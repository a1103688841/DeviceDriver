/**************************************************************************************************
* 功能:                              共享链栈
*        
* 文件:  DoubleStack.c
*        
* 说明:  
*        
* 作者:  日南方  10/27/2020
**************************************************************************************************/

#define __DOUBLESTACK_C__
/* ------------------------------------------- include ----------------------------------------- */
#include	"DoubleStack.h"

/* ------------------------------------- define/typedef/enum ----------------------------------- */


/* ------------------------------------------- variable ---------------------------------------- */


/* -------------------------------------------static funtion ----------------------------------------- */
#ifdef STATIC_FUNCTION
#endif	/* STATIC_FUNCTION */
static sqDStatus sqDSVisit(sqDSElemType c);

/* -------------------------------------------global funtion ----------------------------------------- */
#ifdef GLOBAL_FUNCTION
#endif	/* GLOBAL_FUNCTION */

/**************************************************************************************************
*	 汇总
* 1）打印函数
* 2）内部操作函数			（）
* 3）高级函数			（）
* 4) 使用示例			（20201027）
**************************************************************************************************
*1） 打印函数
**************************************************************************************************/
static sqDStatus sqDSVisit(sqDSElemType c)
{
        printf("%d ",c);
        return OK;
}

sqDStatus sqDStackPrintfTraverse(SqDoubleStack S)
{
	int i;
	i=0;
	while(i<=S.top1)
	{
	    sqDSVisit(S.data[i++]);
	}
	printf("  ||||||  ");
	i = SQDS_MAXSIZE-1;
	while(i >= S.top2)
	{
	    sqDSVisit(S.data[i--]);
	}
	printf("\n");
	return OK;
}
/**************************************************************************************************
*1） 内部操作函数
**************************************************************************************************/
/*  构造一个空栈S */
sqDStatus sqDStackInit(SqDoubleStack *S)
{ 
        S->top1=-1;
        S->top2=SQDS_MAXSIZE;
        return OK;
}

/* 把S置为空栈 */
sqDStatus sqDStackClear(SqDoubleStack *S)
{ 
        S->top1=-1;
        S->top2=SQDS_MAXSIZE;
        return OK;
}

/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
sqDStatus sqDStackEmpty(SqDoubleStack S)
{ 
	if (S.top1==-1 && S.top2==SQDS_MAXSIZE)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/* 返回S的元素个数，即栈的长度 */
int sqDStackLength(SqDoubleStack S)
{ 
	return (S.top1+1)+(SQDS_MAXSIZE-S.top2);
}

/* 插入元素e为新的栈顶元素 */
sqDStatus sqDStackPush(SqDoubleStack *S, sqDSElemType e, int stackNumber)
{
	if (S->top1+1==S->top2)	/* 栈已满，不能再push新元素了 */
	{
		return ERROR;	
	}
	//输入的栈索引超界
	if (!((stackNumber == 1)||(stackNumber == 2)))
	{
		return ERROR;
	}
	if (stackNumber==1)			/* 栈1有元素进栈 */
	{
	    S->data[++S->top1]=e; /* 若是栈1则先top1+1后给数组元素赋值。 */
	}
	else if (stackNumber==2)	/* 栈2有元素进栈 */
	{
		S->data[--S->top2]=e; /* 若是栈2则先top2-1后给数组元素赋值。 */
	}
	return OK;
}

/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
sqDStatus sqDStackPop(SqDoubleStack *S, sqDSElemType *e, int stackNumber)
{ 
	//输入的栈索引超界
	if (!((stackNumber == 1)||(stackNumber == 2)))
	{
		return ERROR;
	}
	if (stackNumber==1) 
	{
	    if (S->top1==-1) 
	    {
	        return ERROR; /* 说明栈1已经是空栈，溢出 */
		}
        *e=S->data[S->top1--]; /* 将栈1的栈顶元素出栈 */
	}
	else if (stackNumber==2)
	{ 
        if (S->top2==SQDS_MAXSIZE)
        {
	        return ERROR; /* 说明栈2已经是空栈，溢出 */
		}
        *e=S->data[S->top2++]; /* 将栈2的栈顶元素出栈 */
	}
	return OK;
}

/**************************************************************************************************
*4) 使用示例	（20201027）
**************************************************************************************************/
#if 1
int main()
{
	int32_t j;
	if(sqDStackInit(&sqDStack_test)==OK)
	{
		for(j = 1; j <= 5; j++)
		{
	        sqDStackPush(&sqDStack_test, j, SQDS_1);
		}
		for(j = SQDS_MAXSIZE; j >= SQDS_MAXSIZE-2; j--)
		{
	        sqDStackPush(&sqDStack_test, j, SQDS_2);
		}
		
	}

	printf("栈中元素依次为：");
	sqDStackPrintfTraverse(sqDStack_test);

	printf("当前栈中元素有：%d \n", sqDStackLength(sqDStack_test));

	sqDStackPop(&sqDStack_test, &sqDStack_elem, SQDS_2);
	printf("弹出的栈2的栈顶元素 e=%d\n", sqDStack_elem);
	printf("栈空否：%d(1:空 0:否)\n", sqDStackEmpty(sqDStack_test));

	for(j=6;j<=SQDS_MAXSIZE-2;j++)
	{
	    sqDStackPush(&sqDStack_test, j, SQDS_1);
	}
	
	printf("栈中元素依次为：");
	sqDStackPrintfTraverse(sqDStack_test);

	printf("栈满否：%d(1:否 0:满)\n", sqDStackPush(&sqDStack_test,100,SQDS_1));


	sqDStackClear(&sqDStack_test);
	printf("清空栈后，栈空否：%d(1:空 0:否)\n",sqDStackEmpty(sqDStack_test));

	return 0;
}
#endif
