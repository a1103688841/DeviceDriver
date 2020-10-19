/**************************************************************************************************
* 文件:  button.h
*        
* 说明:  
*        
* 作者:  rinanfang  3/2/2020
**************************************************************************************************/
#ifndef __BUTTON_H__
#define __BUTTON_H__
//修改
//#include "gd32f30x.h"	//按键读取的函数，可以调整.c文件中的头文件来包含

typedef   signed          char 	int8_t		;
typedef   signed short     int 	int16_t		;
typedef   signed           int 	int32_t		;
typedef unsigned          char 	uint8_t		;
typedef unsigned short     int 	uint16_t	;
typedef unsigned           int 	uint32_t	;
typedef unsigned          char 	boolean_t	;

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifndef NULL
#define NULL 0
#endif
//electrical leve
#ifndef LOW
#define LOW 0
#endif
#ifndef HIGHT
#define HIGHT 0
#endif


#ifdef __BUTTON_C__
	#define BUTTON_EXT
#else
	#define BUTTON_EXT		extern
#endif


//==================================modify define/typedef/enum=================================
///修改
//Get button leve 
#define GetSW0 		!GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)
#define GetSW1 		!GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)
#define GetSW2 		!GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)
#define GetSW3 		!GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_1)
#define GetSW4 		!GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)

//button change level determination  cycle    (n-1)*cycle recall
////按键电平稳定时间 ms*(n-1)=
#define BUTTON_DEBOUNCE_TIME 	  	2

//button  long or double determination  cycle
#define BUTTON_DOUBLE_TIME      	0
#define BUTTON_LONG_TIME 	      	10

//Support contiuos trigger?
#define CONTINUOS_TRIGGER             0

//Support single and double trigger?
#define SINGLE_AND_DOUBLE_TRIGGER     0

//Support long free trigger ?
#define LONG_FREE_TRIGGER             0 

//button long or continuos Trigger again cycle
#define BUTTON_CONTINUOS_CYCLE  	1
#define BUTTON_LONG_CYCLE       	400

////按键名字属性
//button name str max lens
#define BTN_NAME_MAX  10


//==========================================================================================
//按键记录参数修改
//sw record's bin len = btn_idx+1
#define BTNMAX 4

//record sw event
typedef struct
{	//btn_len = btn_idx+1
	uint8_t event[BTNMAX+1];  
	int16_t i;
}SW_RECORD_FIFO_S;

typedef enum
{
	SW0_D = 0,
	SW1_D ,
	SW2_D ,
}SW_RECORD_E;

BUTTON_EXT uint8_t sw_debug_key;
//=========================================================================================

//btn->CallBack_Function[event]     
#define TRIGGER_CB(event)   \
        if(btn->CallBack_Function[event]) \
			btn->CallBack_Function[event]((Button_t*)btn)
//function pointer
typedef void (*Button_CallBack)(void*);

//trigger event array
typedef enum {
  BUTTON_DOWN = 0,
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
//main button function
extern void Button_Attach_ini (void);
extern void Button_Process (void);
//tail interpolation method
extern void Add_Button (Button_t* btn);
extern void Button_Delete (Button_t *btn);
                  
#endif /*  __BUTTON_H__  */
