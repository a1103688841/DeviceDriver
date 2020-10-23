/**************************************************************************************************
* �ļ�:  LinkQueue.h
*        
* ˵��:  
*        
* ����:  ���Ϸ�  10/23/2020
**************************************************************************************************/
#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

/* ------------------------------------------- include ----------------------------------------- */
#include "def.h"



/* ------------------------------------- define/typedef/enum ----------------------------------- */

typedef int lQStatus; 

typedef int lQElemType; /* QElemType���͸���ʵ������������������Ϊint */

typedef struct QNode	/* ���ṹ */
{
   lQElemType data;
   struct QNode *next;
}QNode,*QueuePtr;

typedef struct			/* ���е������ṹ */
{
   QueuePtr front,rear; /* ��ͷ����βָ�� */
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
//��ӡ
extern lQStatus lQueuePrintfTraverse (LinkQueue Q);
//�ڲ���������
extern lQStatus lQueueInit (LinkQueue *Q);			//��ʼ��
extern lQStatus lQueueDestroy (LinkQueue *Q);		//����
extern lQStatus lQueueClear (LinkQueue *Q);			//���
extern lQStatus lQueueEmpty (LinkQueue Q);			//�գ�
extern int lQueueLength (LinkQueue Q);				//����
extern lQStatus lQueueGetHead (LinkQueue Q, lQElemType *e);	//����ͷ
extern lQStatus lQueueEnQueue (LinkQueue *Q, lQElemType e);	//���
extern lQStatus lQueueDeQueue (LinkQueue *Q, lQElemType *e);	//����











#endif  /*  __LINKQUEUE_H__  */
