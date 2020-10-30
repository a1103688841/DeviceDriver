/**************************************************************************************************
* �ļ�:  LinkStack.h
*        
* ˵��:  
*        
* ����:  ���Ϸ�  10/23/2020
**************************************************************************************************/
#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__

/* ------------------------------------------- include ----------------------------------------- */
#include "def.h"

/* ------------------------------------- define/typedef/enum ----------------------------------- */
typedef int lSStatus; 
typedef int lSElemType; /* SElemType���͸���ʵ������������������Ϊint */


/* ��ջ�ṹ */
typedef struct StackNode
{
        lSElemType data;
        struct StackNode *next;
}StackNode,*LinkStackPtr;
//topָ��ָ��ջ����û��ͷ��㣩
typedef struct
{
	LinkStackPtr top;
	int count;
}LinkStack;

/* ------------------------------------------- variable ---------------------------------------- */
#ifdef __LINKSTACK_C__
	#define LINKSTACK_EXT
#else
	#define LINKSTACK_EXT		extern
#endif

LINKSTACK_EXT lSStatus 		linkStack_status;
LINKSTACK_EXT lSElemType	linkStack_elem;
LINKSTACK_EXT LinkStack		linkStack_var;

#if 0
LINKSTACK_EXT S32 var
#ifdef __LINKSTACK_C__
= 0
#endif
;
#endif

/* ------------------------------------------- funtion ----------------------------------------- */
/* externs */
//��ӡ
extern lSStatus lStackPrintfTraverse (LinkStack S);			//��ӡ
//�ڲ�����
extern lSStatus lStackInit (LinkStack *S);					//��ʼ
extern lSStatus lStackClear (LinkStack *S);					//���
extern lSStatus lStackEmpty (LinkStack S);					//�գ�
extern int lStackLength (LinkStack S);						//����
extern lSStatus lStackGetTop (LinkStack S, lSElemType *e);		//ջ��
extern lSStatus lStackPush (LinkStack *S, lSElemType e);		//��ջ
extern lSStatus lStackPop (LinkStack *S, lSElemType *e);		//��ջ




#endif  /*  __LINKSTACK_H__  */
	