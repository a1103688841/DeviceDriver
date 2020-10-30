/**************************************************************************************************
* 文件:  DoubleStack.h
*        
* 说明:  
*        
* 作者:  日南方  10/27/2020
**************************************************************************************************/
#ifndef __DOUBLESTACK_H__
#define __DOUBLESTACK_H__

/* ------------------------------------------- include ----------------------------------------- */
#include "def.h"

/* ------------------------------------- define/typedef/enum ----------------------------------- */

typedef int sqDStatus; 
typedef int sqDSElemType; /* SElemType类型根据实际情况而定，这里假设为int */
//注意这里指针和sqList里面那个长度不一样
//空的话 左边指针指向-1，右边指针指向SQDS_MAXSIZE
#define SQDS_MAXSIZE 100
/* 两栈共享空间结构 */
typedef struct 
{
        sqDSElemType data[SQDS_MAXSIZE];
        int top1;	/* 栈1栈顶指针 */
        int top2;	/* 栈2栈顶指针 */
}SqDoubleStack;
//共享栈的索引是1和2
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
//打印
extern sqDStatus 	sqDStackPrintfTraverse (SqDoubleStack S);	//顺序打印
//内部
extern sqDStatus 	sqDStackInit (SqDoubleStack *S);		//初始化
extern sqDStatus 	sqDStackClear (SqDoubleStack *S);		//清空
extern sqDStatus 	sqDStackEmpty (SqDoubleStack S);		//空？
extern int 			sqDStackLength (SqDoubleStack S);		//长度
extern sqDStatus 	sqDStackPush (SqDoubleStack *S, sqDSElemType e, int stackNumber);		//入栈
extern sqDStatus 	sqDStackPop (SqDoubleStack *S, sqDSElemType *e, int stackNumber);		//出栈





#endif  /*  __DOUBLESTACK_H__  */

