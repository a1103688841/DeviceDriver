/**************************************************************************************************
* 文件:  device.h
*        
* 说明:  
*        
* 作者:  日南方  2/29/2020
**************************************************************************************************/
#ifndef __DEVICE_H__
#define __DEVICE_H__

/* ------------------------------------------- include ----------------------------------------- */


/* ------------------------------------- define/typedef/enum ----------------------------------- */


/* ------------------------------------------- variable ---------------------------------------- */
#ifdef __DEVICE_C__
	#define DEVICE_EXT
#else
	#define DEVICE_EXT		extern
#endif

#if 0
DEVICE_EXT S32 var
#ifdef __DEVICE_C__
= 0
#endif
;
#endif

/* ------------------------------------------- funtion ----------------------------------------- */


#endif  /*  __DEVICE_H__  */

