/**************************************************************************************************
* 文件:  def.h
*        
* 说明:  
*        
* 作者:  日南方  10/6/2020
**************************************************************************************************/
#ifndef __DEF_H__
#define __DEF_H__

/* ------------------------------------------- include ----------------------------------------- */
//包含其他基本定义
#include <stdio.h>
#include <stdlib.h>
//#include "gd32f30x.h"

/* ------------------------------------- define/typedef/enum ----------------------------------- */
//常用类型
typedef   signed       	char 	int8_t		;
typedef   signed short 	int 	int16_t		;
typedef   signed        int 	int32_t		;
typedef unsigned       	char 	uint8_t		;
typedef unsigned short  int 	uint16_t	;
typedef unsigned        int 	uint32_t	;
typedef unsigned		char	boolean_t	;


//常用开关/真假
#ifndef ON	
#define ON				1
#endif
#ifndef OFF	
#define OFF				0
#endif
#ifndef YES	
#define YES				1
#endif
#ifndef NO	
#define NO				0
#endif
#ifndef TRUE	
#define TRUE			1 
#endif
#ifndef FALSE	
#define FALSE			0
#endif
#ifndef OK	
#define	OK				1
#endif
#ifndef ERROR	
#define ERROR 			0
#endif
#ifndef SUCCESS	
#define SUCCESS			1
#endif
#ifndef FAIL	
#define	FAIL			0
#endif
#ifndef NULL	
#define NULL			((void *)0)
#endif



//比特对应十六进制数
#define BIT0 		(0x0001u)
#define BIT1		(0x0002u)
#define BIT2 		(0x0004u)
#define BIT3		(0x0008u)
#define BIT4 		(0x0010u)
#define BIT5		(0x0020u)
#define BIT6		(0x0040u)
#define BIT7 		(0x0080u)

#define BIT8 		(0x0100u)
#define BIT9		(0x0200u)
#define BIT10 		(0x0400u)
#define BIT11		(0x0800u)
#define BIT12 		(0x1000u)
#define BIT13		(0x2000u)
#define BIT14		(0x4000u)
#define BIT15 		(0x8000u)


/* ------------------------------------------- variable ---------------------------------------- */
#ifdef __DEF_C__
	#define DEF_EXT
#else
	#define DEF_EXT		extern
#endif

#if 0
DEF_EXT S32 var
#ifdef __DEF_C__
= 0
#endif
;
#endif

/* ------------------------------------------- funtion ----------------------------------------- */


#endif  /*  __DEF_H__  */
//	
