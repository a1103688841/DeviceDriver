/**************************************************************************************************
* ����:                              ˳��ջ
*        
* �ļ�:  Stack.c
*        
* ˵��:  
*        
* ����:  ���Ϸ�  10/23/2020
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
*	 ����
* 1����ӡ����   ������Ĵ�ӡ�߼����������е㲻һ����
* 2���ڲ���������
* 3) ʹ��ʾ��   ��20201023�汾��
**************************************************************************************************
*1�� ��ӡ����
**************************************************************************************************/
//��ӡһ��Ԫ��
static sqSStatus sqStackVisit(sqSElemType c)
{
	printf("%d ",c);
	return OK;
}
/* ��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ����ʾ */
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
*2�� �ڲ���������
**************************************************************************************************/
/*  ����һ����ջS */
sqSStatus sqStackInit(SqStack *S)
{ 
	S->top=-1;
	return OK;
}

/* ��S��Ϊ��ջ */
sqSStatus sqStackClear(SqStack *S)
{ 
        S->top=-1;
        return OK;
}

/* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
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

/* ����S��Ԫ�ظ�������ջ�ĳ��� */
int sqStackLength(SqStack S)
{ 
	return S.top+1;
}

/* ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
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

/* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
sqSStatus sqStackPush(SqStack *S, sqSElemType e)
{
	if(S->top == SQSMAXSIZE -1) 	/* ջ�� */
	{
	    return ERROR;
	}
	S->top++;					/* ջ��ָ������һ */
	S->data[S->top]=e;  		/* ���²���Ԫ�ظ�ֵ��ջ���ռ� */
	return OK;
}

/* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
sqSStatus sqStacPop(SqStack *S, sqSElemType *e)
{ 
	if(S->top==-1)
	{
	    return ERROR;
	}
	*e=S->data[S->top];			/* ��Ҫɾ����ջ��Ԫ�ظ�ֵ��e */
	S->top--;					/* ջ��ָ���һ */
	return OK;
}


/**************************************************************************************************
*3) ʹ��ʾ��   ��20201023�汾��
**************************************************************************************************/
#if 0
int main()
{
	//��ʱ����
	int32_t j;
	//��ʼ��
	if(sqStackInit(&sqStack_var) == OK)
	{
		//��ջ
		for(j=1;j<=10;j++)
		{
			sqStackPush(&sqStack_var,j);
		}
	}
	//��ӡ
	printf("ջ��Ԫ������Ϊ��");
	sqStackPrintfTraverse(sqStack_var);
	//��ջ
	sqStacPop(&sqStack_var,&SqStack_elem);
	printf("������ջ��Ԫ�� e=%d\n",SqStack_elem);
	//�գ�
	printf("ջ�շ�%d(1:�� 0:��)\n",sqStackEmpty(sqStack_var));
	//�õ�ջ��
	sqStackGetTop(sqStack_var,&SqStack_elem);
	//����
	printf("ջ��Ԫ�� e=%d ջ�ĳ���Ϊ%d\n",SqStack_elem,sqStackLength(sqStack_var));
	//���
	sqStackClear(&sqStack_var);
	printf("���ջ��ջ�շ�%d(1:�� 0:��)\n",sqStackEmpty(sqStack_var));
	        
	return 0;
}
#endif

