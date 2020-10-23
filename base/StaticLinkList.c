/**************************************************************************************************
* 功能:                              静态链表
*        
* 文件:  StaticLinkList.c
*        
* 说明:  
*        
* 作者:  日南方  10/22/2020
**************************************************************************************************/

#define __STATICLINKLIST_C__
/* ------------------------------------------- include ----------------------------------------- */
#include "StaticLinkList.h"

/* ------------------------------------- define/typedef/enum ----------------------------------- */


/* ------------------------------------------- variable ---------------------------------------- */


/* -------------------------------------------static funtion ----------------------------------------- */
#ifdef STATIC_FUNCTION
#endif	/* STATIC_FUNCTION */
//打印一个元素
static slListStatus slListVisit(slListElemType c);

/* -------------------------------------------global funtion ----------------------------------------- */
#ifdef GLOBAL_FUNCTION
#endif	/* GLOBAL_FUNCTION */
/**************************************************************************************************
*	 汇总
* 1）打印函数   （这里的打印逻辑和其他的有点不一样）
* 2）内部操作函数
* 3) 使用示例   （20201022版本）
**************************************************************************************************
*1） 打印函数
**************************************************************************************************/
//打印一个元素
static slListStatus slListVisit(slListElemType c)
{
    printf(" %c  ",c);
    return OK;
}
void slListPrintfTraverse(StaticLinkList L)
{
    int j=0;
    int i=L[SLLISTMAXSIZE-1].cur;
    while(i)
    {
    	slListVisit(L[i].data);
		i=L[i].cur;
		j++;
    }
    printf("\n");
}
/**************************************************************************************************
*2） 内部操作函数
**************************************************************************************************/
/* 将一维数组space中各分量链成一个备用链表，space[0].cur为头指针，"0"表示空指针 */
slListStatus slListInit(StaticLinkList space) 
{
	int i;
	for (i=0; i<SLLISTMAXSIZE-1; i++)  
	{
		space[i].cur = i+1;
	}
	space[SLLISTMAXSIZE-1].cur = 0; /* 目前静态链表为空，最后一个元素的cur为0 */
	return OK;
}
//清空
slListStatus slListClear(StaticLinkList space) 
{
	int i;
	for (i=0; i<SLLISTMAXSIZE-1; i++)  
	{
		space[i].cur = i+1;
	}
	space[SLLISTMAXSIZE-1].cur = 0; /* 目前静态链表为空，最后一个元素的cur为0 */
	return OK;
}
//空？
slListStatus slListEmpty (StaticLinkList space)
{
	int32_t i = space[0].cur;
	if (i)
	{
		return FALSE;
	}
	return TRUE; 
}

/* 若备用空间链表非空，则返回分配的结点下标，否则返回0 */
int slList_Malloc(StaticLinkList space) 
{ 
	int i = space[0].cur;           		/* 当前数组第一个元素的cur存的值 */
	                                		/* 就是要返回的第一个备用空闲的下标 */
	if (space[0].cur)
	{
	    space[0].cur = space[i].cur;       /* 由于要拿出一个分量来使用了， */
	}                                        /* 所以我们就得把它的下一个 */
	                                        /* 分量用来做备用 */
	return i;
}

/*  将下标为k的空闲结点回收到备用链表 */
void slList_Free(StaticLinkList space, int k) 
{  
    space[k].cur = space[0].cur;    /* 把第一个元素的cur值赋给要删除的分量cur */
    space[0].cur = k;               /* 把要删除的分量下标赋值给第一个元素的cur */
}

/* 初始条件：静态链表L已存在。操作结果：返回L中数据元素个数 */
int slListLength(StaticLinkList L)
{
	//j是计数，i是扫描游标
    int j = 0;
    int i = L[SLLISTMAXSIZE-1].cur;
	//扫描到0就是到底了
    while(i)
    {
        i=L[i].cur;
        j++;
    }
    return j;
}

/*  在L中第i个元素之前插入新的数据元素e   */
slListStatus slListInsert(StaticLinkList L, int i, slListElemType e)   
{  
	//j是插入的分配空间,k是扫描游标,l是临时变量
    int j, k, l; 
	//扫描油表定格在头结点
    k = SLLISTMAXSIZE - 1;   /* 注意k首先是最后一个元素的下标 */
	//插入位置错误
	if (i < 1 || i > slListLength(L) + 1)   
    {
        return ERROR;   
    }
	//j != 0  及是分配成功
	j = slList_Malloc(L);   /* 获得空闲分量的下标 */
    if (j)   
    {   
		//扫描达到索引位置
		for(l = 1; l <= i - 1; l++)   /* 找到第i个元素之前的位置 */
		{
		   k = L[k].cur;           
		}
		//插入
		L[j].data = e;   /* 将数据赋值给此分量的data */
		L[j].cur = L[k].cur;    /* 把第i个元素之前的cur赋值给新元素的cur */
		L[k].cur = j;           /* 把新元素的下标赋值给第i个元素之前元素的ur */
		return OK;   
    }   
    return ERROR;   
}

/*  删除在L中第i个数据元素   */
slListStatus slListDelete(StaticLinkList L, int i)   
{ 
	//j是插入的分配空间,k是扫描游标
    int j, k;  
	//删除索引位置错误
    if (i < 1 || i > slListLength(L))
    {
        return ERROR;   
    }
	//扫描油表定格在头结点
	k = SLLISTMAXSIZE - 1;   
	//扫描到达索引位置
	for (j = 1; j <= i - 1; j++)   
    {
        k = L[k].cur;   
    }
	//删除
	j = L[k].cur;   
    L[k].cur = L[j].cur;   
    slList_Free(L, j);   
    return OK;   
} 
/**************************************************************************************************
*3） 使用示例
**************************************************************************************************/
#if 0
int main()
{
    slListStatus i;
    //初始化
    i=slListInit(test_ssl);
    printf("初始化L后：L.length=%d\n",slListLength(test_ssl));
	//插入
    i=slListInsert(test_ssl,1,'F');
    i=slListInsert(test_ssl,1,'E');
    i=slListInsert(test_ssl,1,'D');
    i=slListInsert(test_ssl,1,'B');
    i=slListInsert(test_ssl,1,'A');
    printf("\n在L的表头依次插入FEDBA后： L.data=");
    slListPrintfTraverse(test_ssl);
    i=slListInsert(test_ssl,3,'C');
    printf("\n在L的“B”与“D”之间插入“C”后： L.data=");
    slListPrintfTraverse(test_ssl); 
	//删除
    i=slListDelete(test_ssl,1);
    printf("\n在L的删除“A”后：L.data=");
    slListPrintfTraverse(test_ssl); 
    printf("\n");
    //清空
    i = slListClear(test_ssl);
    printf("清空L后：L.length=%d\n", slListLength(test_ssl));
    return 0;
}
#endif


