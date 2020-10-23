/**************************************************************************************************
* ����:                              ˳�����
*        
* �ļ�:  Queue.c
*        
* ˵��:  
*        
* ����:  ���Ϸ�  10/22/2020
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
*	 ����
* 1����ӡ����
* 2���ڲ���������
* 3���߼�������Ҫע����󷵻صĳ����Ƿ���ȷ
* 4) �����ĸ߼�����
* 5���ض�����������Ϊ���������
* 6) ʹ��ʾ����20200601�汾δ���£�
**************************************************************************************************
*1�� ��ӡ����
**************************************************************************************************/
static sqQStatus sqQueueVisit(sqQElemType c)
{
	printf("%d ",c);
	return OK;
}
/* �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ����� */
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


/* ��ʼ��һ���ն���Q */
sqQStatus sqQueueInit(SqQueue *Q)
{
	Q->front=0;
	Q->rear=0;
	return  OK;
}

/* ��Q��Ϊ�ն��� */
sqQStatus sqQueueClear(SqQueue *Q)
{
	Q->front=0;
	Q->rear=0;
	return OK;
}

/* ������QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */
sqQStatus sqQueueEmpty(SqQueue Q)
{ 
	if(Q.front==Q.rear) /* ���пյı�־ */
		return TRUE;
	else
		return FALSE;
}

/* ����Q��Ԫ�ظ�����Ҳ���Ƕ��еĵ�ǰ���� */
int sqQueueLength(SqQueue Q)
{
	//����г�����(Q.rear-Q.front+SQQUEUEMAXSIZE)%SQQUEUEMAXSIZE
	//���1��rear��front��ֵ�ĺ����Ǿ��룬����ֵ�����ģ�����һȦ����Ӱ��
	//���2��front��rear��ֵ�Ǹ��ģ�ֵ�Ĵ�С��������֮��ľ��룬����һȦ���ǽ�һȦ��ȥ���ǵľ��룬ʣ����һ���������
	return  (Q.rear-Q.front+SQQUEUEMAXSIZE)%SQQUEUEMAXSIZE;
}


/* ������δ���������Ԫ��eΪQ�µĶ�βԪ�� */
sqQStatus sqEnQueue(SqQueue *Q, sqQElemType e)
{
	if ((Q->rear+1)%SQQUEUEMAXSIZE == Q->front)		/* ���������ж� */
	{
		return ERROR;
	}
	Q->data[Q->rear]=e;								/* ��Ԫ��e��ֵ����β */
	//��Ӹ������ָ��
	Q->rear=(Q->rear+1)%SQQUEUEMAXSIZE;				/* rearָ�������һλ�ã� */
													/* ���������ת������ͷ�� */
	return  OK;
}

/* �����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ */
sqQStatus sqDeQueue(SqQueue *Q, sqQElemType *e)
{
	if (Q->front == Q->rear)						/* ���пյ��ж� */
	{
		return ERROR;
	}
	*e=Q->data[Q->front];							/* ����ͷԪ�ظ�ֵ��e */
	//���Ӹ��³���ָ��
	Q->front=(Q->front+1)% SQQUEUEMAXSIZE;					/* frontָ�������һλ�ã� */
													/* ���������ת������ͷ�� */
	return  OK;
}

/* �����в���,����e����Q�Ķ�ͷԪ��,������OK,���򷵻�ERROR */
sqQStatus sqQueueGetHead(SqQueue Q, sqQElemType *e)
{
	if(Q.front==Q.rear) /* ���п� */
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
	printf("��ʼ�����к󣬶��пշ�%u(1:�� 0:��)\n",QueueEmpty(Q));

	printf("���������Ͷ���Ԫ��(������%d��),-1Ϊ��ǰ������: ",SQQUEUEMAXSIZE-1);
	do
	{
		/* scanf("%d",&d); */
		d=i+100;
		if(d==-1)
			break;
		i++;
		EnQueue(&Q,d);
	}while(i< SQQUEUEMAXSIZE -1);

	printf("���г���Ϊ: %d\n",QueueLength(Q));
	printf("���ڶ��пշ�%u(1:�� 0:��)\n",QueueEmpty(Q));
	printf("����%d���ɶ�ͷɾ��Ԫ��,��β����Ԫ��:\n", SQQUEUEMAXSIZE);
	for(l=1;l<=MAXSIZE;l++)
	{
		DeQueue(&Q,&d);
		printf("ɾ����Ԫ����%d,�����Ԫ��:%d \n",d,l+1000);
		/* scanf("%d",&d); */
		d=l+1000;
		EnQueue(&Q,d);
	}
	l=QueueLength(Q);

	printf("���ڶ����е�Ԫ��Ϊ: \n");
	QueueTraverse(Q);
	printf("�����β������%d��Ԫ��\n",i+ SQQUEUEMAXSIZE);
	if(l-2>0)
		printf("�����ɶ�ͷɾ��%d��Ԫ��:\n",l-2);
	while(QueueLength(Q)>2)
	{
		DeQueue(&Q,&d);
		printf("ɾ����Ԫ��ֵΪ%d\n",d);
	}

	j=GetHead(Q,&d);
	if(j)
		printf("���ڶ�ͷԪ��Ϊ: %d\n",d);
	ClearQueue(&Q);
	printf("��ն��к�, ���пշ�%u(1:�� 0:��)\n",QueueEmpty(Q));
	return 0;
}

