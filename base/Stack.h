/**************************************************************************************************
* �ļ�:  Stack.h
*        
* ˵��:  
*        
* ����:  ���Ϸ�  10/23/2020
**************************************************************************************************/
#ifndef __STACK_H__
#define __STACK_H__

/* ------------------------------------------- include ----------------------------------------- */
#include "def.h"

/* ------------------------------------- define/typedef/enum ----------------------------------- */
typedef int sqSStatus; 
typedef int sqSElemType; /* SElemType���͸���ʵ������������������Ϊint */
#define SQSMAXSIZE 20
/* ˳��ջ�ṹ */
//���ﳤ�ȵĶ��廹��һ�µ�(1-N)�������ڲ�ָ����߼���(0-N)��ע������sqList�ĳ�Ա��Length��1-N��
typedef struct
{
	sqSElemType data[SQSMAXSIZE];
	int top; /* ����ջ��ָ�� */
}SqStack;



/* ------------------------------------------- variable ---------------------------------------- */
#ifdef __STACK_C__
	#define STACK_EXT
#else
	#define STACK_EXT		extern
#endif

STACK_EXT sqSStatus		sqStack_status;
STACK_EXT sqSElemType	SqStack_elem;
STACK_EXT SqStack 		sqStack_var;


#if 0
STACK_EXT S32 var
#ifdef __STACK_C__
= 0
#endif
;
#endif

/* ------------------------------------------- funtion ----------------------------------------- */

/* externs */
//��ӡ
extern sqSStatus sqStackPrintfTraverse (SqStack S);				//��ӡ
//�ڲ���������
extern sqSStatus sqStackInit (SqStack *S);		//��ʼ��
extern sqSStatus sqStackClear (SqStack *S);	//���
extern sqSStatus sqStackEmpty (SqStack S);		//�գ�
extern int sqStackLength (SqStack S);			//����
extern sqSStatus sqStackGetTop (SqStack S, sqSElemType *e);		//ջ��
extern sqSStatus sqStackPush (SqStack *S, sqSElemType e);		//��ջ
extern sqSStatus sqStacPop (SqStack *S, sqSElemType *e);		//��ջ



#endif  /*  __STACK_H__  */
	
