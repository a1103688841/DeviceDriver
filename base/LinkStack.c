/**************************************************************************************************
* ����:                              ��ջ
*        
* �ļ�:  LinkStack.c
*        
* ˵��:  
*        
* ����:  ���Ϸ�  10/23/2020
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
*	 ����
* 1����ӡ����   ����
* 2���ڲ�����������������ͷ��㣩
* 3) ʹ��ʾ��   ��20201023�汾��
**************************************************************************************************
*1�� ��ӡ����
**************************************************************************************************/
//��ӡһ��Ԫ��
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
*2�� �ڲ�����
**************************************************************************************************/
/*  ����һ����ջS */
lSStatus lStackInit(LinkStack *S)
{ 
	//����ͷ���
	//S->top = (LinkStackPtr)malloc(sizeof(StackNode));
	//if(!S->top)
	//{
    //    return ERROR;
	//}
	S->top=NULL;
	S->count=0;
	return OK;
}
/* ��S��Ϊ��ջ */
lSStatus lStackClear(LinkStack *S)
{ 
	//p��ɨ��ָ��,������ͷ���
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

/* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
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

/* ����S��Ԫ�ظ�������ջ�ĳ��� */
int lStackLength(LinkStack S)
{ 
	return S.count;
}

/* ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
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

/* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
lSStatus lStackPush(LinkStack *S, lSElemType e)
{
	//s����ջ�ı���ָ��
	LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode)); 
	s->data=e; 
	s->next=S->top;	/* �ѵ�ǰ��ջ��Ԫ�ظ�ֵ���½���ֱ�Ӻ�̣���ͼ�Т� */
	S->top=s;         /* ���µĽ��s��ֵ��ջ��ָ�룬��ͼ�Т� */
	S->count++;
	return OK;
}

/* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
lSStatus lStackPop(LinkStack *S, lSElemType *e)
{ 
	//p����ʱ������ָ��
	LinkStackPtr p;
	if(lStackEmpty(*S))
	{
	    return ERROR;
	}
	*e=S->top->data;
	p=S->top;					/* ��ջ����㸳ֵ��p����ͼ�Т� */
	S->top=S->top->next;    /* ʹ��ջ��ָ������һλ��ָ���һ��㣬��ͼ�Т� */
	free(p);                    /* �ͷŽ��p */        
	S->count--;
	return OK;
}

/**************************************************************************************************
* 3) ʹ��ʾ��   ��20201023�汾��
**************************************************************************************************/
#if 0
int main()
{	
	int j;
	//��ʼ��
	if(lStackInit(&linkStack_var) == OK)
	{
		//��ջ
		for(j=1;j<=10;j++)
		{
			lStackPush(&linkStack_var, j);
		}
	}
	//��ӡ
	printf("ջ��Ԫ������Ϊ��");
	lStackPrintfTraverse(linkStack_var);
	//��ջ
	lStackPop(&linkStack_var, &linkStack_elem);
	printf("������ջ��Ԫ�� e=%d\n",linkStack_elem);
	//�գ�
	printf("ջ�շ�%d(1:�� 0:��)\n",lStackEmpty(linkStack_var));
	//ջ��
	lStackGetTop(linkStack_var, &linkStack_elem);
	//����
	printf("ջ��Ԫ�� e=%d ջ�ĳ���Ϊ%d\n", linkStack_elem, lStackLength(linkStack_var));
	//���
	lStackClear(&linkStack_var);
	printf("���ջ��ջ�շ�%d(1:�� 0:��)\n", lStackEmpty(linkStack_var));
	return 0;
}
#endif
