/**************************************************************************************************
* 功能:                              顺序栈
*        
* 文件:  Stack.c
*        
* 说明:  
*        
* 作者:  日南方  10/23/2020
**************************************************************************************************/

#define __STACK_C__
/* ------------------------------------------- include ----------------------------------------- */
#include "Stack.h"

/* ------------------------------------- define/typedef/enum ----------------------------------- */


/* ------------------------------------------- variable ---------------------------------------- */


/* -------------------------------------------static funtion ----------------------------------------- */
#ifdef STATIC_FUNCTION
#endif	/* STATIC_FUNCTION */

static sqSStatus sqStackVisit(sqSElemType c);

/* -------------------------------------------global funtion ----------------------------------------- */
#ifdef GLOBAL_FUNCTION
#endif	/* GLOBAL_FUNCTION */


/**************************************************************************************************
*	 汇总
* 1）打印函数   （这里的打印逻辑和其他的有点不一样）
* 2）内部操作函数
* 3) 使用示例   （20201023版本）
**************************************************************************************************
*1） 打印函数
**************************************************************************************************/
//打印一个元素
static sqSStatus sqStackVisit(sqSElemType c)
{
	printf("%d ",c);
	return OK;
}
/* 从栈底到栈顶依次对栈中每个元素显示 */
sqSStatus sqStackPrintfTraverse(SqStack S)
{
	int i;
	i=0;
	while(i<=S.top)
	{
		sqStackVisit(S.data[i++]);
	}
	printf("\n");
	return OK;
}

/**************************************************************************************************
*2） 内部操作函数
**************************************************************************************************/
/*  构造一个空栈S */
sqSStatus sqStackInit(SqStack *S)
{ 
	S->top=-1;
	return OK;
}

/* 把S置为空栈 */
sqSStatus sqStackClear(SqStack *S)
{ 
        S->top=-1;
        return OK;
}

/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
sqSStatus sqStackEmpty(SqStack S)
{ 
	if (S.top==-1)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/* 返回S的元素个数，即栈的长度 */
int sqStackLength(SqStack S)
{ 
	return S.top+1;
}

/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
sqSStatus sqStackGetTop(SqStack S, sqSElemType *e)
{
	if (S.top==-1)
	{
		return ERROR;
	}
	else
	{
		*e=S.data[S.top];
	}
	return OK;
}

/* 插入元素e为新的栈顶元素 */
sqSStatus sqStackPush(SqStack *S, sqSElemType e)
{
	if(S->top == SQSMAXSIZE -1) 	/* 栈满 */
	{
	    return ERROR;
	}
	S->top++;					/* 栈顶指针增加一 */
	S->data[S->top]=e;  		/* 将新插入元素赋值给栈顶空间 */
	return OK;
}

/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
sqSStatus sqStacPop(SqStack *S, sqSElemType *e)
{ 
	if(S->top==-1)
	{
	    return ERROR;
	}
	*e=S->data[S->top];			/* 将要删除的栈顶元素赋值给e */
	S->top--;					/* 栈顶指针减一 */
	return OK;
}


/**************************************************************************************************
*3) 使用示例   （20201023版本）
**************************************************************************************************/
#if 0
int main()
{
	//临时变量
	int32_t j;
	//初始化
	if(sqStackInit(&sqStack_var) == OK)
	{
		//入栈
		for(j=1;j<=10;j++)
		{
			sqStackPush(&sqStack_var,j);
		}
	}
	//打印
	printf("栈中元素依次为：");
	sqStackPrintfTraverse(sqStack_var);
	//出栈
	sqStacPop(&sqStack_var,&SqStack_elem);
	printf("弹出的栈顶元素 e=%d\n",SqStack_elem);
	//空？
	printf("栈空否：%d(1:空 0:否)\n",sqStackEmpty(sqStack_var));
	//得到栈顶
	sqStackGetTop(sqStack_var,&SqStack_elem);
	//长度
	printf("栈顶元素 e=%d 栈的长度为%d\n",SqStack_elem,sqStackLength(sqStack_var));
	//清空
	sqStackClear(&sqStack_var);
	printf("清空栈后，栈空否：%d(1:空 0:否)\n",sqStackEmpty(sqStack_var));
	        
	return 0;
}
#endif

