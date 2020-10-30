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

static linkStatus linkListVisit (linkElemType c);					//��ӡԪ��
static void linkListPrintInversionRecursion(LinkList L);
static void linkListDelxRecursion(LinkList* L, int x);

/* -------------------------------------------global funtion ----------------------------------------- */
#ifdef GLOBAL_FUNCTION
#endif	/* GLOBAL_FUNCTION */
/**************************************************************************************************
*	 ����
* 1����ӡ����
* 2���ڲ���������	������ͷ��㣬�ֶ���������ͣ���ʼ�������룬ɾ������գ���ͬ��
* 3���߼�����		������ͷ��㣩
* 4) ʹ��ʾ��		��20201022�汾�ڲ������������£�
**************************************************************************************************
*1�� ��ӡ����
**************************************************************************************************/
static linkStatus linkListVisit(linkElemType c)
{
	//ע�� linkElemType ������
	//Uart_Printf("%s(%d):this data is:%d\n",__MODULE__,__LINE__,c);
	printf("this data is : %d \n", c);
	return OK;
}
/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* ������������ζ�L��ÿ������Ԫ����� */
void linkListPrintTraverse(LinkList L)
{
	LinkList p = L->next;
	while (p)
	{
		linkListVisit(p->data);
		p = p->next;
	}
}
static void linkListPrintInversionRecursion(LinkList L)
{
	if (L == NULL)
	{
		return;
	}
	linkListPrintInversionRecursion(L->next);
	linkListVisit((L)->data);
}
//�����ӡ���޳�ͷ���
void linkListPrintInversion(LinkList L)
{
	L = L->next;
	linkListPrintInversionRecursion(L);
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
linkStatus linkListAssign()
{
	//����ʼ������һ��ָ��ͱ�����������Ҫʮ��ע������
	linkList_point2_head 			= &linkList_var2_head;
	linkList_point2_head->data 		= 0;
	linkList_point2_head->next 		= NULL;
	
	linkList_point2_1 				= &linkList_var2_1;
	linkList_point2_1->data			= 0;
	linkList_point2_1->next		 	= NULL;

	linkList_point2_2 				= &linkList_var2_2;
	linkList_point2_2->data 		= 0;
	linkList_point2_2->next 		= NULL;
	
	linkList_point2_3 				= &linkList_var2_3;
	linkList_point2_3->data 		= 0;
	linkList_point2_3->next 		= NULL;
	
	linkList_point2_4 				= &linkList_var2_4;
	linkList_point2_4->data 		= 0;
	linkList_point2_4->next 		= NULL;
	
	return OK;
}
/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��ͷ�巨�� */
//��Щ��Ƭ����֧��time����
void linkListRandomHeadInsertion(LinkList* L, int n)
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
void linkListRandomTailInsertion(LinkList* L, int n)
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
void linkListClear(LinkList* L)
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
}
void linkListClearManu(LinkList L)
{
	if (L == NULL)
	{
		return;
	}
	linkListClearManu(L->next);
	L->next = NULL;
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
linkStatus linkListInsertManu(LinkList L, LinkList node,int i, linkElemType e)
{
	int j;
	//p�ǵ�ǰָ�룬S�Ǽ���ָ��
	LinkList p, s;
	p = L;
	//��ֹ�¼ӵĽڵ��Ѿ��������е�һ���ڵ�
	while (p)						
	{
		if (p == node)
		{
			return ERROR;
		}
		p = p->next;
	}
	//ָ���������
	p = L;
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
	//����
	s = node;  			/*  �����½��(���Ѿ�����õĽڵ�) */
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
linkStatus linkListDeleteManu(LinkList L, int i, linkElemType* e)
{
	int j;
	//p�Ǳ���ָ�룬q�ǲ���ָ���ɾ��ָ��
	LinkList p, q;
	//����
	p = L;
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
static void linkListDelxRecursion(LinkList* L, int x)
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
void LinkListDelx(LinkList* L, int x)
{
	//ͷ����ĵ�һ���ڵ�
	LinkList p = (*L)->next;
	linkListDelxRecursion(&p, x);
}
void LinkListDelx1(LinkList L, int x)
{
	//now��ɨ��ڵ�
	//prev��now��ǰ���ڵ�
	//temp����ɾ������
	LinkList prev , now , temp ;
	prev = L;
	now = prev->next;
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
	LinkList prev = NULL, now = NULL;
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
	//�ⲿ�����߼���1-N
	//����linkElemTypeΪint�µ�ʾ��
	int  i,length, index;
	linkElemType elem;
	linkStatus status;
	//�Զ���������ռ��ʾ��
	//��ʼ��
	printf("************�Զ���������ռ��ʾ��***********************\n");
	status = linkListInit(&linkList_point1_head);
	printf("��ʼ��L״̬%d(1:�ɹ� 0:ʧ��)\n", status);
	//ͷ��
	for (i = 1;i <= 5;i++)
	{
		status = linkListInsert(&linkList_point1_head, 1, i);
	}
	printf("��L�ı�ͷ���β���1��5��,��ӡ����ǣ�\n");
	linkListPrintTraverse(linkList_point1_head);
	printf("��ӡ����\n");
	//���ȣ���գ��գ�
	length = linkListLength(linkList_point1_head);
	printf("ListLength(L)=%d \n", length);
	status = linkListEmpty(linkList_point1_head);
	printf("L�Ƿ�գ�status=%d(1:�� 0:��)\n", status);
	linkListClear(&linkList_point1_head);
	status = linkListEmpty(linkList_point1_head);
	printf("���L���Ƿ�գ�status=%d(1:�� 0:��)\n", status);
	//β��
	for (i = 1;i <= 20;i=i+2)
	{
		linkListInsert(&linkList_point1_head, linkListLength(linkList_point1_head)+1, i);
	}
	linkListInsert(&linkList_point1_head, linkListLength(linkList_point1_head) + 1, 7);
	linkListInsert(&linkList_point1_head, linkListLength(linkList_point1_head) + 1, 7);
	printf("��L�ı�β���β���1��10�󣬴�ӡ����ǣ�\n");
	linkListPrintTraverse(linkList_point1_head);
	printf("��ӡ����\n");
	//ɾ��������Ӧֵ
	status = linkListDelete(&linkList_point1_head, 3, &elem);
	printf("ɾ����3������%d\n", elem);
	printf("�����ӡ����ӡ����ǣ�\n");
	linkListPrintInversion(linkList_point1_head);
	printf("��ӡ����\n");
	//��ȡ������Ӧֵ
	linkListGetElem(linkList_point1_head, 5, &elem);
	printf("��ȡ��5��Ԫ�ص�ֵΪ��%d\n",elem);
	//��������ֵ�����ض�Ӧ����
	printf("����ֵΪ3��4��  ");
	for (i = 3;i <= 4;i++)
	{
		index = linkListLocateElem(linkList_point1_head, i);
		if (index)
			printf("��%d��Ԫ�ص�ֵΪ%d  ", index, i);
		else
			printf("û��ֵΪ%d��Ԫ��   ", i);
	}
	printf("\n");

	//�ֶ���������ĺ���ʾ��
	printf("\n************�ֶ���������ռ��ʾ��***********************\n");
	//��ʼ����Ҫʮ����Ҫ���ӱ���������
	linkListInitManu();
	linkListInsertManu(linkList_point2_head, linkList_point2_1, 1, 5);
	linkListInsertManu(linkList_point2_head, linkList_point2_2, 1, 100);
	linkListInsertManu(linkList_point2_head, linkList_point2_3, 1, 24);
	linkListInsertManu(linkList_point2_head, linkList_point2_4, 1, 24);
	//�������
	linkListInsertManu(linkList_point2_head, linkList_point2_1, 1, 100);
	//��ӡ
	linkListPrintTraverse(linkList_point2_head);
	printf("��ӡ����\n");
	linkListDeleteManu(linkList_point2_head,2,&elem);
	printf("ɾ����2������%d\n", elem);
	linkListClearManu(linkList_point2_head);
	linkListPrintTraverse(linkList_point2_head);
	printf("��ӡ����\n");
	printf("************�ڲ��Ļ���������ʾ���***********************\n");
	while (1);
    return 0;
}
#endif

