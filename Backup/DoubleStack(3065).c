/**************************************************************************************************
* ����:                              ������ջ
*        
* �ļ�:  DoubleStack.c
*        
* ˵��:  
*        
* ����:  ���Ϸ�  10/27/2020
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
*	 ����
* 1����ӡ����
* 2���ڲ���������			����
* 3���߼�����			����
* 4) ʹ��ʾ��			��20201027��
**************************************************************************************************
*1�� ��ӡ����
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
*1�� �ڲ���������
**************************************************************************************************/
/*  ����һ����ջS */
sqDStatus sqDStackInit(SqDoubleStack *S)
{ 
        S->top1=-1;
        S->top2=SQDS_MAXSIZE;
        return OK;
}

/* ��S��Ϊ��ջ */
sqDStatus sqDStackClear(SqDoubleStack *S)
{ 
        S->top1=-1;
        S->top2=SQDS_MAXSIZE;
        return OK;
}

/* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
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

/* ����S��Ԫ�ظ�������ջ�ĳ��� */
int sqDStackLength(SqDoubleStack S)
{ 
	return (S.top1+1)+(SQDS_MAXSIZE-S.top2);
}

/* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
sqDStatus sqDStackPush(SqDoubleStack *S, sqDSElemType e, int stackNumber)
{
	if (S->top1+1==S->top2)	/* ջ������������push��Ԫ���� */
	{
		return ERROR;	
	}
	//�����ջ��������
	if (!((stackNumber == 1)||(stackNumber == 2)))
	{
		return ERROR;
	}
	if (stackNumber==1)			/* ջ1��Ԫ�ؽ�ջ */
	{
	    S->data[++S->top1]=e; /* ����ջ1����top1+1�������Ԫ�ظ�ֵ�� */
	}
	else if (stackNumber==2)	/* ջ2��Ԫ�ؽ�ջ */
	{
		S->data[--S->top2]=e; /* ����ջ2����top2-1�������Ԫ�ظ�ֵ�� */
	}
	return OK;
}

/* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
sqDStatus sqDStackPop(SqDoubleStack *S, sqDSElemType *e, int stackNumber)
{ 
	//�����ջ��������
	if (!((stackNumber == 1)||(stackNumber == 2)))
	{
		return ERROR;
	}
	if (stackNumber==1) 
	{
	    if (S->top1==-1) 
	    {
	        return ERROR; /* ˵��ջ1�Ѿ��ǿ�ջ����� */
		}
        *e=S->data[S->top1--]; /* ��ջ1��ջ��Ԫ�س�ջ */
	}
	else if (stackNumber==2)
	{ 
        if (S->top2==SQDS_MAXSIZE)
        {
	        return ERROR; /* ˵��ջ2�Ѿ��ǿ�ջ����� */
		}
        *e=S->data[S->top2++]; /* ��ջ2��ջ��Ԫ�س�ջ */
	}
	return OK;
}

/**************************************************************************************************
*4) ʹ��ʾ��	��20201027��
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

	printf("ջ��Ԫ������Ϊ��");
	sqDStackPrintfTraverse(sqDStack_test);

	printf("��ǰջ��Ԫ���У�%d \n", sqDStackLength(sqDStack_test));

	sqDStackPop(&sqDStack_test, &sqDStack_elem, SQDS_2);
	printf("������ջ2��ջ��Ԫ�� e=%d\n", sqDStack_elem);
	printf("ջ�շ�%d(1:�� 0:��)\n", sqDStackEmpty(sqDStack_test));

	for(j=6;j<=SQDS_MAXSIZE-2;j++)
	{
	    sqDStackPush(&sqDStack_test, j, SQDS_1);
	}
	
	printf("ջ��Ԫ������Ϊ��");
	sqDStackPrintfTraverse(sqDStack_test);

	printf("ջ����%d(1:�� 0:��)\n", sqDStackPush(&sqDStack_test,100,SQDS_1));


	sqDStackClear(&sqDStack_test);
	printf("���ջ��ջ�շ�%d(1:�� 0:��)\n",sqDStackEmpty(sqDStack_test));

	return 0;
}
#endif
