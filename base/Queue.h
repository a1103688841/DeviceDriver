/**************************************************************************************************
* 文件:  Queue.h
*        
* 说明:  
*        
* 作者:  日南方  10/22/2020
**************************************************************************************************/
#ifndef __QUEUE_H__

#define __QUEUE_H__

/* ------------------------------------------- include ----------------------------------------- */
#include "def.h"

/* ------------------------------------- define/typedef/enum ----------------------------------- */

#define SQQUEUEMAXSIZE 20 /* 存储空间初始分配量 */

typedef int sqQStatus; 
typedef int sqQElemType; /* sqQElemType类型根据实际情况而定，这里假设为int */

/* 循环队列的顺序存储结构 */
//头指针和尾指针相等表示队列空
//队尾是入队元素的指针，对头是出队元素的指针
//SQQUEUEMAXSIZE=20,及是分配了20个空间，从内部索引是0-19,索引直接%SQQUEUEMAXSIZE，就是0-19，无需转换
//求队列长度是(Q.rear-Q.front+SQQUEUEMAXSIZE)%SQQUEUEMAXSIZE
//情况1）rear在front大，值的含义是距离，正常值是正的，加上一圈，不影响
//情况2）front在rear大，值是负的，值的大小等于他们之间的距离，加上一圈就是将一圈减去他们的距离，剩余另一半的正距离
typedef struct
{
	sqQElemType data[SQQUEUEMAXSIZE];
	int32_t front;    	/* 头指针 */
	int32_t rear;		/* 尾指针，若队列不空，指向队列尾元素的下一个位置 */
}SqQueue;


/* ------------------------------------------- variable ---------------------------------------- */
#ifdef __QUEUE_C__
	#define QUEUE_EXT
#else
	#define QUEUE_EXT		extern
#endif

QUEUE_EXT sqQStatus 	sqq_status;
QUEUE_EXT sqQElemType 	sqq_elem;
QUEUE_EXT SqQueue		sqq_var_test;





#if 0
QUEUE_EXT S32 var
#ifdef __QUEUE_C__
= 0
#endif
;
#endif

/* ------------------------------------------- funtion ----------------------------------------- */

/* externs */
//打印函数
extern sqQStatus sqQueuePrintfTraverse (SqQueue Q);
//内部操作函数
extern void sqQueueInit (SqQueue *Q);			//初始化
extern void sqQueueClear (SqQueue *Q);			//清空
extern sqQStatus sqQueueEmpty (SqQueue Q);		//空？
extern int sqQueueLength (SqQueue Q);			//长度
extern sqQStatus sqQueueGetHead (SqQueue Q, sqQElemType *e);		//头元素
extern sqQStatus sqQueueEnQueue (SqQueue *Q, sqQElemType e);		//入队			
extern sqQStatus sqQueueDeQueue (SqQueue *Q, sqQElemType *e);		//出队





#endif  /*  __QUEUE_H__  */

