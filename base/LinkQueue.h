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
/* externs */
//打印
extern lQStatus lQueuePrintfTraverse (LinkQueue Q);
//内部操作函数
extern lQStatus lQueueInit (LinkQueue *Q);			//初始化
extern lQStatus lQueueDestroy (LinkQueue *Q);		//销毁
extern lQStatus lQueueClear (LinkQueue *Q);			//清空
extern lQStatus lQueueEmpty (LinkQueue Q);			//空？
extern int lQueueLength (LinkQueue Q);				//长度
extern lQStatus lQueueGetHead (LinkQueue Q, lQElemType *e);	//对列头
extern lQStatus lQueueEnQueue (LinkQueue *Q, lQElemType e);	//入队
extern lQStatus lQueueDeQueue (LinkQueue *Q, lQElemType *e);	//出队











#endif  /*  __LINKQUEUE_H__  */

