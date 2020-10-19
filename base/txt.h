/**************************************************************************************************
* 文件:  txt.h
*        
* 说明:  
*        
* 作者:  ysr10/12/2020
**************************************************************************************************/
#ifndef __TXT_H__
#define __TXT_H__

/* ------------------------------------------- include ----------------------------------------- */
#include "def.h"

/* ------------------------------------- define/typedef/enum ----------------------------------- */
typedef enum
{
	MSTA_END,
}MSTA_E;
/* ------------------------------------------- variable ---------------------------------------- */
#ifdef __TXT_C__
	#define TXT_EXT
#else
	#define TXT_EXT		extern
#endif

TXT_EXT uint8_t msta;
TXT_EXT uint8_t time_ms;

//临时变量
TXT_EXT uint8_t print_buff[10];
TXT_EXT uint16_t i;
TXT_EXT uint16_t j;


#if 0
TXT_EXT S32 var
#ifdef __TXT_C__
= 0
#endif
;
#endif

/* ------------------------------------------- funtion ----------------------------------------- */

/* externs */

extern void head_beat_var_ini ();
extern void head_disp_var_ini ();
extern void VarIni ();



#endif  /*  __TXT_H__  */
//	
