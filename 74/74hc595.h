/**************************************************************************************************
* 文件:  74hc595.h
*        
* 说明:  
*        
* 作者:  rinanfang  2/29/2020
**************************************************************************************************/
#ifndef __74HC595_H__
#define __74HC595_H__

/* ------------------------------------------- include ----------------------------------------- */
#include "txt.h"
#include "ybase.h"
/* ------------------------------------- define/typedef/enum ----------------------------------- */
#define SI_H					SetBit (PT1, 7);
#define SI_L					ClrBit (PT1, 7);
#define SCK_H					SetBit (PT1, 5);
#define	SCK_L					ClrBit (PT1, 5);
#define RCK_H					SetBit (PT1, 6);
#define	RCK_L					ClrBit (PT1, 6);

/* ------------------------------------------- variable ---------------------------------------- */
#ifdef __74HC595_C__
	#define 74HC595_EXT
#else
	#define 74HC595_EXT		extern
#endif

#if 0
74HC595_EXT S32 var
#ifdef __74HC595_C__
= 0
#endif
;
#endif

/* ------------------------------------------- funtion ----------------------------------------- */


#endif  /*  __74HC595_H__  */

