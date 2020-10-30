/**************************************************************************************************
* 功能:                              链表
*        
* 文件:  LinkList.c
*        
* 说明:  
*        
* 作者:  日南方  10/20/2020
**************************************************************************************************/

#define __LINKLIST_C__
/* ------------------------------------------- include ----------------------------------------- */
#include "LinkList.h"
/* ------------------------------------- define/typedef/enum ----------------------------------- */

/* ------------------------------------------- variable ---------------------------------------- */


/* -------------------------------------------static funtion ----------------------------------------- */
#ifdef STATIC_FUNCTION
#endif	/* STATIC_FUNCTION */

static linkStatus linkListVisit (linkElemType c);					//打印元素
static void linkListPrintInversionRecursion(LinkList L);
static void linkListDelxRecursion(LinkList* L, int x);

/* -------------------------------------------global funtion ----------------------------------------- */
#ifdef GLOBAL_FUNCTION
#endif	/* GLOBAL_FUNCTION */
/**************************************************************************************************
*	 汇总
* 1）打印函数
* 2）内部操作函数	（都含头结点，手动申请变量就（初始化，插入，删除，清空）不同）
* 3）高级函数		（都含头结点）
* 4) 使用示例		（20201022版本内部操作函数更新）
**************************************************************************************************
*1） 打印函数
**************************************************************************************************/
static linkStatus linkListVisit(linkElemType c)
{
	//注意 linkElemType 的类型
	//Uart_Printf("%s(%d):this data is:%d\n",__MODULE__,__LINE__,c);
	printf("this data is : %d \n", c);
	return OK;
}
/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
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
//逆序打印，剔除头结点
void linkListPrintInversion(LinkList L)
{
	L = L->next;
	linkListPrintInversionRecursion(L);
}
/**************************************************************************************************
*2） 内部操作函数，这个头结点是哨兵
**************************************************************************************************/
// 	初始化顺序线性表 
////用链表的头结点指针过来就可以了，初始化帮忙申请一个实体的变量
////这边要注意LinkList是一阶指针，用于存放结构体地址
////LinkList *L 是二阶指针，这边因为函数传递的原因，第一层地址是不一样的，也就是LinkList *L的地址和原来不同
////外部一个头结点的定义如下LinkList lingklistvar_head，传递进去是&lingklistvar_head；
////也就是说，LinkList *L,二阶指针存放的是，一阶指针的地址，一阶指针存放的是变量地址
////就是说，L是存放一阶指针的指针,*L是存放变量的指针
linkStatus linkListInit(LinkList *L)
{
	//申请空间
	////(指针类型)malloc(空间大小)
	(*L) = (LinkListNode_S *)malloc(sizeof(LinkListNode_S)); /* 产生头结点,并使L指向此头结点 */
	if (!(*L)) 							/* 存储分配失败 */
	{	
		return ERROR;
	}
	//初始化
	(*L)->next = NULL; /* 指针域为空 */

	return OK;
}
//这个用一阶指针就可以了,但是为了和上面保存一致性就用了二阶
linkStatus linkListAssign()
{
	//结点初始化，将一阶指针和变量连起来，要十分注意名字
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
/*  随机产生n个元素的值，建立带表头结点的单链线性表L（头插法） */
//有些单片机不支持time函数
void linkListRandomHeadInsertion(LinkList* L, int n)
{
//	LinkList p;
//	int i;
//	srand(time(0));                         	/* 初始化随机数种子 */
//	*L = (LinkListNode_S*)malloc(sizeof(LinkListNode_S));
//	(*L)->next = NULL;                     	 	/*  先建立一个带头结点的单链表 */
//	for (i = 0; i < n; i++)
//	{
//		p = (LinkListNode_S*)malloc(sizeof(LinkListNode_S)); 	/*  生成新结点 */
//		p->data = rand() % 100 + 1;             /*  随机生成100以内的数字 */
//		p->next = (*L)->next;
//		(*L)->next = p;							/*  插入到表头 */
//	}
}
/*  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法） */
void linkListRandomTailInsertion(LinkList* L, int n)
{
//	LinkList p, r;
//	int i;
//	srand(time(0));                      /* 初始化随机数种子 */
//	*L = (LinkListNode_S*)malloc(sizeof(LinkListNode_S)); /* L为整个线性表 */
//	r = *L;                                /* r为指向尾部的结点 */
//	for (i = 0; i < n; i++)
//	{
//		p = (LinkListNode_S*)malloc(sizeof(LinkListNode_S)); /*  生成新结点 */
//		p->data = rand() % 100 + 1;           /*  随机生成100以内的数字 */
//		r->next = p;                        /* 将表尾终端结点的指针指向新结点 */
//		r = p;                            /* 将当前的新结点定义为表尾终端结点 */
//	}
//	r->next = NULL;                       /* 表示当前链表结束 */
}

/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
linkStatus linkListEmpty(LinkList L)
{
	if (L->next)
		return FALSE;
	else
		return TRUE;
}

/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
//输入的是链表头节点
void linkListClear(LinkList* L)
{
	LinkList p, q;
	//p指向第一个结点 
	p = (*L)->next; 
	//没到表尾         
	while (p)                
	{
		//释放后面链表的空间
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;        /* 头结点指针域为空 */
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

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int16_t linkListLength(LinkList L)
{
	int i = 0;
	LinkList p = L->next; /* p指向第一个结点 */
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值 */
linkStatus linkListGetElem(LinkList L, int i, linkElemType* e)
{
	int j;
	LinkList p;			/* 声明一结点p */
	p = L->next;		/* 让p指向链表L的第一个结点 */
	j = 1;				/*  j为计数器 */
	while (p && j < i)  /* p不为空或者计数器j还没有等于i时，循环继续 */
	{
		p = p->next;  	/* 让p指向下一个结点 */
		++j;
	}
	if (!p || j > i)
	{
		return ERROR;  /*  第i个元素不存在 */
	}
	*e = p->data;   	/*  取第i个元素的数据 */
	return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
int16_t linkListLocateElem(LinkList L, linkElemType e)
{
	int i = 0;
	//扫描
	LinkList p = L->next;
	while (p)
	{
		i++;
		if (p->data == e) /* 找到这样的数据元素 */
			return i;
		p = p->next;
	}

	return 0;
}


/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
linkStatus linkListInsert(LinkList* L, int i, linkElemType e)
{
	int j;
	//p是扫描指针，S是操作指针
	LinkList p, s;
	//扫描
	p = *L;
	j = 1;
	while (p && j < i)    	 			/* 寻找第i个结点 */
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return ERROR;   				/* 第i个元素不存在 */
	//插入
	s = (LinkListNode_S*)malloc(sizeof(LinkListNode_S));  /*  生成新结点(C语言标准函数) */
	s->data = e;
	s->next = p->next;      /* 将p的后继结点赋值给s的后继  */
	p->next = s;          /* 将s赋值给p的后继 */
	return OK;
}
linkStatus linkListInsertManu(LinkList L, LinkList node,int i, linkElemType e)
{
	int j;
	//p是当前指针，S是加入指针
	LinkList p, s;
	p = L;
	//防止新加的节点已经是链表中的一个节点
	while (p)						
	{
		if (p == node)
		{
			return ERROR;
		}
		p = p->next;
	}
	//指向索引结点
	p = L;
	j = 1;
	while (p && j < i)    	 			/* 寻找第i个结点 */
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
	{
		return ERROR;   				/* 第i个元素不存在 */

	}
	//插入
	s = node;  			/*  生成新结点(用已经申请好的节点) */
	s->data = e;
	s->next = p->next;      /* 将p的后继结点赋值给s的后继  */
	p->next = s;          	/* 将s赋值给p的后继 */
	return OK;
}


/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
linkStatus linkListDelete(LinkList* L, int i, linkElemType* e)
{
	int j;
	//p是遍历指针，q是操作指针既删除指针
	LinkList p, q;
	//遍历
	p = *L;
	j = 1;
	while (p->next && j < i)	/* 遍历寻找第i个元素 */
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i)
		return ERROR;           /* 第i个元素不存在 */
	//删除
	q = p->next;
	p->next = q->next;			/* 将q的后继赋值给p的后继 */
	*e = q->data;               /* 将q结点中的数据给e */
	free(q);                    /* 让系统回收此结点，释放内存 */
	return OK;
}
linkStatus linkListDeleteManu(LinkList L, int i, linkElemType* e)
{
	int j;
	//p是遍历指针，q是操作指针既删除指针
	LinkList p, q;
	//遍历
	p = L;
	j = 1;
	while (p->next && j < i)	/* 遍历寻找第i个元素 */
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i)
		return ERROR;           /* 第i个元素不存在 */
	//删除
	q = p->next;
	p->next = q->next;			/* 将q的后继赋值给p的后继 */
	*e = q->data;               /* 将q结点中的数据给e */
	q->next = NULL;             /* 手动申请的节点系统不回收 */
	return OK;
}
/**************************************************************************************************
*3） 高级操作函数，默认使用free和malloc来操作变量
**************************************************************************************************
* 函数:                                   linkListDelx
* 说明:  	删除拥有头结点的单链表中所有的等于x的结点
* 输入:  
*		   LinkList *L		
*		int x		
* 关联变量: 
* 返回:  
* 作者:  日南方  6/20/2020
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
		//temp->next = NULL;  //手动申请变量不回收
		linkListDelxRecursion(L, x);
	}else{
		*L = (*L)->next;
	 	linkListDelxRecursion(L, x);
	}
}	
void LinkListDelx(LinkList* L, int x)
{
	//头结点后的第一个节点
	LinkList p = (*L)->next;
	linkListDelxRecursion(&p, x);
}
void LinkListDelx1(LinkList L, int x)
{
	//now是扫描节点
	//prev是now的前驱节点
	//temp辅助删除操作
	LinkList prev , now , temp ;
	prev = L;
	now = prev->next;
	while (now != NULL)
	{
		if (now->data == x)
		{
			//删除，并切下一个节点
			temp = now;
			now = now->next;
			prev->next = now;
			free(temp);
			//temp->next = NULL; 	//手动申请变量不回收
		}else{
			//下一个节点
			prev = now;
			now  = now->next;
		}
	}
}

/**************************************************************************************************
* 函数:                                   del_minx_slList
* 说明:  	删除单链表中最小值，只删除一个，含头结点
* 输入:  
*		   LinkList *L		
* 关联变量: 
* 返回:  
* 作者:  日南方  6/20/2020
**************************************************************************************************/
void LinkListDelMin(LinkList L)
{
	//now是扫描节点,temp是最小的保存节点
	//prev是now的前驱节点,temp_prev是temp的前驱节点
	LinkList prev, now, temp, temp_prev;
	////前驱
	prev = L;
	temp_prev = L;
	////当前
	now = L->next;
	temp = L->next;
	while(now != NULL)
	{
		//保存最小值的节点
		if(now->data <= temp->data)
		{
			temp = now;
			temp_prev = prev;
		}
		//扫描
		prev = now;
		now = now->next;
	}
	//删除
	temp_prev->next = temp->next;
	free(temp);
	//temp->next = NULL;
}
/**************************************************************************************************
* 函数:                                   linkListInversion
* 说明:  	逆序单链表，使用头插法改变顺序
* 输入:  
*		   LinkList * L		
* 关联变量: 
* 返回:  
* 作者:  日南方  6/20/2020
**************************************************************************************************/
void linkListInversion(LinkList L)
{
	//head是头结点,now是扫描节点,temp是取扫描过的节点
	LinkList head, now, temp;
	//把头结点空出来
	head = L;
	head->next = NULL;
	//now是扫描指针，temp是取出扫描过的节点
	now  = L->next;
	while (now != NULL)
	{	
		temp = now;
		now = now->next;
		//头插法，来进行逆序
		temp->next = head->next;
		head->next = temp;
	}
}
/**************************************************************************************************
* 函数:                                   linkListDelMin2Max
* 说明:  
* 输入:  
*		   LinkList *L		
*		int min		
*		int max		
* 关联变量: 
* 返回:  
* 作者:  日南方  10/20/2020
**************************************************************************************************/
void linkListDelMin2Max(LinkList L, int min, int max)
{
	//now是扫描指针，prev是now的前驱
	LinkList prev = NULL, now = NULL;
	//含头结点，now指向第一个节点
	prev = L;
	now = L->next;
	//扫描
	while (now != NULL)
	{
		//满足条件，删除，并切下一个节点
		if(min < now->data && now->data < max)
		{
			prev->next = now->next;
			free(now);
			//now->next =NULL;
			now = prev->next;
		}else{
		//不满足,切下一个节点
			prev = now;
			now = now->next;
		}
	}
}

/**************************************************************************************************
* 4）使用示例
**************************************************************************************************/

#if 0
int main()
{
	//外部索引逻辑是1-N
	//这是linkElemType为int下的示例
	int  i,length, index;
	linkElemType elem;
	linkStatus status;
	//自动申请变量空间的示例
	//初始化
	printf("************自动申请变量空间的示例***********************\n");
	status = linkListInit(&linkList_point1_head);
	printf("初始化L状态%d(1:成功 0:失败)\n", status);
	//头插
	for (i = 1;i <= 5;i++)
	{
		status = linkListInsert(&linkList_point1_head, 1, i);
	}
	printf("在L的表头依次插入1～5后,打印结果是：\n");
	linkListPrintTraverse(linkList_point1_head);
	printf("打印结束\n");
	//长度，清空，空？
	length = linkListLength(linkList_point1_head);
	printf("ListLength(L)=%d \n", length);
	status = linkListEmpty(linkList_point1_head);
	printf("L是否空：status=%d(1:是 0:否)\n", status);
	linkListClear(&linkList_point1_head);
	status = linkListEmpty(linkList_point1_head);
	printf("清空L后是否空：status=%d(1:是 0:否)\n", status);
	//尾插
	for (i = 1;i <= 20;i=i+2)
	{
		linkListInsert(&linkList_point1_head, linkListLength(linkList_point1_head)+1, i);
	}
	linkListInsert(&linkList_point1_head, linkListLength(linkList_point1_head) + 1, 7);
	linkListInsert(&linkList_point1_head, linkListLength(linkList_point1_head) + 1, 7);
	printf("在L的表尾依次插入1～10后，打印结果是：\n");
	linkListPrintTraverse(linkList_point1_head);
	printf("打印结束\n");
	//删除引索对应值
	status = linkListDelete(&linkList_point1_head, 3, &elem);
	printf("删除第3个数据%d\n", elem);
	printf("逆序打印，打印结果是：\n");
	linkListPrintInversion(linkList_point1_head);
	printf("打印结束\n");
	//提取索引对应值
	linkListGetElem(linkList_point1_head, 5, &elem);
	printf("提取第5个元素的值为：%d\n",elem);
	//搜索链表值，返回对应索引
	printf("搜索值为3和4：  ");
	for (i = 3;i <= 4;i++)
	{
		index = linkListLocateElem(linkList_point1_head, i);
		if (index)
			printf("第%d个元素的值为%d  ", index, i);
		else
			printf("没有值为%d的元素   ", i);
	}
	printf("\n");

	//手动申请变量的函数示例
	printf("\n************手动申请变量空间的示例***********************\n");
	//初始化，要十分主要链接变量的名字
	linkListInitManu();
	linkListInsertManu(linkList_point2_head, linkList_point2_1, 1, 5);
	linkListInsertManu(linkList_point2_head, linkList_point2_2, 1, 100);
	linkListInsertManu(linkList_point2_head, linkList_point2_3, 1, 24);
	linkListInsertManu(linkList_point2_head, linkList_point2_4, 1, 24);
	//插入错误
	linkListInsertManu(linkList_point2_head, linkList_point2_1, 1, 100);
	//打印
	linkListPrintTraverse(linkList_point2_head);
	printf("打印结束\n");
	linkListDeleteManu(linkList_point2_head,2,&elem);
	printf("删除第2个数据%d\n", elem);
	linkListClearManu(linkList_point2_head);
	linkListPrintTraverse(linkList_point2_head);
	printf("打印结束\n");
	printf("************内部的基础操作演示完毕***********************\n");
	while (1);
    return 0;
}
#endif

