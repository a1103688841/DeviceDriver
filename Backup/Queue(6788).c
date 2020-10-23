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
* 3）高级函数，要注意最后返回的长度是否正确
* 4) 有序表的高级函数
* 5）特定任务（数组作为输入参数）
* 6) 使用示例（20200601版本未更新）
**************************************************************************************************
*1） 打印函数
**************************************************************************************************/
static sqQStatus sqQueueVisit(sqQElemType c)
{
	printf("%d ",c);
	return OK;
}
/* 从队头到队尾依次对队列Q中每个元素输出 */
sqQStatus QueueTraverse(SqQueue Q)
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


/* 初始化一个空队列Q */
sqQStatus sqQueueInit(SqQueue *Q)
{
	Q->front=0;
	Q->rear=0;
	return  OK;
}

/* 将Q清为空队列 */
sqQStatus sqQueueClear(SqQueue *Q)
{
	Q->front=0;
	Q->rear=0;
	return OK;
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
sqQStatus sqEnQueue(SqQueue *Q, sqQElemType e)
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
sqQStatus sqDeQueue(SqQueue *Q, sqQElemType *e)
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


int main()
{
	sqQStatus j;
	int i=0,l;
	sqQElemType d;
	SqQueue Q;
	InitQueue(&Q);
	printf("初始化队列后，队列空否？%u(1:空 0:否)\n",QueueEmpty(Q));

	printf("请输入整型队列元素(不超过%d个),-1为提前结束符: ",SQQUEUEMAXSIZE-1);
	do
	{
		/* scanf("%d",&d); */
		d=i+100;
		if(d==-1)
			break;
		i++;
		EnQueue(&Q,d);
	}while(i< SQQUEUEMAXSIZE -1);

	printf("队列长度为: %d\n",QueueLength(Q));
	printf("现在队列空否？%u(1:空 0:否)\n",QueueEmpty(Q));
	printf("连续%d次由队头删除元素,队尾插入元素:\n", SQQUEUEMAXSIZE);
	for(l=1;l<=MAXSIZE;l++)
	{
		DeQueue(&Q,&d);
		printf("删除的元素是%d,插入的元素:%d \n",d,l+1000);
		/* scanf("%d",&d); */
		d=l+1000;
		EnQueue(&Q,d);
	}
	l=QueueLength(Q);

	printf("现在队列中的元素为: \n");
	QueueTraverse(Q);
	printf("共向队尾插入了%d个元素\n",i+ SQQUEUEMAXSIZE);
	if(l-2>0)
		printf("现在由队头删除%d个元素:\n",l-2);
	while(QueueLength(Q)>2)
	{
		DeQueue(&Q,&d);
		printf("删除的元素值为%d\n",d);
	}

	j=GetHead(Q,&d);
	if(j)
		printf("现在队头元素为: %d\n",d);
	ClearQueue(&Q);
	printf("清空队列后, 队列空否？%u(1:空 0:否)\n",QueueEmpty(Q));
	return 0;
}

