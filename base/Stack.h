/**************************************************************************************************
* 文件:  Stack.h
*        
* 说明:  
*        
* 作者:  日南方  10/23/2020
**************************************************************************************************/
#ifndef __STACK_H__
#define __STACK_H__

/* ------------------------------------------- include ----------------------------------------- */
#include "def.h"

/* ------------------------------------- define/typedef/enum ----------------------------------- */
typedef int sqSStatus; 
typedef int sqSElemType; /* SElemType类型根据实际情况而定，这里假设为int */
#define SQSMAXSIZE 20
/* 顺序栈结构 */
//这里长度的定义还是一致的(1-N)，但是内部指针的逻辑是(0-N)，注意区别sqList的成员是Length（1-N）
typedef struct
{
	sqSElemType data[SQSMAXSIZE];
	int top; /* 用于栈顶指针 */
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
//打印
extern sqSStatus sqStackPrintfTraverse (SqStack S);				//打印
//内部操作函数
extern sqSStatus sqStackInit (SqStack *S);		//初始化
extern sqSStatus sqStackClear (SqStack *S);	//清空
extern sqSStatus sqStackEmpty (SqStack S);		//空？
extern int sqStackLength (SqStack S);			//长度
extern sqSStatus sqStackGetTop (SqStack S, sqSElemType *e);		//栈顶
extern sqSStatus sqStackPush (SqStack *S, sqSElemType e);		//出栈
extern sqSStatus sqStacPop (SqStack *S, sqSElemType *e);		//入栈



#endif  /*  __STACK_H__  */
	
