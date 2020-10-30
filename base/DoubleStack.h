/**************************************************************************************************
* �ļ�:  DoubleStack.h
*        
* ˵��:  
*        
* ����:  ���Ϸ�  10/27/2020
**************************************************************************************************/
#ifndef __DOUBLESTACK_H__
#define __DOUBLESTACK_H__

/* ------------------------------------------- include ----------------------------------------- */
#include "def.h"

/* ------------------------------------- define/typedef/enum ----------------------------------- */

typedef int sqDStatus; 
typedef int sqDSElemType; /* SElemType���͸���ʵ������������������Ϊint */
//ע������ָ���sqList�����Ǹ����Ȳ�һ��
//�յĻ� ���ָ��ָ��-1���ұ�ָ��ָ��SQDS_MAXSIZE
#define SQDS_MAXSIZE 100
/* ��ջ����ռ�ṹ */
typedef struct 
{
        sqDSElemType data[SQDS_MAXSIZE];
        int top1;	/* ջ1ջ��ָ�� */
        int top2;	/* ջ2ջ��ָ�� */
}SqDoubleStack;
//����ջ��������1��2
typedef enum
{
	SQDS_1=1,
	SQDS_2=2,
}SqDoubleStack_Num_E;
/* ------------------------------------------- variable ---------------------------------------- */
#ifdef __DOUBLESTACK_C__
	#define DOUBLESTACK_EXT
#else
	#define DOUBLESTACK_EXT		extern
#endif

DOUBLESTACK_EXT sqDSElemType 	sqDStack_elem;
DOUBLESTACK_EXT sqDStatus 		sqDStack_status;
DOUBLESTACK_EXT SqDoubleStack 	sqDStack_test;


#if 0
DOUBLESTACK_EXT S32 var
#ifdef __DOUBLESTACK_C__
= 0
#endif
;
#endif

/* ------------------------------------------- funtion ----------------------------------------- */

/* externs */
//��ӡ
extern sqDStatus 	sqDStackPrintfTraverse (SqDoubleStack S);	//˳���ӡ
//�ڲ�
extern sqDStatus 	sqDStackInit (SqDoubleStack *S);		//��ʼ��
extern sqDStatus 	sqDStackClear (SqDoubleStack *S);		//���
extern sqDStatus 	sqDStackEmpty (SqDoubleStack S);		//�գ�
extern int 			sqDStackLength (SqDoubleStack S);		//����
extern sqDStatus 	sqDStackPush (SqDoubleStack *S, sqDSElemType e, int stackNumber);		//��ջ
extern sqDStatus 	sqDStackPop (SqDoubleStack *S, sqDSElemType *e, int stackNumber);		//��ջ





#endif  /*  __DOUBLESTACK_H__  */

