/**************************************************************************************************
* ����:                              button
*        
* �ļ�:  button.c
*        
* ˵��:  
*        
* ����:  ���Ϸ�  3/2/2020
**************************************************************************************************/

#define __BUTTON_C__

/* ------------------------------------------- include ----------------------------------------- */
#include "txt.h"
#include "ybase.h"
#include "button.h"
#include "string.h"

/* ------------------------------------- define/typedef/enum ----------------------------------- */
//	

/* ------------------------------------------- variable ---------------------------------------- */


/* -------------------------------------------static funtion ----------------------------------------- */
#ifdef STATIC_FUNCTION
#endif	/* STATIC_FUNCTION */

 //Name str copy
static char *StrnCopy(char *dst, const char *src, unsigned int n);
//tail interpolation method
static void Add_Button(Button_t* btn);


/* -------------------------------------------global funtion ----------------------------------------- */
#ifdef GLOBAL_FUNCTION
#endif	/* GLOBAL_FUNCTION */

/**************************************************************************************************
* function	:                                   Button_Create
* brief	:  
* param	:  
* const char *name		 :
* Button_t *btn		 :
* uint8_t(*read_btn_level)(void)		 :
* uint8_t btn_trigger_level		 :
* global variable	: 
* return			:  
* author			:  rinanfang  3/2/2020
**************************************************************************************************/
boolean_t Button_Create(const char *name,
                  Button_t *btn, 
                  uint8_t(*read_btn_level)(void),
                  uint8_t btn_trigger_level)
{
  if( btn == NULL)
  {
	  return BUTTON_FALSE;
  }
  //"string.h"
  memset(btn, 0, sizeof(struct button));  //
  StrnCopy(btn->Name, name, BTN_NAME_MAX);
  
  //set button param to no trigger status
  btn->Button_State = NONE_TRIGGER;
  btn->Button_Last_State = NONE_TRIGGER;
  btn->Button_Trigger_Event = NONE_TRIGGER;
  
  btn->Read_Button_Level = read_btn_level;
  btn->Button_Trigger_Level = btn_trigger_level;
  btn->Button_Last_Level = btn->Read_Button_Level();
  btn->Debounce_Time = 0;

  //add to line tabe
  Add_Button(btn);          //add button line
  
  return BUTTON_TRUE;
}

/************************************************************
  * @brief   Button_Attach
  * @param   btn 			: 
  * @param   btn_event 		: 
  * @param   btn_callback 	: 
  * @return  TRUE FALSE
  ***********************************************************/
boolean_t Button_Attach(Button_t *btn,Button_Event btn_event,Button_CallBack btn_callback)
{
  uint8_t i=0;
  if( btn == NULL)
  {
	  return BUTTON_FALSE;
  }
  
  if(BUTTON_ALL_RIGGER == btn_event)
  {
    for( i = 0 ; i < number_of_event-1 ; i++)
      btn->CallBack_Function[i] = btn_callback; //
  }
  else
  {
    btn->CallBack_Function[btn_event] = btn_callback; //
  }
  return BUTTON_TRUE;
}

/************************************************************
  * @brief   button delete
	* @param   NULL
  * @return  NULL
  * @author  jiejie
  * @github  https://github.com/jiejieTop
  * @date    2018-xx-xx
  * @version v1.0
  * @note    NULL
  ***********************************************************/
void Button_Delete(Button_t *btn)
{
  struct button** curr;
  for(curr = &Head_Button; *curr;) 
  {
    struct button* entry = *curr;
    if (entry == btn) 
    {
      *curr = entry->Next;
    } 
    else
    {
      curr = &entry->Next;
    }
  }
}

/************************************************************
  * @brief   鑾峰彇鎸夐敭瑙﹀彂鐨勪簨浠�
	* @param   NULL
  * @return  NULL
  * @author  jiejie
  * @github  https://github.com/jiejieTop
  * @date    2018-xx-xx
  * @version v1.0
  ***********************************************************/
void Get_Button_EventInfo(Button_t *btn)
{
  uint8_t i = 0;
  for( i = 0; i < number_of_event-1 ; i++)
  {
    if(btn->CallBack_Function[i] != 0)
    {
      //PRINT_INFO("Button_Event:%d",i);
    }      
  } 
}

uint8_t Get_Button_Event(Button_t *btn)
{
  return (uint8_t)(btn->Button_Trigger_Event);
}

/************************************************************
  * @brief   鑾峰彇鎸夐敭瑙﹀彂鐨勪簨浠�
	* @param   NULL
  * @return  NULL
  * @author  jiejie
  * @github  https://github.com/jiejieTop
  * @date    2018-xx-xx
  * @version v1.0
  ***********************************************************/
uint8_t Get_Button_State(Button_t *btn)
{
  return (uint8_t)(btn->Button_State);
}

/************************************************************
* @brief 	button cycle proces  fuction
* @param   btn:
* @return  NULL
* @version v1.0
* @note    cycle call time 20~50ms
***********************************************************/
void Button_Cycle_Process(Button_t *btn)
{
  uint8_t current_level = (uint8_t)btn->Read_Button_Level();//获取当前按键电平
  
  if((current_level != btn->Button_Last_Level)&&(++(btn->Debounce_Time) >= BUTTON_DEBOUNCE_TIME)) //按键电平发生变化，消�?
  {
      btn->Button_Last_Level = current_level; //更新当前按键电平
      btn->Debounce_Time = 0;                 //确定了是按下

      //如果按键是没被按下的，改变按键状态为按下(首次按下/双击按下)
      if((btn->Button_State == NONE_TRIGGER)||(btn->Button_State == BUTTON_DOUBLE))
      {
        btn->Button_State = BUTTON_DOWM;
      }
      //释放按键
      else if(btn->Button_State == BUTTON_DOWM)
      {
        btn->Button_State = BUTTON_UP;
        //PRINT_DEBUG("释放按键");
      }
  }
  
  switch(btn->Button_State)
  {
    case BUTTON_DOWM :            // 按下状�??
    {
      if(btn->Button_Last_Level == btn->Button_Trigger_Level) //按键按下
      {
        #if CONTINUOS_TRIGGER     //支持连续触发

        if(++(btn->Button_Cycle) >= BUTTON_CONTINUOS_CYCLE)
        {
          btn->Button_Cycle = 0;
          btn->Button_Trigger_Event = BUTTON_CONTINUOS; 
          TRIGGER_CB(BUTTON_CONTINUOS);    //连按
          //PRINT_DEBUG("连按");
        }
        
        #else
        if(btn->Button_Trigger_Event != BUTTON_LONG)
          btn->Button_Trigger_Event = BUTTON_DOWM;
      
        if(++(btn->Long_Time) >= BUTTON_LONG_TIME)  //释放按键前更新触发事件为长按
        {
          #if LONG_FREE_TRIGGER
          
          btn->Button_Trigger_Event = BUTTON_LONG; 
          
          #else
          
          if(++(btn->Button_Cycle) >= BUTTON_LONG_CYCLE)    //连续触发长按的周�?
          {
            btn->Button_Cycle = 0;
            btn->Button_Trigger_Event = BUTTON_LONG; 
            TRIGGER_CB(BUTTON_LONG);    //长按
          }
          #endif
          
          if(btn->Long_Time == 0xFF)  //更新时间溢出
          {
            btn->Long_Time = BUTTON_LONG_TIME;
          }
          //PRINT_DEBUG("长按");
        }
          
        #endif
      }

      break;
    } 
    
    case BUTTON_UP :        // 弹起状�??
    {
      if(btn->Button_Trigger_Event == BUTTON_DOWM)  //触发单击
      {
        if((btn->Timer_Count <= BUTTON_DOUBLE_TIME)&&(btn->Button_Last_State == BUTTON_DOUBLE)) // 双击
        {
          btn->Button_Trigger_Event = BUTTON_DOUBLE;
          TRIGGER_CB(BUTTON_DOUBLE);    
          //PRINT_DEBUG("双击");
          btn->Button_State = NONE_TRIGGER;
          btn->Button_Last_State = NONE_TRIGGER;
        }
        else
        {
            btn->Timer_Count=0;
            btn->Long_Time = 0;   //�?测长按失败，�?0
          
          #if (SINGLE_AND_DOUBLE_TRIGGER == 0)
            TRIGGER_CB(BUTTON_DOWM);    //单击
          #endif
            btn->Button_State = BUTTON_DOUBLE;
            btn->Button_Last_State = BUTTON_DOUBLE;
          
        }
      }
      
      else if(btn->Button_Trigger_Event == BUTTON_LONG)
      {
        #if LONG_FREE_TRIGGER
          TRIGGER_CB(BUTTON_LONG);    //长按
        #else
          TRIGGER_CB(BUTTON_LONG_FREE);    //长按释放
        #endif
        btn->Long_Time = 0;
        btn->Button_State = NONE_TRIGGER;
        btn->Button_Last_State = BUTTON_LONG;
		btn->Button_Trigger_Event = BUTTON_DOWM;
      } 
      
      #if CONTINUOS_TRIGGER
        else if(btn->Button_Trigger_Event == BUTTON_CONTINUOS)  //连按
        {
          btn->Long_Time = 0;
          TRIGGER_CB(BUTTON_CONTINUOS_FREE);    //连发释放
          btn->Button_State = NONE_TRIGGER;
          btn->Button_Last_State = BUTTON_CONTINUOS;
        } 
      #endif
      
      break;
    }
    
    case BUTTON_DOUBLE :		//中间间隔的超时判�?
    {
      btn->Timer_Count++;     //时间记录
      if(btn->Timer_Count>=BUTTON_DOUBLE_TIME)
      {
        btn->Button_State = NONE_TRIGGER;
        btn->Button_Last_State = NONE_TRIGGER;
      }
      #if SINGLE_AND_DOUBLE_TRIGGER
      
        if((btn->Timer_Count>=BUTTON_DOUBLE_TIME)&&(btn->Button_Last_State != BUTTON_DOWM))
        {
          btn->Timer_Count=0;
          TRIGGER_CB(BUTTON_DOWM);    //单击
          btn->Button_State = NONE_TRIGGER;
          btn->Button_Last_State = BUTTON_DOWM;
        }
        
      #endif

      break;
    }

    default :
      break;
  }
  
}

/************************************************************
 * @brief   Button_Process
 * @param   NULL
 * @return  NULL
  ***********************************************************/
void Button_Process(void)
{
  struct button* pass_btn;
  for(pass_btn = Head_Button; pass_btn != NULL; pass_btn = pass_btn->Next)
  {
      Button_Cycle_Process(pass_btn);
  }
}

/************************************************************
  * @brief   閬嶅巻鎸夐敭
	* @param   NULL
  * @return  NULL
  * @author  jiejie
  * @github  https://github.com/jiejieTop
  * @date    2018-xx-xx
  * @version v1.0
  * @note    NULL
  ***********************************************************/
struct button* Search_Button(char Name[])
{
  struct button* pass_btn;
  for(pass_btn = Head_Button; pass_btn != NULL; pass_btn = pass_btn->Next)
  {
    //PRINT_INFO("button node have %s",pass_btn->Name);
	  if(strcmp(Name, pass_btn->Name) == 0)
	  {
		  return pass_btn;
	  }
  }
  return NULL;
}

/************************************************************
  * @brief   澶勭悊鎵�湁鎸夐敭鍥炶皟鍑芥�?
	* @param   NULL
  * @return  NULL
  * @author  jiejie
  * @github  https://github.com/jiejieTop
  * @date    2018-xx-xx
  * @version v1.0
  * @note    鏆備笉�?�炵�?
  ***********************************************************/
void Button_Process_CallBack(void *btn)
{
  uint8_t btn_event = Get_Button_Event(btn);

  switch(btn_event)
  {
    case BUTTON_DOWM:
    {
      //PRINT_INFO("button down");
      break;
    }
    
    case BUTTON_UP:
    {
     // PRINT_INFO("button up");
      break;
    }
    
    case BUTTON_DOUBLE:
    {
      //PRINT_INFO("button double");
      break;
    }
    
    case BUTTON_LONG:
    {
      //PRINT_INFO("button long");
      break;
    }
    
    case BUTTON_LONG_FREE:
    {
     // PRINT_INFO("button long free");
      break;
    }
    
    case BUTTON_CONTINUOS:
    {
     // PRINT_INFO("button continuos");
      break;
    }
    
    case BUTTON_CONTINUOS_FREE:
    {
      //PRINT_INFO("button continuos free");
      break;
    }
      
  } 
}


/**************************** local fuction********************/

/************************************************************
  * @brief   constrat str
	* @param   NULL
  * @return  NULL
  ***********************************************************/
static char *StrnCopy(char *dst, const char *src, uint32_t n)
{
  if (n != 0)
  {
    char *d = dst;
    const char *s = src;
    do
    {
        if ((*d++ = *s++) == 0)
        {
            while (--n != 0)
                *d++ = 0;
            break;
        }
    } while (--n != 0);
  }
  return (dst);
}


/************************************************************
  * @brief   add button
	* @param   NULL
  * @return  NULL
  * @author  jiejie
  * @github  https://github.com/jiejieTop
  * @date    2018-xx-xx
  * @version v1.0
  * @note    NULL
  ***********************************************************/
static void Add_Button(Button_t* btn)
{
  struct button *pass_btn = Head_Button;
  
  while(pass_btn)
  {
    pass_btn = pass_btn->Next;
  }
  
  btn->Next = Head_Button;
  Head_Button = btn;
}




