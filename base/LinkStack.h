/**************************************************************************************************
* 文件:  LinkStack.h
*        
* 说明:  
*        
* 作者:  日南方  10/23/2020
**************************************************************************************************/
#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__

/* ------------------------------------------- include ----------------------------------------- */
#include "def.h"

/* ------------------------------------- define/typedef/enum ----------------------------------- */
typedef int lSStatus; 
typedef int lSElemType; /* SElemType类型根据实际情况而定，这里假设为int */


/* 链栈结构 */
typedef struct StackNode
{
        lSElemType data;
        struct StackNode *next;
}StackNode,*LinkStackPtr;
//top指针指向栈顶（没有头结点）
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
//打印
extern lSStatus lStackPrintfTraverse (LinkStack S);			//打印
//内部函数
extern lSStatus lStackInit (LinkStack *S);					//初始
extern lSStatus lStackClear (LinkStack *S);					//清空
extern lSStatus lStackEmpty (LinkStack S);					//空？
extern int lStackLength (LinkStack S);						//长度
extern lSStatus lStackGetTop (LinkStack S, lSElemType *e);		//栈顶
extern lSStatus lStackPush (LinkStack *S, lSElemType e);		//入栈
extern lSStatus lStackPop (LinkStack *S, lSElemType *e);		//出栈




#endif  /*  __LINKSTACK_H__  */
	
