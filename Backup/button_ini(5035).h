#ifndef __BUTTON_CALL__
#define __BUTTON_CALL__
#include "txt.h"
#include "Button.h"
#include "DrvGPIO.h"
#ifdef __button_var__
	#define button_global
#else
	#define button_global	extern
#endif
#define BUTTON_INI_FALSE	0
#define BUTTON_INI_TRUE		1
#define GetSW0 		!DrvGPIO_GetBit(E_PT2,3)
#define GetSW1 		!DrvGPIO_GetBit(E_PT2,1)
#define GetSW2 		!DrvGPIO_GetBit(E_PT2,2)
#define GetSW3 		!DrvGPIO_GetBit(E_PT2,0)
/*******************************************************************
 *                        new button
 *******************************************************************/
button_global Button_t 	SW0;
button_global Button_t 	SW1;
button_global Button_t	SW2;
button_global Button_t 	SW1_2;
button_global Button_t	SW3;
/*******************************************************************
 *                 gobal fuction
 *******************************************************************/

void Button_Attach_ini(void);
void Button_Process(void);
#endif
