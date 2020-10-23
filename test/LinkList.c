/**************************************************************************************************
* ����:                              ����
*        
* �ļ�:  LinkList.c
*        
* ˵��:  
*        
* ����:  ���Ϸ�  10/20/2020
**************************************************************************************************/

#define __LINKLIST_C__
/* ------------------------------------------- include ----------------------------------------- */
#include "LinkList.h"
/* ------------------------------------- define/typedef/enum ----------------------------------- */

/* ------------------------------------------- variable ---------------------------------------- */


/* -------------------------------------------static funtion ----------------------------------------- */
#ifdef STATIC_FUNCTION
#endif	/* STATIC_FUNCTION */


/* -------------------------------------------global funtion ----------------------------------------- */
#ifdef GLOBAL_FUNCTION
#endif	/* GLOBAL_FUNCTION */
/**************************************************************************************************
*	 ����
* 1����ӡ����
* 2���ڲ���������������ͷ��㣩
* 3���߼�����	������ͷ��㣩
* 4) ʹ��ʾ����20200601�汾δ���£�
**************************************************************************************************
*1�� ��ӡ����
**************************************************************************************************/
linkStatus linkListVisit(linkElemType c)
{
	Uart_Printf("%s(%d):this data is:%f\n",__MODULE__,__LINE__,c);
	return OK;
}
/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* ������������ζ�L��ÿ������Ԫ����� */
linkStatus linkListPrintTraverse(LinkList L)
{
	LinkList p = L->next;
	while (p)
	{
		linkListVisit(p->data);
		p = p->next;
	}
	return OK;
}
void linkListPrintInversion(LinkList L)
{
	if (L == NULL)
	{
		return;
	}
	linkListPrintInversion(L->next);
	linkListVisit((L)->data);
}

/**************************************************************************************************
*2�� �ڲ��������������ͷ������ڱ�
**************************************************************************************************/
// 	��ʼ��˳�����Ա� 
////�������ͷ���ָ������Ϳ����ˣ���ʼ����æ����һ��ʵ��ı���
////���Ҫע��LinkList��һ��ָ�룬���ڴ�Žṹ���ַ
////LinkList *L �Ƕ���ָ�룬�����Ϊ�������ݵ�ԭ�򣬵�һ���ַ�ǲ�һ���ģ�Ҳ����LinkList *L�ĵ�ַ��ԭ����ͬ
////�ⲿһ��ͷ���Ķ�������LinkList lingklistvar_head�����ݽ�ȥ��&lingklistvar_head��
////Ҳ����˵��LinkList *L,����ָ���ŵ��ǣ�һ��ָ��ĵ�ַ��һ��ָ���ŵ��Ǳ�����ַ
////����˵��L�Ǵ��һ��ָ���ָ��,*L�Ǵ�ű�����ָ��
linkStatus linkListInit(LinkList *L)
{
	//����ռ�
	////(ָ������)malloc(�ռ��С)
	(*L) = (LinkListNode_S *)malloc(sizeof(LinkListNode_S)); /* ����ͷ���,��ʹLָ���ͷ��� */
	if (!(*L)) 							/* �洢����ʧ�� */
	{	
		return ERROR;
	}
	//��ʼ��
	(*L)->next = NULL; /* ָ����Ϊ�� */

	return OK;
}
//�����һ��ָ��Ϳ�����,����Ϊ�˺����汣��һ���Ծ����˶���
linkStatus linkListInitManu()
{
	//����ʼ������һ��ָ��ͱ���������
	linkList_point2_head 				= &linkList_var2_head;
	linkList_point2_head->data 	= 0;
	linkList_point2_head->next 	= NULL;
	
	linkList_point2_1 					= &linkList_var2_1;
	linkList_point2_1->data			= 0;
	linkList_point2_1->next		 	= NULL;

	linkList_point2_2 				= &linkList_var2_head;
	linkList_point2_2->data 	= 0;
	linkList_point2_2->next 	= NULL;
	
	linkList_point2_3 				= &linkList_var2_3;
	linkList_point2_3->data 	= 0;
	linkList_point2_3->next 	= NULL;
	
	linkList_point2_4 				= &linkList_var2_4;
	linkList_point2_4->data 	= 0;
	linkList_point2_4->next 	= NULL;
	
	return OK;
}
/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��ͷ�巨�� */
//��Щ��Ƭ����֧��time����
void linkListInitRandomElementsHeadInsertion(LinkList* L, int n)
{
//	LinkList p;
//	int i;
//	srand(time(0));                         	/* ��ʼ����������� */
//	*L = (LinkListNode_S*)malloc(sizeof(LinkListNode_S));
//	(*L)->next = NULL;                     	 	/*  �Ƚ���һ����ͷ���ĵ����� */
//	for (i = 0; i < n; i++)
//	{
//		p = (LinkListNode_S*)malloc(sizeof(LinkListNode_S)); 	/*  �����½�� */
//		p->data = rand() % 100 + 1;             /*  �������100���ڵ����� */
//		p->next = (*L)->next;
//		(*L)->next = p;							/*  ���뵽��ͷ */
//	}
}
/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��β�巨�� */
void linkListInitRandomElementsTailInsertion(LinkList* L, int n)
{
//	LinkList p, r;
//	int i;
//	srand(time(0));                      /* ��ʼ����������� */
//	*L = (LinkListNode_S*)malloc(sizeof(LinkListNode_S)); /* LΪ�������Ա� */
//	r = *L;                                /* rΪָ��β���Ľ�� */
//	for (i = 0; i < n; i++)
//	{
//		p = (LinkListNode_S*)malloc(sizeof(LinkListNode_S)); /*  �����½�� */
//		p->data = rand() % 100 + 1;           /*  �������100���ڵ����� */
//		r->next = p;                        /* ����β�ն˽���ָ��ָ���½�� */
//		r = p;                            /* ����ǰ���½�㶨��Ϊ��β�ն˽�� */
//	}
//	r->next = NULL;                       /* ��ʾ��ǰ������� */
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
linkStatus linkListEmpty(LinkList L)
{
	if (L->next)
		return FALSE;
	else
		return TRUE;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
//�����������ͷ�ڵ�
linkStatus linkListClear(LinkList* L)
{
	LinkList p, q;
	//pָ���һ����� 
	p = (*L)->next; 
	//û����β         
	while (p)                
	{
		//�ͷź�������Ŀռ�
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;        /* ͷ���ָ����Ϊ�� */
	return OK;
}
linkStatus linkListClearManu(LinkList* L)
{
	(*L)->next = NULL;
	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
int16_t linkListLength(LinkList L)
{
	int i = 0;
	LinkList p = L->next; /* pָ���һ����� */
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* �����������e����L�е�i������Ԫ�ص�ֵ */
linkStatus linkListGetElem(LinkList L, int i, linkElemType* e)
{
	int j;
	LinkList p;			/* ����һ���p */
	p = L->next;		/* ��pָ������L�ĵ�һ����� */
	j = 1;				/*  jΪ������ */
	while (p && j < i)  /* p��Ϊ�ջ��߼�����j��û�е���iʱ��ѭ������ */
	{
		p = p->next;  	/* ��pָ����һ����� */
		++j;
	}
	if (!p || j > i)
	{
		return ERROR;  /*  ��i��Ԫ�ز����� */
	}
	*e = p->data;   	/*  ȡ��i��Ԫ�ص����� */
	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* �������������L�е�1����e�����ϵ������Ԫ�ص�λ�� */
/* ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
int16_t linkListLocateElem(LinkList L, linkElemType e)
{
	int i = 0;
	//ɨ��
	LinkList p = L->next;
	while (p)
	{
		i++;
		if (p->data == e) /* �ҵ�����������Ԫ�� */
			return i;
		p = p->next;
	}

	return 0;
}


/* ��ʼ������˳�����Ա�L�Ѵ���,1��i��ListLength(L)�� */
/* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
linkStatus linkListInsert(LinkList* L, int i, linkElemType e)
{
	int j;
	//p��ɨ��ָ�룬S�ǲ���ָ��
	LinkList p, s;
	//ɨ��
	p = *L;
	j = 1;
	while (p && j < i)    	 			/* Ѱ�ҵ�i����� */
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return ERROR;   				/* ��i��Ԫ�ز����� */
	//����
	s = (LinkListNode_S*)malloc(sizeof(LinkListNode_S));  /*  �����½��(C���Ա�׼����) */
	s->data = e;
	s->next = p->next;      /* ��p�ĺ�̽�㸳ֵ��s�ĺ��  */
	p->next = s;          /* ��s��ֵ��p�ĺ�� */
	return OK;
}
linkStatus linkListInsertManu(LinkList* L, LinkList* node,int i, linkElemType e)
{
	int j;
	LinkList p, s;
	p = *L;
	//��ֹ�¼ӵĽڵ��Ѿ��������е�һ���ڵ�
	while (p)						
	{
		if (p == *node)
		{
			return ERROR;
		}
		p = p->next;
	}
	p = *L;
	j = 1;
	while (p && j < i)    	 			/* Ѱ�ҵ�i����� */
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
	{
		return ERROR;   				/* ��i��Ԫ�ز����� */

	}
	s = *node;  			/*  �����½��(���Ѿ�����õĽڵ�) */
	s->data = e;
	s->next = p->next;      /* ��p�ĺ�̽�㸳ֵ��s�ĺ��  */
	p->next = s;          	/* ��s��ֵ��p�ĺ�� */
	return OK;
}


/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
linkStatus linkListDelete(LinkList* L, int i, linkElemType* e)
{
	int j;
	//p�Ǳ���ָ�룬q�ǲ���ָ���ɾ��ָ��
	LinkList p, q;
	//����
	p = *L;
	j = 1;
	while (p->next && j < i)	/* ����Ѱ�ҵ�i��Ԫ�� */
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i)
		return ERROR;           /* ��i��Ԫ�ز����� */
	//ɾ��
	q = p->next;
	p->next = q->next;			/* ��q�ĺ�̸�ֵ��p�ĺ�� */
	*e = q->data;               /* ��q����е����ݸ�e */
	free(q);                    /* ��ϵͳ���մ˽�㣬�ͷ��ڴ� */
	return OK;
}
linkStatus linkListDeleteManu(LinkList* L, int i, linkElemType* e)
{
	int j;
	//p�Ǳ���ָ�룬q�ǲ���ָ���ɾ��ָ��
	LinkList p, q;
	//����
	p = *L;
	j = 1;
	while (p->next && j < i)	/* ����Ѱ�ҵ�i��Ԫ�� */
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i)
		return ERROR;           /* ��i��Ԫ�ز����� */
	//ɾ��
	q = p->next;
	p->next = q->next;			/* ��q�ĺ�̸�ֵ��p�ĺ�� */
	*e = q->data;               /* ��q����е����ݸ�e */
	q->next = NULL;             /* �ֶ�����Ľڵ�ϵͳ������ */
	return OK;
}
/**************************************************************************************************
*3�� �߼�����������Ĭ��ʹ��free��malloc����������
**************************************************************************************************
* ����:                                   linkListDelx
* ˵��:  	ɾ��ӵ��ͷ���ĵ����������еĵ���x�Ľ��
* ����:  
*		   LinkList *L		
*		int x		
* ��������: 
* ����:  
* ����:  ���Ϸ�  6/20/2020
**************************************************************************************************/
void LinkListDelx(LinkList* L, int x)
{
	//ͷ����ĵ�һ���ڵ�
	LinkList p = (*L)->next;
	linkListDelxRecursion(&p,x);
}
void linkListDelxRecursion(LinkList* L, int x)
{
	LinkList temp;
	if (L == NULL)
	{
		return;
	}
	if((*L)->data == x)
	{
		temp = (*L)->next;
		*L = (*L)->next;
		free(temp);
		//temp->next = NULL;  //�ֶ��������������
		linkListDelxRecursion(L, x);
	}else{
		*L = (*L)->next;
	 	linkListDelxRecursion(L, x);
	}
}	
void LinkListDelx1(LinkList *L, int x)
{
	//now��ɨ��ڵ�
	//prev��now��ǰ���ڵ�
	//temp����ɾ������
	LinkList prev, now, temp;
	prev = (*L);
	now  = prev->next;
	
	while (now != NULL)
	{
		if (now->data == x)
		{
			//ɾ����������һ���ڵ�
			temp = now;
			now = now->next;
			prev->next = now;
			free(temp);
			//temp->next = NULL; 	//�ֶ��������������
		}else{
			//��һ���ڵ�
			prev = now;
			now  = now->next;
		}
	}
}

/**************************************************************************************************
* ����:                                   del_minx_slList
* ˵��:  	ɾ������������Сֵ��ֻɾ��һ������ͷ���
* ����:  
*		   LinkList *L		
* ��������: 
* ����:  
* ����:  ���Ϸ�  6/20/2020
**************************************************************************************************/
void LinkListDelMin(LinkList L)
{
	//now��ɨ��ڵ�,temp����С�ı���ڵ�
	//prev��now��ǰ���ڵ�,temp_prev��temp��ǰ���ڵ�
	LinkList prev, now, temp, temp_prev;
	////ǰ��
	prev = L;
	temp_prev = L;
	////��ǰ
	now = L->next;
	temp = L->next;
	while(now != NULL)
	{
		//������Сֵ�Ľڵ�
		if(now->data <= temp->data)
		{
			temp = now;
			temp_prev = prev;
		}
		//ɨ��
		prev = now;
		now = now->next;
	}
	//ɾ��
	temp_prev->next = temp->next;
	free(temp);
	//temp->next = NULL;
}
/**************************************************************************************************
* ����:                                   linkListInversion
* ˵��:  	��������ʹ��ͷ�巨�ı�˳��
* ����:  
*		   LinkList * L		
* ��������: 
* ����:  
* ����:  ���Ϸ�  6/20/2020
**************************************************************************************************/
void linkListInversion(LinkList L)
{
	//head��ͷ���,now��ɨ��ڵ�,temp��ȡɨ����Ľڵ�
	LinkList head, now, temp;
	//��ͷ���ճ���
	head = L;
	head->next = NULL;
	//now��ɨ��ָ�룬temp��ȡ��ɨ����Ľڵ�
	now  = L->next;
	while (now != NULL)
	{	
		temp = now;
		now = now->next;
		//ͷ�巨������������
		temp->next = head->next;
		head->next = temp;
	}
}
/**************************************************************************************************
* ����:                                   linkListDelMin2Max
* ˵��:  
* ����:  
*		   LinkList *L		
*		int min		
*		int max		
* ��������: 
* ����:  
* ����:  ���Ϸ�  10/20/2020
**************************************************************************************************/
void linkListDelMin2Max(LinkList L, int min, int max)
{
	//now��ɨ��ָ�룬prev��now��ǰ��
	LinkList prev, now;
	//��ͷ��㣬nowָ���һ���ڵ�
	prev = L;
	now = L->next;
	//ɨ��
	while (now != NULL)
	{
		//����������ɾ����������һ���ڵ�
		if(min < now->data && now->data < max)
		{
			prev->next = now->next;
			free(now);
			//now->next =NULL;
			now = prev->next;
		}else{
		//������,����һ���ڵ�
			prev = now;
			now = now->next;
		}
	}
}

/**************************************************************************************************
* 4��ʹ��ʾ��
**************************************************************************************************/

#if 0
int main()
{        
	LinkList L;
	ElemType e;
	Status i;
	int j, k;
	i = InitList(&L);
	printf("��ʼ��L��ListLength(L)=%d\n", ListLength(L));
	for (j = 1;j <= 5;j++)
		i = ListInsert(&L, 1, j);
	printf("��L�ı�ͷ���β���1��5��L.data=");
	ListTraverse(L);

	printf("ListLength(L)=%d \n", ListLength(L));
	i = ListEmpty(L);
	printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);

	i = ClearList(&L);
	printf("���L��ListLength(L)=%d\n", ListLength(L));
	i = ListEmpty(L);
	printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);

	for (j = 1;j <= 10;j++)
		ListInsert(&L, j, j);
	printf("��L�ı�β���β���1��10��L.data=");
	ListTraverse(L);

	printf("ListLength(L)=%d \n", ListLength(L));

	ListInsert(&L, 1, 0);
	printf("��L�ı�ͷ����0��L.data=");
	ListTraverse(L);
	printf("ListLength(L)=%d \n", ListLength(L));

	GetElem(L, 5, &e);
	printf("��5��Ԫ�ص�ֵΪ��%d\n", e);
	for (j = 3;j <= 4;j++)
	{
		k = LocateElem(L, j);
		if (k)
			printf("��%d��Ԫ�ص�ֵΪ%d\n", k, j);
		else
			printf("û��ֵΪ%d��Ԫ��\n", j);
	}


	k = ListLength(L); /* kΪ�� */
	for (j = k + 1;j >= k;j--)
	{
		i = ListDelete(&L, j, &e); /* ɾ����j������ */
		if (i == ERROR)
			printf("ɾ����%d������ʧ��\n", j);
		else
			printf("ɾ����%d����Ԫ��ֵΪ��%d\n", j, e);
	}
	printf("�������L��Ԫ�أ�");
	ListTraverse(L);

	j = 5;
	ListDelete(&L, j, &e); /* ɾ����5������ */
	printf("ɾ����%d����Ԫ��ֵΪ��%d\n", j, e);

	printf("�������L��Ԫ�أ�");
	ListTraverse(L);

	i = ClearList(&L);
	printf("\n���L��ListLength(L)=%d\n", ListLength(L));
	CreateListHead(&L, 20);
	printf("���崴��L��Ԫ��(ͷ�巨)��");
	ListTraverse(L);

	i = ClearList(&L);
	printf("\nɾ��L��ListLength(L)=%d\n", ListLength(L));
	CreateListTail(&L, 20);
	printf("���崴��L��Ԫ��(β�巨)��");
	ListTraverse(L);

	printf("\n\n�ڵ����ɸ�λ�ò���100��");
	ListInsert(&L, 3, 100);
	ListInsert(&L, 4, 100);
	ListInsert(&L, 5, 100);
	ListInsert(&L, 10, 100);
	ListTraverse(L);
	printf("ʹ���Լ�д��û��ͷ��㣬ɾ��ָ��xΪ100��Ч����");
	del_x_slList(L->next, 100);
	ListTraverse(L);

	printf("\n\n�ڵ����ɸ�λ�ò���100��");
	ListInsert(&L, 3, 100);
	ListInsert(&L, 4, 100);
	ListInsert(&L, 5, 100);
	ListInsert(&L, 10, 100);
	ListTraverse(L);
	printf("ʹ���Լ�д��û��ͷ��㣬ɾ��ָ��xΪ100��Ч����");
	del_x_slList1(L, 100);
	ListTraverse(L);

	printf("\n\n�ڵ����ɸ�λ�ò���100��");
	ListInsert(&L, 3, 100);
	ListInsert(&L, 4, 100);
	ListInsert(&L, 5, 100);
	ListInsert(&L, 10, 100);
	ListTraverse(L);
	printf("ʹ���Լ�д��û��ͷ��㣬ɾ��ָ��xΪ100��Ч����");
	del_x_slList2(L, 100);
	ListTraverse(L);


	while (1);
    return 0;
}
#endif

