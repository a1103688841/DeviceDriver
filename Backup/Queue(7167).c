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
* 3) ʹ��ʾ����20200601�汾δ���£�
**************************************************************************************************
*1�� ��ӡ����
**************************************************************************************************/
static sqQStatus sqQueueVisit(sqQElemType c)
{
	printf("%d ",c);
	return OK;
}
/* �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ����� */
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
*2�� �ڲ���������
**************************************************************************************************/
/* ��ʼ��һ���ն���Q */
void sqQueueInit(SqQueue *Q)
{
	Q->front=0;
	Q->rear=0;
}

/* ��Q��Ϊ�ն��� */
void sqQueueClear(SqQueue *Q)
{
	Q->front=0;
	Q->rear=0;
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
sqQStatus sqQueueEnQueue(SqQueue *Q, sqQElemType e)
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
sqQStatus sqQueueDeQueue(SqQueue *Q, sqQElemType *e)
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

/**************************************************************************************************
*3�� �ڲ���������ʾ����20201023��
**************************************************************************************************/
#if 0
void main()
{
	sqQueueInit(&sqq_var_test);
	sqQueueEnQueue(&sqq_var_test,1);
	sqQueueEnQueue(&sqq_var_test,2);
	sqQueueEnQueue(&sqq_var_test,3);
	printf("���1,2,3��");
	sqQueuePrintfTraverse(sqq_var_test);
	printf("��ǰ���и��� %d\n", sqQueueLength(sqq_var_test));
	sqQueueClear(&sqq_var_test);
	printf("��պ�: %d (1�ǿգ�0�ǲ���)\n", sqQueueEmpty(sqq_var_test));
	sqQueueEnQueue(&sqq_var_test, 8);
	sqQueueEnQueue(&sqq_var_test, 3);
	sqQueueEnQueue(&sqq_var_test, 5);
	printf("���8,3,5��");
	sqQueuePrintfTraverse(sqq_var_test);
	sqQueueDeQueue(&sqq_var_test,&sqq_elem);
	printf("\n����Ԫ����%d",sqq_elem);
}
#endif

