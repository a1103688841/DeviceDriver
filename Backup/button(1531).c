/**************************************************************************************************
* fuction	:                              button     
* file		:  button.c     
* brief		:     
* author	: rinanfang  3/2/2020
**************************************************************************************************/

#define __BUTTON_C__

/* ------------------------------------------- include ----------------------------------------- */
//修改的头文件
#include "txt.h"	//sw callback need global variable
#include "def.h"	//data define || NULL FALSE TRUE define
#include "gd32f30x.h"//Get gipo level
//default
#include "button.h" //data sturct
#include "string.h" //memset() strcmp() fuction
#include "stdio.h"
/* ------------------------------------- define/typedef/enum ----------------------------------- */


/* ------------------------------------------- variable ---------------------------------------- */
//Button's head
static struct button* Head_Button = NULL;

//new many button 
////需要修改的函数变量
static Button_t 	SW0;
static Button_t 	SW1;
static Button_t		SW2;
static Button_t 	SW3;
static Button_t		SW4;
//密码

/* -------------------------------------------static funtion ----------------------------------------- */
//Name str copy
static char *StrnCopy(char *dst, const char *src, unsigned int n);
static boolean_t Button_Attach (Button_t *btn, Button_Event btn_event, Button_CallBack btn_callback);
static boolean_t Button_Create (const char *name, Button_t *btn, uint8_t (*read_btn_level) (void), uint8_t btn_trigger_level);
//tail interpolation method
extern void Add_Button (Button_t* btn);
extern void Button_Delete (Button_t *btn);

//button state determine
static void Button_Cycle_Process (Button_t *btn);


//read sw level || sw event callback
////需要修改的函数声明
static boolean_t 	Read_SW0_Level (void);
static boolean_t 	Read_SW1_Level (void);
static boolean_t 	Read_SW2_Level (void);
static boolean_t 	Read_SW3_Level (void);
static boolean_t 	Read_SW4_Level (void);
static void 		SW0_Down_CallBack (void *btn);
static void 		SW1_2_Long_CallBack (void *btn);
static void 		SW1_Down_CallBack (void *btn);
static void 		SW2_Down_CallBack (void *btn);
static void 		SW3_Down_CallBack (void *btn);
static void 		SW4_Down_CallBack (void *btn);
////record function
static void 		btnRecord(char *event_name);


/* -------------------------------------------global funtion ----------------------------------------- */
//main button function
extern void Button_Attach_ini (void);
extern void Button_Process (void);



/* -------------------------------------------modify funtion ----------------------------------------- */
//需要修改的函数
/* --------------------ini button node and attach button event callbak to button----------------------------------------- */
//按键链接初始化
void Button_Attach_ini(void)
{

  	Button_GPIO_ini();
 	Button_Create("SW0",&SW0,Read_SW0_Level,HIGHT);
	Button_Attach(&SW0,BUTTON_DOWN,SW0_Down_CallBack);                       //call fuction attach
	
  	Button_Create("SW1",&SW1,Read_SW1_Level,HIGHT);
	Button_Attach(&SW1,BUTTON_DOWN,SW1_Down_CallBack);                       //call fuction attach
	
  	Button_Create("SW2",&SW2,Read_SW2_Level,LOW);
	Button_Attach(&SW2,BUTTON_DOWN,SW2_Down_CallBack);                       //call fuction attach

 	Button_Create("SW3",&SW3,Read_SW3_Level,HIGHT);
	Button_Attach(&SW3,BUTTON_DOWN,SW3_Down_CallBack);                       //call fuction attach
	
  	Button_Create("SW4",&SW4,Read_SW4_Level,HIGHT);
	Button_Attach(&SW4,BUTTON_DOWN,SW4_Down_CallBack);                       //call fuction attach

}

//修改按键引脚初始化
void Button_GPIO_ini()
{

 	GPIO_InitTypeDef GPIO_InitStructure;
 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE,ENABLE);//使能PORTA,PORTE时钟

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_4|GPIO_Pin_3|GPIO_Pin_1|GPIO_Pin_2;//KEY0-KEY1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化GPIOE4,3


	//初始化 WK_UP-->GPIOA.0	  下拉输入
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0设置成输入，默认下拉	  
	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.0
	
}
//修改函数状态转移初始化
void mstaVarIni()
{

}

/* -------------------------------------------sw level ----------------------------------------- */
//修改电平
/* ----------------------------------------------------------------------------------------------------- */
static boolean_t Read_SW0_Level(void)
{
	return (GetSW0)?TRUE:FALSE;
}
static boolean_t Read_SW1_Level(void)
{
	return (GetSW1)?TRUE:FALSE;
}
static boolean_t Read_SW2_Level(void)
{
	return (GetSW2)?TRUE:FALSE;
}
static boolean_t Read_SW3_Level(void)
{
	return (GetSW3)?TRUE:FALSE;
}
static boolean_t Read_SW4_Level(void)
{
	return (GetSW4)?TRUE:FALSE;
}
/* -------------------------------------------sw down callback ----------------------------------------- */
//修改按键逻辑
/* ----------------------------------------------------------------------------------------------------- */
static void SW0_Down_CallBack(void *btn)
{
	// 0-3
	mstaVarIni();
//	btnRecord(SW0_Down_e);

}
static void SW1_Down_CallBack(void *btn)
{
	mstaVarIni();
//	btnRecord(SW1_Down_e);

}
static void SW2_Down_CallBack(void *btn)
{
	mstaVarIni();
	//btnRecord(SW2_Down_e);

}
static void SW3_Down_CallBack(void *btn)
{
	mstaVarIni();
//	btnRecord(SW1_Down_e);

}
static void SW4_Down_CallBack(void *btn)
{
	mstaVarIni();
//	btnRecord(SW1_Down_e);

}


/* -------------------------------------------sw long callback ----------------------------------------- */
static void SW1_2_Long_CallBack(void *btn)
{

}

/* -----------------------------------sw record and trigger event ----------------------------------------- */

/*
static void btnRecord(char event_name)
{
	boolean_t f1,f2,f3;
 	int8_t i;
	
	//record
	StrnCopy(button_list.event[button_list.i],event_name, BTN_NAME_MAX);
	button_list.i++;
	if(button_list.i>btn_idx)
	{
		button_list.i=0;
	}

	//compare key
	i=button_list.i;
	if(--i<0)
	{
		i=btn_idx;
	} 
	f1=!(strcmp(button_list.event[i], key0));
	if(--i<0)
	{
		i=btn_idx;
	} 	
	f2=!(strcmp(button_list.event[i], key1));
	if(--i<0)
	{
		i=btn_idx;
	} 
	f3=!(strcmp(button_list.event[i], key1));

	//trigger event	
	 if(f1==TRUE&&f2==TRUE&&f3==TRUE)
	{
		//sta.main=calibration_mode;
	}
 }
 */

/* ------------------------------------------- funtion ----------------------------------------- */
//内部函数
/* ------------------------------------------- funtion ----------------------------------------- */
/************************************************************
  * @brief   按键周期处理函数
  * @param   btn:处理的按键
  * @return  NULL
  * @author  jiejie
  * @github  https://github.com/jiejieTop
  * @date    2018-xx-xx
  * @version v1.0
  * @note    必须以一定周期调用此函数，建议周期为20~50ms
  ***********************************************************/
void Button_Cycle_Process(Button_t *btn)
{
  uint8_t current_level = (uint8_t)btn->Read_Button_Level();
  
  if((current_level != btn->Button_Last_Level)&&(++(btn->Debounce_Time) >= BUTTON_DEBOUNCE_TIME)) 
  {
      btn->Button_Last_Level = current_level; 
      btn->Debounce_Time = 0;                 

      if((btn->Button_State == NONE_TRIGGER)||(btn->Button_State == BUTTON_DOUBLE))
      {
        btn->Button_State = BUTTON_DOWN;
      }

      else if(btn->Button_State == BUTTON_DOWN)
      {
        btn->Button_State = BUTTON_UP;
      }
  }
  
  switch(btn->Button_State)
  {
    case BUTTON_DOWN :           
    {
      if(btn->Button_Last_Level == btn->Button_Trigger_Level) 
      {
        #if CONTINUOS_TRIGGER     

        if(++(btn->Button_Cycle) >= BUTTON_CONTINUOS_CYCLE)
        {
          btn->Button_Cycle = 0;
          btn->Button_Trigger_Event = BUTTON_CONTINUOS; 
          TRIGGER_CB(BUTTON_CONTINUOS);  
        }
        
        #else
        if(btn->Button_Trigger_Event != BUTTON_LONG)
          btn->Button_Trigger_Event = BUTTON_DOWN;
      
        if(++(btn->Long_Time) >= BUTTON_LONG_TIME)  
        {
          #if LONG_FREE_TRIGGER
          
          btn->Button_Trigger_Event = BUTTON_LONG; 
          
          #else
          
          if(++(btn->Button_Cycle) >= BUTTON_LONG_CYCLE)    
          {
            btn->Button_Cycle = 0;
            btn->Button_Trigger_Event = BUTTON_LONG; 
            TRIGGER_CB(BUTTON_LONG);    
          }
          #endif
          
          if(btn->Long_Time == 0xFF)  
          {
            btn->Long_Time = BUTTON_LONG_TIME;
          }
        }
          
        #endif
      }

      break;
    } 
    
    case BUTTON_UP :        
    {
      if(btn->Button_Trigger_Event == BUTTON_DOWN)  
      {
        if((btn->Timer_Count <= BUTTON_DOUBLE_TIME)&&(btn->Button_Last_State == BUTTON_DOUBLE)) 
        {
          btn->Button_Trigger_Event = BUTTON_DOUBLE;
          TRIGGER_CB(BUTTON_DOUBLE);    
          btn->Button_State = NONE_TRIGGER;
          btn->Button_Last_State = NONE_TRIGGER;
        }
        else
        {
            btn->Timer_Count=0;
            btn->Long_Time = 0; 
          
          #if (SINGLE_AND_DOUBLE_TRIGGER == 0)
            TRIGGER_CB(BUTTON_DOWN);  
          #endif
            btn->Button_State = BUTTON_DOUBLE;
            btn->Button_Last_State = BUTTON_DOUBLE;
          
        }
      }
      
      else if(btn->Button_Trigger_Event == BUTTON_LONG)
      {
        #if LONG_FREE_TRIGGER
          TRIGGER_CB(BUTTON_LONG);    
        #else
          TRIGGER_CB(BUTTON_LONG_FREE);    
        #endif
        btn->Long_Time = 0;
        btn->Button_State = NONE_TRIGGER;
        btn->Button_Last_State = BUTTON_LONG;
		btn->Button_Trigger_Event = BUTTON_DOWN;
      } 
      
      #if CONTINUOS_TRIGGER
        else if(btn->Button_Trigger_Event == BUTTON_CONTINUOS)  
        {
          btn->Long_Time = 0;
          TRIGGER_CB(BUTTON_CONTINUOS_FREE);  
          btn->Button_State = NONE_TRIGGER;
          btn->Button_Last_State = BUTTON_CONTINUOS;
        } 
      #endif
      
      break;
    }
    
    case BUTTON_DOUBLE :		
      btn->Timer_Count++;     
      if(btn->Timer_Count>=BUTTON_DOUBLE_TIME)
      {
        btn->Button_State = NONE_TRIGGER;
        btn->Button_Last_State = NONE_TRIGGER;
      }
      #if SINGLE_AND_DOUBLE_TRIGGER
      
        if((btn->Timer_Count>=BUTTON_DOUBLE_TIME)&&(btn->Button_Last_State != BUTTON_DOWN))
        {
          btn->Timer_Count=0;
          TRIGGER_CB(BUTTON_DOWN);    
          btn->Button_State = NONE_TRIGGER;
          btn->Button_Last_State = BUTTON_DOWN;
        }
      #endif
      break;
    default:
      break;
  }
  
}

/**************************************************************************************************
* function	:                                   Button_Process
* brief	:  			   scan each button and each button's each button event
* param	:  			   none
* return			:  none
* author			:  rinanfang  3/2/2020
**************************************************************************************************/
void Button_Process(void)
{
  struct button* pass_btn;
  for(pass_btn = Head_Button; pass_btn != NULL; pass_btn = pass_btn->Next)
  {
      Button_Cycle_Process(pass_btn);
  }
}

/**************************************************************************************************
* function	:                                   Add_Button
* brief	:   add button node to button linear list
* param	:  button node
* return			:  none
* author			:  rinanfang  3/2/2020
**************************************************************************************************/
void Add_Button(Button_t* btn)
{
  struct button *pass_btn = Head_Button;
  
  while(pass_btn)
  {
    pass_btn = pass_btn->Next;
  }
  
  btn->Next = Head_Button;
  Head_Button = btn;
}

/**************************************************************************************************
* function	:                                   Button_Delete
* brief	:  delete button node from button linear list
* param	:  button node
* return			:  none
* author			:  rinanfang  3/2/2020
**************************************************************************************************/
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
/**************************************************************************************************
* function	:                                   Button_Create
* brief	:  create a new button nod and add it to button linear list
* param	:  button name||button node||button level||button trigger level		
* return			:  TRUE FALSE
* author			:  rinanfang  3/2/2020
**************************************************************************************************/
static boolean_t Button_Create(const char *name,
                  Button_t *btn, 
                  uint8_t(*read_btn_level)(void),
                  uint8_t btn_trigger_level)
{
  if( btn == NULL)
  {
	  return FALSE;
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
  
  return TRUE;
}

/**************************************************************************************************
* function	:                                   Button_Attach
* brief	:		attach button event to  corresponding button node
* param	:  		button node||button event's array idex||button event's callback
* return			:  TRUE FALSE
* author			:  rinanfang  3/2/2020
**************************************************************************************************/
static boolean_t Button_Attach(Button_t *btn,Button_Event btn_event,Button_CallBack btn_callback)
{
  uint8_t i=0;
  if( btn == NULL)
  {
	  return FALSE;
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
  return TRUE;
}

/**************************************************************************************************
* function	:                                   StrnCopy
* brief	:  
* param	:  dst str || src str || str line
* return			:  dst str 
* author			:  rinanfang  3/2/2020
**************************************************************************************************/
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



