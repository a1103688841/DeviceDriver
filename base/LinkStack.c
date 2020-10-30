/**************************************************************************************************
* 功能:                              链栈
*        
* 文件:  LinkStack.c
*        
* 说明:  
*        
* 作者:  日南方  10/23/2020
**************************************************************************************************/

#define __LINKSTACK_C__
/* ------------------------------------------- include ----------------------------------------- */
#include "LinkStack.h"

/* ------------------------------------- define/typedef/enum ----------------------------------- */


/* ------------------------------------------- variable ---------------------------------------- */


/* -------------------------------------------static funtion ----------------------------------------- */
#ifdef STATIC_FUNCTION
#endif	/* STATIC_FUNCTION */
/* static function pre-declared */
static lSStatus lStackVisit (lSElemType c);

/* -------------------------------------------global funtion ----------------------------------------- */
#ifdef GLOBAL_FUNCTION
#endif	/* GLOBAL_FUNCTION */


/**************************************************************************************************
*	 汇总
* 1）打印函数   （）
* 2）内部操作函数（不包含头结点）
* 3) 使用示例   （20201023版本）
**************************************************************************************************
*1） 打印函数
**************************************************************************************************/
//打印一个元素
static lSStatus lStackVisit(lSElemType c)
{
        printf("%d ",c);
        return OK;
}
lSStatus lStackPrintfTraverse(LinkStack S)
{
	LinkStackPtr p;
	p=S.top;
	while(p)
	{
		lStackVisit(p->data);
		p=p->next;
	}
	printf("\n");
	return OK;
}

/**************************************************************************************************
*2） 内部函数
**************************************************************************************************/
/*  构造一个空栈S */
lSStatus lStackInit(LinkStack *S)
{ 
	//不含头结点
	//S->top = (LinkStackPtr)malloc(sizeof(StackNode));
	//if(!S->top)
	//{
    //    return ERROR;
	//}
	S->top=NULL;
	S->count=0;
	return OK;
}
/* 把S置为空栈 */
lSStatus lStackClear(LinkStack *S)
{ 
	//p是扫描指针,不包含头结点
    LinkStackPtr p,q;
    p=S->top;
    while(p)
    {  
        q=p;
        p=p->next;
        free(q);
    } 
    S->count=0;
    return OK;
}

/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
lSStatus lStackEmpty(LinkStack S)
{ 
	if (S.count==0)
	{
	    return TRUE;
	}
	else
	{
	    return FALSE;
	}
}

/* 返回S的元素个数，即栈的长度 */
int lStackLength(LinkStack S)
{ 
	return S.count;
}

/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
lSStatus lStackGetTop(LinkStack S, lSElemType *e)
{
	if (S.top==NULL)
	{
		return ERROR;
	}
	else
	{
		*e=S.top->data;
	}
	return OK;
}

/* 插入元素e为新的栈顶元素 */
lSStatus lStackPush(LinkStack *S, lSElemType e)
{
	//s是入栈的变量指针
	LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode)); 
	s->data=e; 
	s->next=S->top;	/* 把当前的栈顶元素赋值给新结点的直接后继，见图中① */
	S->top=s;         /* 将新的结点s赋值给栈顶指针，见图中② */
	S->count++;
	return OK;
}

/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
lSStatus lStackPop(LinkStack *S, lSElemType *e)
{ 
	//p是临时变量的指针
	LinkStackPtr p;
	if(lStackEmpty(*S))
	{
	    return ERROR;
	}
	*e=S->top->data;
	p=S->top;					/* 将栈顶结点赋值给p，见图中③ */
	S->top=S->top->next;    /* 使得栈顶指针下移一位，指向后一结点，见图中④ */
	free(p);                    /* 释放结点p */        
	S->count--;
	return OK;
}

/**************************************************************************************************
* 3) 使用示例   （20201023版本）
**************************************************************************************************/
#if 0
int main()
{	
	int j;
	//初始化
	if(lStackInit(&linkStack_var) == OK)
	{
		//入栈
		for(j=1;j<=10;j++)
		{
			lStackPush(&linkStack_var, j);
		}
	}
	//打印
	printf("栈中元素依次为：");
	lStackPrintfTraverse(linkStack_var);
	//出栈
	lStackPop(&linkStack_var, &linkStack_elem);
	printf("弹出的栈顶元素 e=%d\n",linkStack_elem);
	//空？
	printf("栈空否：%d(1:空 0:否)\n",lStackEmpty(linkStack_var));
	//栈顶
	lStackGetTop(linkStack_var, &linkStack_elem);
	//长度
	printf("栈顶元素 e=%d 栈的长度为%d\n", linkStack_elem, lStackLength(linkStack_var));
	//清空
	lStackClear(&linkStack_var);
	printf("清空栈后，栈空否：%d(1:空 0:否)\n", lStackEmpty(linkStack_var));
	return 0;
}
#endif
