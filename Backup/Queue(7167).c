/**************************************************************************************************
* 功能:                              顺序队列
*        
* 文件:  Queue.c
*        
* 说明:  
*        
* 作者:  日南方  10/22/2020
**************************************************************************************************/

#define __QUEUE_C__
/* ------------------------------------------- include ----------------------------------------- */
#include "Queue.h"

/* ------------------------------------- define/typedef/enum ----------------------------------- */


/* ------------------------------------------- variable ---------------------------------------- */


/* -------------------------------------------static funtion ----------------------------------------- */
#ifdef STATIC_FUNCTION
#endif	/* STATIC_FUNCTION */


/* -------------------------------------------global funtion ----------------------------------------- */
#ifdef GLOBAL_FUNCTION
#endif	/* GLOBAL_FUNCTION */

/**************************************************************************************************
*	 汇总
* 1）打印函数
* 2）内部操作函数
* 3) 使用示例（20200601版本未更新）
**************************************************************************************************
*1） 打印函数
**************************************************************************************************/
static sqQStatus sqQueueVisit(sqQElemType c)
{
	printf("%d ",c);
	return OK;
}
/* 从队头到队尾依次对队列Q中每个元素输出 */
sqQStatus sqQueuePrintfTraverse(SqQueue Q)
{ 
	int i;
	i=Q.front;
	while((i+Q.front)!=Q.rear)
	{
		sqQueueVisit(Q.data[i]);
		i=(i+1)%SQQUEUEMAXSIZE;
	}
	printf("\n");
	return OK;
}
/**************************************************************************************************
*2） 内部操作函数
**************************************************************************************************/
/* 初始化一个空队列Q */
void sqQueueInit(SqQueue *Q)
{
	Q->front=0;
	Q->rear=0;
}

/* 将Q清为空队列 */
void sqQueueClear(SqQueue *Q)
{
	Q->front=0;
	Q->rear=0;
}

/* 若队列Q为空队列,则返回TRUE,否则返回FALSE */
sqQStatus sqQueueEmpty(SqQueue Q)
{ 
	if(Q.front==Q.rear) /* 队列空的标志 */
		return TRUE;
	else
		return FALSE;
}

/* 返回Q的元素个数，也就是队列的当前长度 */
int sqQueueLength(SqQueue Q)
{
	//求队列长度是(Q.rear-Q.front+SQQUEUEMAXSIZE)%SQQUEUEMAXSIZE
	//情况1）rear在front大，值的含义是距离，正常值是正的，加上一圈，不影响
	//情况2）front在rear大，值是负的，值的大小等于他们之间的距离，加上一圈就是将一圈减去他们的距离，剩余另一半的正距离
	return  (Q.rear-Q.front+SQQUEUEMAXSIZE)%SQQUEUEMAXSIZE;
}


/* 若队列未满，则插入元素e为Q新的队尾元素 */
sqQStatus sqQueueEnQueue(SqQueue *Q, sqQElemType e)
{
	if ((Q->rear+1)%SQQUEUEMAXSIZE == Q->front)		/* 队列满的判断 */
	{
		return ERROR;
	}
	Q->data[Q->rear]=e;								/* 将元素e赋值给队尾 */
	//入队更新入队指针
	Q->rear=(Q->rear+1)%SQQUEUEMAXSIZE;				/* rear指针向后移一位置， */
													/* 若到最后则转到数组头部 */
	return  OK;
}

/* 若队列不空，则删除Q中队头元素，用e返回其值 */
sqQStatus sqQueueDeQueue(SqQueue *Q, sqQElemType *e)
{
	if (Q->front == Q->rear)						/* 队列空的判断 */
	{
		return ERROR;
	}
	*e=Q->data[Q->front];							/* 将队头元素赋值给e */
	//出队更新出队指针
	Q->front=(Q->front+1)% SQQUEUEMAXSIZE;					/* front指针向后移一位置， */
													/* 若到最后则转到数组头部 */
	return  OK;
}

/* 若队列不空,则用e返回Q的队头元素,并返回OK,否则返回ERROR */
sqQStatus sqQueueGetHead(SqQueue Q, sqQElemType *e)
{
	if(Q.front==Q.rear) /* 队列空 */
	{
		return ERROR;
	}
	*e=Q.data[Q.front];
	return OK;
}

/**************************************************************************************************
*3） 内部操作函数示例（20201023）
**************************************************************************************************/
#if 0
void main()
{
	sqQueueInit(&sqq_var_test);
	sqQueueEnQueue(&sqq_var_test,1);
	sqQueueEnQueue(&sqq_var_test,2);
	sqQueueEnQueue(&sqq_var_test,3);
	printf("入队1,2,3后：");
	sqQueuePrintfTraverse(sqq_var_test);
	printf("当前队列个数 %d\n", sqQueueLength(sqq_var_test));
	sqQueueClear(&sqq_var_test);
	printf("清空后: %d (1是空，0是不空)\n", sqQueueEmpty(sqq_var_test));
	sqQueueEnQueue(&sqq_var_test, 8);
	sqQueueEnQueue(&sqq_var_test, 3);
	sqQueueEnQueue(&sqq_var_test, 5);
	printf("入队8,3,5后：");
	sqQueuePrintfTraverse(sqq_var_test);
	sqQueueDeQueue(&sqq_var_test,&sqq_elem);
	printf("\n出队元素是%d",sqq_elem);
}
#endif

