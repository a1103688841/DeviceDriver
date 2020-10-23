/**************************************************************************************************
* 文件:  LinkQueue.h
*        
* 说明:  
*        
* 作者:  日南方  10/23/2020
**************************************************************************************************/
#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

/* ------------------------------------------- include ----------------------------------------- */
#include "def.h"



/* ------------------------------------- define/typedef/enum ----------------------------------- */

typedef int lQStatus; 

typedef int lQElemType; /* QElemType类型根据实际情况而定，这里假设为int */

typedef struct QNode	/* 结点结构 */
{
   lQElemType data;
   struct QNode *next;
}QNode,*QueuePtr;

typedef struct			/* 队列的链表结构 */
{
   QueuePtr front,rear; /* 队头、队尾指针 */
}LinkQueue;

/* ------------------------------------------- variable ---------------------------------------- */
#ifdef __LINKQUEUE_C__
	#define LINKQUEUE_EXT
#else
	#define LINKQUEUE_EXT		extern
#endif

LINKQUEUE_EXT lQStatus		linkQueue_status;
LINKQUEUE_EXT lQElemType	linkQueue_elem;
LINKQUEUE_EXT LinkQueue		linkQueue_var;

#if 0
LINKQUEUE_EXT S32 var
#ifdef __LINKQUEUE_C__
= 0
#endif
;
#endif

/* ------------------------------------------- funtion ----------------------------------------- */


#endif  /*  __LINKQUEUE_H__  */

