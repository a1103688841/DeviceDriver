/**************************************************************************************************
* �ļ�:  Queue.h
*        
* ˵��:  
*        
* ����:  ���Ϸ�  10/22/2020
**************************************************************************************************/
#ifndef __QUEUE_H__

#define __QUEUE_H__

/* ------------------------------------------- include ----------------------------------------- */
#include "def.h"

/* ------------------------------------- define/typedef/enum ----------------------------------- */

#define SQQUEUEMAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int sqQStatus; 
typedef int sqQElemType; /* sqQElemType���͸���ʵ������������������Ϊint */

/* ѭ�����е�˳��洢�ṹ */
//ͷָ���βָ����ȱ�ʾ���п�
//��β�����Ԫ�ص�ָ�룬��ͷ�ǳ���Ԫ�ص�ָ��
//SQQUEUEMAXSIZE=20,���Ƿ�����20���ռ䣬���ڲ�������0-19,����ֱ��%SQQUEUEMAXSIZE������0-19������ת��
//����г�����(Q.rear-Q.front+SQQUEUEMAXSIZE)%SQQUEUEMAXSIZE
//���1��rear��front��ֵ�ĺ����Ǿ��룬����ֵ�����ģ�����һȦ����Ӱ��
//���2��front��rear��ֵ�Ǹ��ģ�ֵ�Ĵ�С��������֮��ľ��룬����һȦ���ǽ�һȦ��ȥ���ǵľ��룬ʣ����һ���������
typedef struct
{
	sqQElemType data[SQQUEUEMAXSIZE];
	int32_t front;    	/* ͷָ�� */
	int32_t rear;		/* βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ�� */
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
//��ӡ����
extern sqQStatus sqQueuePrintfTraverse (SqQueue Q);
//�ڲ���������
extern void sqQueueInit (SqQueue *Q);			//��ʼ��
extern void sqQueueClear (SqQueue *Q);			//���
extern sqQStatus sqQueueEmpty (SqQueue Q);		//�գ�
extern int sqQueueLength (SqQueue Q);			//����
extern sqQStatus sqQueueGetHead (SqQueue Q, sqQElemType *e);		//ͷԪ��
extern sqQStatus sqQueueEnQueue (SqQueue *Q, sqQElemType e);		//���			
extern sqQStatus sqQueueDeQueue (SqQueue *Q, sqQElemType *e);		//����





#endif  /*  __QUEUE_H__  */

