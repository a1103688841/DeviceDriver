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


/*******************************************************************
 *                 gobal fuction
 *******************************************************************/

void Button_Attach_ini(void);
void Button_Process(void);
#endif
