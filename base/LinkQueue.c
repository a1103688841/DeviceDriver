/**************************************************************************************************
* 功能:                              链表队列
*        
* 文件:  LinkQueue.c
*        
* 说明:  
*        
* 作者:  日南方  10/23/2020
**************************************************************************************************/

#define __LINKQUEUE_C__
/* ------------------------------------------- include ----------------------------------------- */
#include "LinkQueue.h"

/* ------------------------------------- define/typedef/enum ----------------------------------- */


/* ------------------------------------------- variable ---------------------------------------- */


/* -------------------------------------------static funtion ----------------------------------------- */
#ifdef STATIC_FUNCTION
#endif	/* STATIC_FUNCTION */

static void lQVisit(lQElemType c);
/* -------------------------------------------global funtion ----------------------------------------- */
#ifdef GLOBAL_FUNCTION
#endif	/* GLOBAL_FUNCTION */

/**************************************************************************************************
*	 汇总
* 1）打印函数 
* 2）内部操作函数 (含头结点，出队指针指向头结点，入队指针指向队列最后一个变量)
* 3) 使用示例（20201023）
**************************************************************************************************
*1） 打印函数
**************************************************************************************************/
static void lQueueVisit(lQElemType c)
{
	printf("%d ",c);
}
/* 从队头到队尾依次对队列Q中每个元素输出 */
lQStatus lQueuePrintfTraverse(LinkQueue Q)
{
	//p是扫描指针
	QueuePtr p;
	//指向第一个节点
	p=Q.front->next;
	while(p)
	{
		lQueueVisit(p->data);
		p=p->next;
	}
	printf("\n");
	return OK;
}

/**************************************************************************************************
*2） 内部操作函数
**************************************************************************************************/
/* 构造一个空队列Q */
lQStatus lQueueInit(LinkQueue *Q)
{ 
	//申请一个空间
	Q->front = (QNode*)malloc(sizeof(QNode));
	Q->rear = Q->front;
	if(Q->front == NULL)
	{
		return ERROR;
	}
	Q->front->next=NULL;
	return OK;
}

/* 销毁队列Q */
lQStatus lQueueDestroy(LinkQueue *Q)
{
	//这边Q->rear临时作为变量
	while(Q->front)
	{
		 Q->rear = Q->front->next;
		 free(Q->front);
		 Q->front = Q->rear;
	}
	return OK;
}

/* 将Q清为空队列 */
lQStatus lQueueClear(LinkQueue *Q)
{
	//p是扫描指针，q是临时变量
	QueuePtr p,q;
	//将p指向第一个节点，入队和出队指针指向头结点
	Q->rear = Q->front;
	p = Q->front->next;
	Q->front->next = NULL;
	while(p)
	{
		 q=p;
		 p=p->next;
		 free(q);
	}
	return OK;
}

/* 若Q为空队列,则返回TRUE,否则返回FALSE */
lQStatus lQueueEmpty(LinkQueue Q)
{ 
	if(Q.front==Q.rear)
		return TRUE;
	else
		return FALSE;
}

/* 求队列的长度 */
int lQueueLength(LinkQueue Q)
{ 
	int i=0;
	QueuePtr p;
	p=Q.front;
	while(Q.rear!=p)
	{
		 i++;
		 p=p->next;
	}
	return i;
}

/* 若队列不空,则用e返回Q的队头元素,并返回OK,否则返回ERROR */
lQStatus lQueueGetHead(LinkQueue Q, lQElemType *e)
{ 
	//p是临时指针
	QueuePtr p;
	if(Q.front==Q.rear)
	{
		return ERROR;
	}
	p=Q.front->next;
	*e=p->data;
	return OK;
}


/* 插入元素e为Q的新的队尾元素 */
lQStatus lQueueEnQueue(LinkQueue *Q, lQElemType e)
{ 
	//s是入队指针
	QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
	if(s == NULL) /* 存储分配失败 */
	{
		return ERROR;
	}
	s->data=e;
	s->next=NULL;
	Q->rear->next=s;	/* 把拥有元素e的新结点s赋值给原队尾结点的后继，见图中① */
	Q->rear=s;		/* 把当前的s设置为队尾结点，rear指向s，见图中② */
	return OK;
}

/* 若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR */
lQStatus lQueueDeQueue(LinkQueue *Q, lQElemType *e)
{	
	//p是出队指针
	QueuePtr p;
	//队列已经没有元素了
	if(Q->front==Q->rear)
	{
		return ERROR;
	}
	//指向第一个元素
	p=Q->front->next;			/* 将欲删除的队头结点暂存给p，见图中① */
	*e=p->data;					/* 将欲删除的队头结点的值赋值给e */
	Q->front->next=p->next;		/* 将原队头结点的后继p->next赋值给头结点后继，见图中② */
	if(Q->rear==p)				/* 若队头就是队尾，则删除后将rear指向头结点，见图中③ */
	{
		Q->rear=Q->front;
	}
	free(p);
	return OK;
}


/**************************************************************************************************
*2） 使用示例
**************************************************************************************************/
#if 1
int main()
{
	//初始化
	linkQueue_status = lQueueInit(&linkQueue_var);
	if (linkQueue_status)
	{
		printf("成功地构造了一个空队列!其中含头结点，出队指针指向头结点，入队指针指向队列最后一个变量！！！\n");
	}
	//空？
	printf("是否空队列？%d(1:空 0:否)  ", lQueueEmpty(linkQueue_var));
	//长度
	printf("队列的长度为%d\n", lQueueLength(linkQueue_var));
	//入队
	lQueueEnQueue(&linkQueue_var, -5);
	lQueueEnQueue(&linkQueue_var, 5);
	lQueueEnQueue(&linkQueue_var, 10);
	printf("插入3个元素(-5,5,10)后,队列的长度为%d\n", lQueueLength(linkQueue_var));
	printf("是否空队列？%d(1:空 0:否)  ", lQueueEmpty(linkQueue_var));
	//打印
	printf("队列的元素依次为：");
	lQueuePrintfTraverse(linkQueue_var);
	//得到队列头和出队
	linkQueue_status = lQueueGetHead(linkQueue_var, &linkQueue_elem);
	if (linkQueue_status == OK)
	{
		printf("队头元素是：%d\n", linkQueue_elem);
	}
	lQueueDeQueue(&linkQueue_var, &linkQueue_elem);
	printf("删除了队头元素%d\n", linkQueue_elem);
	linkQueue_status = lQueueGetHead(linkQueue_var, &linkQueue_elem);
	if(linkQueue_status == OK)
	{
		printf("新的队头元素是：%d\n", linkQueue_elem);
	}
	//清空
	lQueueClear(&linkQueue_var);
	printf("清空队列后,q.front=%u q.rear=%u q.front->next=%u\n",\
			linkQueue_var.front, linkQueue_var.rear, linkQueue_var.front->next);
	//销毁
	lQueueDestroy(&linkQueue_var);
	printf("销毁队列后,q.front=%u q.rear=%u\n", \
			linkQueue_var.front, linkQueue_var.rear);

	return 0;
}
#endif

