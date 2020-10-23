/**************************************************************************************************
* ����:                              �������
*        
* �ļ�:  LinkQueue.c
*        
* ˵��:  
*        
* ����:  ���Ϸ�  10/23/2020
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
*	 ����
* 1����ӡ���� 
* 2���ڲ��������� (��ͷ��㣬����ָ��ָ��ͷ��㣬���ָ��ָ��������һ������)
* 3) ʹ��ʾ����20201023��
**************************************************************************************************
*1�� ��ӡ����
**************************************************************************************************/
static void lQueueVisit(lQElemType c)
{
	printf("%d ",c);
}
/* �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ����� */
lQStatus lQueuePrintfTraverse(LinkQueue Q)
{
	//p��ɨ��ָ��
	QueuePtr p;
	//ָ���һ���ڵ�
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
*2�� �ڲ���������
**************************************************************************************************/
/* ����һ���ն���Q */
lQStatus lQueueInit(LinkQueue *Q)
{ 
	//����һ���ռ�
	Q->front = (QNode*)malloc(sizeof(QNode));
	Q->rear = Q->front;
	if(Q->front == NULL)
	{
		return ERROR;
	}
	Q->front->next=NULL;
	return OK;
}

/* ���ٶ���Q */
lQStatus lQueueDestroy(LinkQueue *Q)
{
	//���Q->rear��ʱ��Ϊ����
	while(Q->front)
	{
		 Q->rear = Q->front->next;
		 free(Q->front);
		 Q->front = Q->rear;
	}
	return OK;
}

/* ��Q��Ϊ�ն��� */
lQStatus lQueueClear(LinkQueue *Q)
{
	//p��ɨ��ָ�룬q����ʱ����
	QueuePtr p,q;
	//��pָ���һ���ڵ㣬��Ӻͳ���ָ��ָ��ͷ���
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

/* ��QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */
lQStatus lQueueEmpty(LinkQueue Q)
{ 
	if(Q.front==Q.rear)
		return TRUE;
	else
		return FALSE;
}

/* ����еĳ��� */
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

/* �����в���,����e����Q�Ķ�ͷԪ��,������OK,���򷵻�ERROR */
lQStatus lQueueGetHead(LinkQueue Q, lQElemType *e)
{ 
	//p����ʱָ��
	QueuePtr p;
	if(Q.front==Q.rear)
	{
		return ERROR;
	}
	p=Q.front->next;
	*e=p->data;
	return OK;
}


/* ����Ԫ��eΪQ���µĶ�βԪ�� */
lQStatus lQueueEnQueue(LinkQueue *Q, lQElemType e)
{ 
	//s�����ָ��
	QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
	if(s == NULL) /* �洢����ʧ�� */
	{
		return ERROR;
	}
	s->data=e;
	s->next=NULL;
	Q->rear->next=s;	/* ��ӵ��Ԫ��e���½��s��ֵ��ԭ��β���ĺ�̣���ͼ�Т� */
	Q->rear=s;		/* �ѵ�ǰ��s����Ϊ��β��㣬rearָ��s����ͼ�Т� */
	return OK;
}

/* �����в���,ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK,���򷵻�ERROR */
lQStatus lQueueDeQueue(LinkQueue *Q, lQElemType *e)
{	
	//p�ǳ���ָ��
	QueuePtr p;
	//�����Ѿ�û��Ԫ����
	if(Q->front==Q->rear)
	{
		return ERROR;
	}
	//ָ���һ��Ԫ��
	p=Q->front->next;			/* ����ɾ���Ķ�ͷ����ݴ��p����ͼ�Т� */
	*e=p->data;					/* ����ɾ���Ķ�ͷ����ֵ��ֵ��e */
	Q->front->next=p->next;		/* ��ԭ��ͷ���ĺ��p->next��ֵ��ͷ����̣���ͼ�Т� */
	if(Q->rear==p)				/* ����ͷ���Ƕ�β����ɾ����rearָ��ͷ��㣬��ͼ�Т� */
	{
		Q->rear=Q->front;
	}
	free(p);
	return OK;
}


/**************************************************************************************************
*2�� ʹ��ʾ��
**************************************************************************************************/
#if 1
int main()
{
	//��ʼ��
	linkQueue_status = lQueueInit(&linkQueue_var);
	if (linkQueue_status)
	{
		printf("�ɹ��ع�����һ���ն���!���к�ͷ��㣬����ָ��ָ��ͷ��㣬���ָ��ָ��������һ������������\n");
	}
	//�գ�
	printf("�Ƿ�ն��У�%d(1:�� 0:��)  ", lQueueEmpty(linkQueue_var));
	//����
	printf("���еĳ���Ϊ%d\n", lQueueLength(linkQueue_var));
	//���
	lQueueEnQueue(&linkQueue_var, -5);
	lQueueEnQueue(&linkQueue_var, 5);
	lQueueEnQueue(&linkQueue_var, 10);
	printf("����3��Ԫ��(-5,5,10)��,���еĳ���Ϊ%d\n", lQueueLength(linkQueue_var));
	printf("�Ƿ�ն��У�%d(1:�� 0:��)  ", lQueueEmpty(linkQueue_var));
	//��ӡ
	printf("���е�Ԫ������Ϊ��");
	lQueuePrintfTraverse(linkQueue_var);
	//�õ�����ͷ�ͳ���
	linkQueue_status = lQueueGetHead(linkQueue_var, &linkQueue_elem);
	if (linkQueue_status == OK)
	{
		printf("��ͷԪ���ǣ�%d\n", linkQueue_elem);
	}
	lQueueDeQueue(&linkQueue_var, &linkQueue_elem);
	printf("ɾ���˶�ͷԪ��%d\n", linkQueue_elem);
	linkQueue_status = lQueueGetHead(linkQueue_var, &linkQueue_elem);
	if(linkQueue_status == OK)
	{
		printf("�µĶ�ͷԪ���ǣ�%d\n", linkQueue_elem);
	}
	//���
	lQueueClear(&linkQueue_var);
	printf("��ն��к�,q.front=%u q.rear=%u q.front->next=%u\n",\
			linkQueue_var.front, linkQueue_var.rear, linkQueue_var.front->next);
	//����
	lQueueDestroy(&linkQueue_var);
	printf("���ٶ��к�,q.front=%u q.rear=%u\n", \
			linkQueue_var.front, linkQueue_var.rear);

	return 0;
}
#endif

