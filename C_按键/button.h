/**************************************************************************************************
* 文件:  button.h
*        
* 说明:  
*        
* 作者:  日南方  3/2/2020
**************************************************************************************************/
#ifndef __BUTTON_H__
#define __BUTTON_H__

#ifdef __BUTTON_C__
	#define BUTTON_EXT
#else
	#define BUTTON_EXT		extern
#endif
/* ------------------------------------------- variable ---------------------------------------- */

//Button's head
static struct button* Head_Button = NULL;

//=============need to change Variables==========================
//new many button 
button_global Button_t 	SW0;
button_global Button_t 	SW1;
button_global Button_t	SW2;
button_global Button_t 	SW1_2;
button_global Button_t	SW3;

//Get button leve 
#define GetSW0 		!DrvGPIO_GetBit(E_PT2,3)
#define GetSW1 		!DrvGPIO_GetBit(E_PT2,1)
#define GetSW2 		!DrvGPIO_GetBit(E_PT2,2)
#define GetSW3 		!DrvGPIO_GetBit(E_PT2,0)

//button name str max lens
#define BTN_NAME_MAX  15

//Support contiuos trigger?
#define CONTINUOS_TRIGGER             0

//Support single and double trigger?
#define SINGLE_AND_DOUBLE_TRIGGER     0

//Support long free trigger ?
#define LONG_FREE_TRIGGER             0 

//button change level determination  cycle    (n-1)*cycle recall
//?ms*(n-1)=
#define BUTTON_DEBOUNCE_TIME 	  	24
//button  long or double determination  cycle
#define BUTTON_DOUBLE_TIME      	15
#define BUTTON_LONG_TIME 	      	15

//button long or continuos Trigger again cycle
#define BUTTON_CONTINUOS_CYCLE  	1
#define BUTTON_LONG_CYCLE       	400
//===========================================================



//btn->CallBack_Function[event]     
#define TRIGGER_CB(event)   \
        if(btn->CallBack_Function[event]) \
			btn->CallBack_Function[event]((Button_t*)btn)
//function pointer
typedef void (*Button_CallBack)(void*);

//trigger event array
typedef enum {
  BUTTON_DOWM = 0,
  BUTTON_UP,
  BUTTON_DOUBLE,
  BUTTON_LONG,
  BUTTON_LONG_FREE,
  BUTTON_CONTINUOS,
  BUTTON_CONTINUOS_FREE,
  BUTTON_ALL_RIGGER,
  number_of_event,
  NONE_TRIGGER
}Button_Event;

//electrical leve
typedef enum
{
	LOW=0,
	HIGHT=1
}Trigger_Level_t;


//button struct
typedef struct button
{
  	uint8_t (*Read_Button_Level)(void); 
  
  	char Name[BTN_NAME_MAX];

	//button main status
  	uint8_t Button_State              :   4;	 	
  	uint8_t Button_Last_State         :   4;	  	
  	uint8_t Button_Trigger_Level      :   2;    	
  	uint8_t Button_Last_Level         :   2;    	

	//callback function
  	uint8_t Button_Trigger_Event;     				
  	Button_CallBack CallBack_Function[number_of_event];

	//each button status counter  
  	uint16_t Button_Cycle;
  	uint16_t Timer_Count;
  	uint16_t Debounce_Time;							
	uint16_t Long_Time;		  					

	//nexst node
  	struct button *Next;
}Button_t;

/* ------------------------------------------- funtion ----------------------------------------- */

//create one button
unsigned char 	Button_Create(const char *name,
                  Button_t *btn, 
                  unsigned char(*read_btn_level)(void),
                  unsigned char btn_trigger_level);
//delete one button
void 			Button_Delete(Button_t *btn);   

//attch button event's callback fuction to button
boolean_t 		Button_Attach(Button_t *btn,
					Button_Event btn_event,
					Button_CallBack btn_callback);

//ergodic one button's callback process          
void 			Button_Cycle_Process(Button_t *btn);   
//ergodic all button process
void 			Button_Process(void);
                  

  
struct button* 	Search_Button(char Name[]);
                  
void 			Get_Button_EventInfo(Button_t *btn);
unsigned char 	Get_Button_Event(Button_t *btn);
unsigned char 	Get_Button_State(Button_t *btn);
void 			Button_Process_CallBack(void *btn);
                  
#endif /*  __BUTTON_H__  */