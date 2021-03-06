/**************************************************************************************************
* 文件:  button.h
*        
* 说明:  
*        
* 作者:  rinanfang  3/2/2020
**************************************************************************************************/
#ifndef __BUTTON_H__
#define __BUTTON_H__


#ifdef __BUTTON_C__
	#define BUTTON_EXT
#else
	#define BUTTON_EXT		extern
#endif

/* ------------------------------------- define/typedef/enum ----------------------------------- */
//==================================modify define/typedef/enum=================================

//Get button leve 
#define GetSW0 		!DrvGPIO_GetBit(E_PT2,3)


//button name str max lens
#define BTN_NAME_MAX  20

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

//sw record's bin len = btn_idx+1
#define btn_idx 4
//in sw record fuction to set key for trigger secret
#define key0 "SW0_Down"
#define key1 "SW3_Down"
//==========================================================================================



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

//record sw event
typedef struct
{	//btn_len = btn_idx+1
	char event[btn_idx+1][BTN_NAME_MAX];  
	int i;
}SQ_btn_t;


/* ------------------------------------------- funtion ----------------------------------------- */
//main button function
extern void Button_Attach_ini (void);
extern void Button_Process (void);
//tail interpolation method
extern void Add_Button (Button_t* btn);
extern void Button_Delete (Button_t *btn);
                  
#endif /*  __BUTTON_H__  */
