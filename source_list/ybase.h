/**************************************************************************************************
* 文件:  ybase.h
*        
* 说明:  
*        
* 作者:  rinanfang 2/29/2020
**************************************************************************************************/
#ifndef __YBASE_H__
#define __YBASE_H__

/* ------------------------------------------- include ----------------------------------------- */


/* ------------------------------------- define/typedef/enum ----------------------------------- */
//data type define
typedef   signed          char 	int8_t;
typedef   signed short     int 	int16_t;
typedef   signed           int 	int32_t;
typedef unsigned          char 	uint8_t;
typedef unsigned short     int 	uint16_t;
typedef unsigned           int 	uint32_t;
typedef _Bool	 				boolean_t;

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef SUCCESS
#define SUCCESS		0
#endif

#ifndef FAIL
#define FAIL		1
#endif

#ifndef NULL
#define NULL        ((void *)0)
#endif





/* ------------------------------------------- variable ---------------------------------------- */
#ifdef __YBASE_C__
	#define YBASE_EXT
#else
	#define YBASE_EXT		extern
#endif

#if 0
YBASE_EXT S32 var
#ifdef __YBASE_C__
= 0
#endif
;
#endif

/* ------------------------------------------- funtion ----------------------------------------- */


#endif  /*  __YBASE_H__  */

