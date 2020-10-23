
/**************************************************************************************************
* 功能:                              sqList
*        
* 文件:   sqList.c
*        
* 说明: 使用数组作为单链表 
*        
* 作者:  日南方  10/19/2020
**************************************************************************************************/

#define __SQLIST_C__
/* ------------------------------------------- include ----------------------------------------- */
#include "sqList.h"
/* ------------------------------------- define/typedef/enum ----------------------------------- */

/* ------------------------------------------- variable ---------------------------------------- */


/* -------------------------------------------static funtion ----------------------------------------- */
#ifdef STATIC_FUNCTION
#endif	/* STATIC_FUNCTION */
//打印一个元素
static sqStatus sqVisit(sqElemType c);

/* -------------------------------------------global funtion ----------------------------------------- */
#ifdef GLOBAL_FUNCTION
#endif	/* GLOBAL_FUNCTION */
/**************************************************************************************************
*	 汇总
* 1）打印函数
* 2）内部操作函数
* 3）高级函数，要注意最后返回的长度是否正确
* 4) 有序表的高级函数
* 5）特定任务（数组作为输入参数）
* 6) 使用示例（20200601版本未更新）
**************************************************************************************************
*1） 修改函数
**************************************************************************************************/
//打印一个数组单链表的值
static sqStatus sqVisit(sqElemType c)
{
		//选定打印的函数
		//Uart_Printf("this fifo[i] data is %d\n",__MODULE__,__LINE__,c);
    return OK;
}
/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
sqStatus sqListPrintTraverse(SqList L)
{
	int i;
    for(i=0;i<L.length;i++)
   	{
    	sqVisit(L.data[i]);
    }
    return OK;
}

/**************************************************************************************************
* 2）内部操作函数，有些函数不需要传指针
* 数组列表的引索是1-length，函数内部转为实际的0-length-1
**************************************************************************************************/
/* 初始化顺序线性表 */
sqStatus sqInitList(SqList *L) 
{ 
    L->length=0;
    return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
//可不加指针，没有修改FIFO原来的值
sqStatus sqListEmpty(SqList L)
{ 
	if(L.length==0)
		return TRUE;
	else
		return FALSE;
}

/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
sqStatus sqClearList(SqList *L)
{ 
    L->length=0;
    return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
//可不加指针，没有修改FIFO原来的值
int16_t sqListLength(SqList L)
{
	return L.length;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值,注意i是指位置，第1个位置的数组是从0开始 */
//可不加指针，没有修改FIFO原来的值
sqStatus sqGetElem(SqList L,int i,sqElemType *e)
{
    if(L.length==0 || i<1 || i>L.length)
            return ERROR;
    *e=L.data[i-1];
    return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0，数列排列顺序是从1开始*/
//可不加指针，没有修改FIFO原来的值
//数组列表的引索是1-length，函数内部转为实际的0-length-1
int16_t sqLocateElem(SqList L,sqElemType e)
{
    int i;
    if (L.length==0)
	{
    	return ERROR;
    }
	
	for(i=0;i<L.length;i++)
    {
      	if (L.data[i]==e)
      	{
        	break;
      	}
    }
    if(i>=L.length)
    {
    	return ERROR;
    }
    return i+1;
}


/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
//i的引索是 1-length，然后函数里面转换为0-length-1
sqStatus sqListInsert(SqList *L,int i,sqElemType e)
{ 
	int k;
	if (L->length==SQMAXSIZE)  			/* 顺序线性表已经满 */
		return ERROR;
	
	//插入的位置可以是数组列表的最后一位的后面就是length+1
	if (i<1 || i>L->length+1)			/* 当i比第一位置小或者比最后一位置后一位置还要大时 */
		return ERROR;

	if (i<=L->length)        			/* 若插入数据位置不在表尾 */
	{
		for(k=L->length-1;k>=i-1;k--)  /* 将要插入位置之后的数据元素向后移动一位 */
		{
			L->data[k+1]=L->data[k];
		}
	}
	
	L->data[i-1]=e;          /* 将新元素插入 */
	L->length++;

	return OK;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
sqStatus sqListDelete(SqList *L,int i,sqElemType *e) 
{ 
    int k;
    if (L->length==0)               /* 线性表为空 */
		return ERROR;
	
    if (i<1 || i>L->length)         /* 删除位置不正确 */
        return ERROR;

	*e=L->data[i-1];
    if (i<L->length)                /* 如果删除不是最后位置 */
    {
        for(k=i;k<L->length;k++)	/* 将删除位置后继元素前移 */
			L->data[k-1]=L->data[k];
    }
	
    L->length--;
	
    return OK;
}


/**************************************************************************************************
* 3）自己写的高级操作函数，要注意最后返回的长度是否正确
**************************************************************************************************
* 函数:                                   sqUnionList
* 说明:	合并两个链表的中不一样的元素
*		i的引索是 1-length，然后函数里面转换为0-length-1
* 输入:  
*		   	SqList *La		第一个链表是主体
*			SqList Lb		第二个链表是添加到La中
* 关联变量: 
* 返回:  
* 作者:  日南方  10/19/2020
**************************************************************************************************/
void sqUnionList(SqList *La,SqList Lb)
{
	int La_len,Lb_len,i;
	sqElemType *e = NULL;
	//得到长度 
	La_len=sqListLength(*La);
	Lb_len=sqListLength(Lb);
	//取出B链表的值，搜索A链表
	for (i=1;i<=Lb_len;i++)
	{
		sqGetElem(Lb,i,e);
		if (!sqLocateElem(*La,*e))
			sqListInsert(La,++La_len,*e);
	}
}

/**************************************************************************************************
* 函数:                                   sqDelMin
* 说明:   删除数列中最小的元素用末尾移动补足删除空缺，一次只删除一个
* 输入:  
*		SqList &L		
*		sqStatus &value		
* 关联变量: 
* 返回:   成功 失败
* 作者:  日南方  6/15/2020
**************************************************************************************************/
sqStatus sqDelMin(SqList *L ,sqElemType *value)
{
	int16_t	min_data_i	=0;
	int16_t	i			=0;
	
	if (L->length==0)
	{
		return ERROR;
	}
	*value=L->data[0];
	for (i = 1; i < L->length; ++i)
	{
		if (*value > L->data[i])
		{
			*value = L->data[i];
			min_data_i = i;
		}
	}
	//删除，不改变顺序，要将内部引索值换成外部的
	//sqListDelete(L,min_data_i+1, value);
	//删除，改变顺序
	L->data[min_data_i] = L->data[L->length-1];
	L->length--;
	return OK;
}

/**************************************************************************************************
* 函数:                                   sqInversion
* 说明:  	互换顺序表的头尾,逆序置换
* 输入:  
*		   SqList &L		
* 关联变量: 
* 返回:  
* 作者:  日南方  6/15/2020
**************************************************************************************************/
void sqInversion(SqList *L)
{
	sqElemType 	temp;
	int 		i;
	//如果外部是9，内部是8，交换是0-3<->8-5
	//如果外部是8，内部是7，交换是0-3<->7-4
	for ( i = 0; i < L->length/2; ++i)
	{
		temp = L->data[ L->length-1-i];
		L->data[ L->length-1-i ] = L->data[i];
		L->data[i] = temp;
	}
}

/**************************************************************************************************
* 函数:                    sqDelAllx sqDelAllX_Opt1 sqDelAllX_Opt2
* 说明:  	删除顺序表中所有X
* 输入:  
*		   	SqList &L		
*			sqStatus x		
* 关联变量: 
* 返回:  
* 作者:  日南方  6/16/2020
**************************************************************************************************/
void sqDelAllX(SqList *L , sqElemType x)
{
	int i	= 0;
	int j	= L->length;
	//配合屏蔽片段
	//sqElemType temp;
	
	while (i < j)
	{
		if (L->data[i] == x)
		{
			//删除，不改变顺序，要将内部引索值换成外部的
			//sqListDelete(L,i+1, temp);		
			//删除改变顺序
			L->data[i] = L->data[ L->length-1 ];
			j--;
		}
		else
		{
			i++;
		}
	}
	
}
//删除不改变顺序的优化版
void sqDelAllX_Opt1(SqList *L, sqStatus x)
{
	int i =0 , k = 0;
	for (i = 0, k = 0; i < L->length; ++i)
	{
		//这里的k是来记录与X相等的数量，用来表示需要前移几位
		if (L->data[i] == x)
		{
			k++;
		}else{
			L->data[i-k] = L->data[i]; 
		}
	}
	L->length-= k;
}
void sqDelAllX_Opt2(SqList *L, sqElemType x)
{
	int i = 0, k = 0;
	
	//i是扫描引索,k是赋值引索，利用两个自加不一样的情况进行赋值
	for (i = 0, k = 0; i < L->length; ++i)
	{
		//不一样的赋值，且引索自加
		if (L->data[i] != x)
		{
			L->data[k] = L->data[i];
			k++;
		}
	}
	L->length = k;
}
/**************************************************************************************************
* 4）有序表的高级函数
**************************************************************************************************
* 函数:                                   sqDelSeqListMin2Max
* 说明:   删除(顺序表)中min_data到max_data之间的元素，和sqDelAllX_Opt2思路一致
* 输入:  
*		   SqList *L		
*		sqElemType min_data		
*		sqElemType max_data		
* 关联变量: 
* 返回:  
* 作者:  日南方  10/19/2020
**************************************************************************************************/
sqStatus sqDelSeqListMin2Max(SqList *L, sqElemType min_data, sqElemType max_data)
{
	int i=0, k=0;
	if(L->length==0)
	{
		return ERROR;
	}
	if(min_data >= max_data)
	{
		return ERROR;
	}
	for (i = 0 , k = 0; i < L->length; ++i)
	{
		//i是扫描引索,k是赋值引索，利用两个自加不一样的情况进行赋值
		//将不在最大最小之间的进行赋值
		if (!( min_data < L->data[i] && L->data[i] < max_data))
		{
			L->data[k]=L->data[i];
			k++;
		}
	}
	L->length = k;
	return OK;
}

/**************************************************************************************************
* 函数:                                   sqDelSeqListMin2Max2
* 说明:  删除(有序表)，S到T中间的元素都删除
* 输入:  
*		   SqList & L		
*		sqElemType min_data		
*		sqElemType max_data		
* 关联变量: 
* 返回:  
* 作者:  日南方  10/19/2020
**************************************************************************************************/
boolean_t sqDelSeqListMin2Max2(SqList *L, sqElemType min_data, sqElemType max_data)
{
	int min_data_i, max_data_i;
	if (min_data>=max_data || L->length==0)
	{
		return ERROR;
	}
	// 找最小的索引
	for (min_data_i = 0; min_data_i < L->length&&L->data[min_data_i]<min_data; ++min_data_i);
	if (min_data_i>L->length)
	{
		return ERROR;
	}
	//找最大的索引
	for (max_data_i = min_data_i; max_data_i < L->length && L->data[max_data_i] <= max_data; ++max_data_i);
	if (max_data_i>L->length)
	{
		return ERROR;
	}
	//屏蔽最小和最大的中间进行赋值
	for (; max_data_i < L->length; min_data_i++,max_data_i++)
	{
		L->data[min_data_i] = L->data[max_data_i];
	}

	L->length=min_data_i+1;
	return OK;
}

/**************************************************************************************************
* 函数:                                   sqDelSeqListEqual
* 说明:  （有序表）中删除相同元素,和sqDelAllX_Opt2思路一致
* 输入:  
*		   SqList &L		
* 关联变量: 
* 返回:  
* 作者:  日南方  6/17/2020
**************************************************************************************************/
boolean_t sqDelSeqListEqual(SqList *L)
{
	int i, k;
	if (L->length==0)
	{
		return ERROR;
	}
	for (i = 1, k=0; i < L->length; ++i)
	{
		if(L->data[k] != L->data[i])
		{
			k++;					//指针对齐的问题
			L->data[k] = L->data[i];
		}
		
	}
	L->length=k+1;
	return OK;
}

/**************************************************************************************************
* 函数:                                   sqUnionSeqList
* 说明:  	两个小到大（有序表），合成一个有序表
* 输入:  
*		   SqList A		
*		SqList B		
*		SqList &C		
* 关联变量: 
* 返回:  
* 作者:  日南方  6/17/2020
**************************************************************************************************/
boolean_t sqUnionSeqList(SqList A, SqList B, SqList *C)
{
	
	int A_i,B_i,C_i;
	if(A.length+B.length >SQMAXSIZE)
	{
		return ERROR;
	}
	A_i=B_i=C_i=0;
	//比较大小，进行赋值
	while (A_i < A.length && B_i < B.length)
	{
		if(A.data[A_i] > B.data[B_i])
		{
			C->data[C_i] = B.data[B_i];
			B_i++;
		}else{
			C->data[C_i] = A.data[A_i];
			A_i++;
		}
		C_i++;
	}
	//哪个有剩继续赋值
	while (A_i < A.length)
	{
		C->data[C_i] = A.data[A_i];
		C_i++;
		A_i++;
	}
	while (B_i < B.length)
	{
		C->data[C_i] = B.data[B_i];
		C_i++;
		B_i++;
	}
	C->length = C_i;
	return OK;
}


/**************************************************************************************************
* 特定场景下的函数（数组作为输入参数）
**************************************************************************************************
* 函数:                                   arrayInverse
* 说明:  	在大小为arraySize的数组中，左起left索引，右边到right索引
*       在这两个索引之间的数字进行逆置，
*       索引是0-(N-1),区别于1-N
* 输入:  
*		sqStatus A[]		
*		int left		
*		int right		
*		int arraySize		
* 关联变量: 
* 返回:  
* 作者:  日南方  6/17/2020
**************************************************************************************************/
boolean_t arrayInverse(int16_t A[], int left, int right,  int arraySize)
{
	int mid, i;
	int temp;
	if(left >= right || right >= arraySize )
	{
		return ERROR;
	}
	//arraySize=7,left=1,right=6,mid=3,交换索引是1-2 <-> 6-5
	//arraySize=8,left=1,right=7,mid=4,交换索引是1-3 <->      7-5
	mid = (left+right)/2;
	for (i = 0; i < mid-left; ++i)
	{
		//交换
		temp = A[left+i];
		A[left+i] = A[right-i];
		A[right-i] = temp;
	}
	return OK;
}
/**************************************************************************************************
* 函数:                                   arrayAB2BA
* 说明:   将(a1,a2,a3,b1,b2,b3),逆置成(b1,b2,b3,a1,a2,a3)
*		可以用作循环左移
* 输入:  
*		sqStatus A[]		
*		int m		
*		int n		
*		int arraySize		
* 关联变量: 
* 返回:  
* 作者:  日南方  6/17/2020
**************************************************************************************************/
void arrayAB2BA(int16_t A[],  int m, int n, int arraySize)
{
	arrayInverse(A, 0, m+n-1, arraySize);
	arrayInverse(A, 0, n-1, arraySize);
	arrayInverse(A, n, m+n-1, arraySize);
}
/**************************************************************************************************
* 函数:                                   arrayRotateLeft
* 说明: 数组A 	序列循环左移P位，下面a就是循环左移的序列 
*		ab转ba,先a(-1)b，接着a(-1)b(-1)，最后a(-1)b(-1)(-1)，等于ba
*		这个是2021年王道数据结构第20页第10题
* 输入:  
*		   int R[]		
*		int n		
*		int p		
* 关联变量: 
* 返回:  
* 作者:  日南方  6/18/2020
**************************************************************************************************/
void arrayRotateLeft(int16_t R[], int n, int p)
{
	arrayInverse(R, 0, p-1, p-1);
	arrayInverse(R, p, n-1, n-1);
	arrayInverse(R, 0, n-1, n-1);
}

/**************************************************************************************************
* 函数:                                   arSeqArraySearchInsert
* 说明:  	查找在(有序)数组A中的x，找到和后继元素位置交还，没找到x插入仍是有序
*		这个是2021年王道数据结构第20页题目，要求找到和后继逆置
* 输入:  
*		   sqStatus A[]		
*		int size_max		
*		sqStatus x		
* 关联变量: 
* 返回:  
* 作者:  日南方  6/18/2020
**************************************************************************************************/
int16_t arraySeqArraySearchInsert(int16_t A[], int size_max,sqElemType x)
{
	int low=0, mid, hight=size_max-1;
	int i;
	//配合屏蔽字段
	//sqElemType temp;
	//折半
	while (low<=hight)
	{
		mid = (low+hight)/2;
		if (x < A[mid])
		{
			hight = mid-1;
		}else if(x > A[mid])
		{
			low = mid+1;
		}else{
			low=mid;
			hight=mid;

			break;
		}
	}
//		这个是2021年王道数据结构第20页题目，要求找到和后继逆置
//		if(A[mid]==x && mid!=size_max-1)
//		{
//			temp = A[mid];
//			A[mid] = A[mid+1];
//			A[mid+1] = temp;
//		}
	if (x == A[mid])
	{
		//外部索引是1-N
		return mid+1;
	}
	//查找失败
	if(hight<low)	
	{
		//后移+插入
		for (i = size_max-1; i > hight; i--)
		{
			A[i+1]=A[i];
		}
		A[i+1]=x;
	}
	//外部索引是1-N
	return i+1+1;
}


/**************************************************************************************************
* 函数:                                   arrayABMedian
* 说明:  	（等长）（升序）序列，查找A和B的中位数，逻辑和折半查找差不多
*		长度逻辑是1-N
*		这个是2021年王道数据结构第20页第11题
* 输入:  
*		   int A[]		
*		int B[]		
*		int n		
* 关联变量: 
* 返回:  
* 作者:  日南方  6/19/2020
**************************************************************************************************/
int arrayABMedian(int A[], int B[], int n)
{
	//分别表示序列A和B的首位数、末位数和中位数
	int32_t s1 = 0, d1 = n-1, m1; 
	int32_t s2 = 0, d2 = n-1, m2; 
	while (s1 != d1 || s2 != d2)
	{
		m1 = (s1+d1)/2;
		m2 = (s2+d2)/2;
		//中位数一样，那么A左边+B左边 = A右边+B右边
		//还是A和B合体的中位数
		if (A[m1] == B[m2])
		{
			return A[m1];
		}
		//A的中位数比B小，那么舍弃A的左边,舍弃B的右边，同时舍弃一样多的数值
		//所以才造成舍弃的时候有的需要+1
		if (A[m1] < B[m2])
		{
			//判断单双，进行赋值，这个逻辑和折半查找很像
			if((s1+d1)%2 == 0)
			{					//元素个数为奇数		
				s1 = m1;		//舍弃A中间点以前的部分且保留中间点
				d2 = m2;		//舍弃B中间点以后的部分且保留中间点
			}else{				//元素个数为偶数->0-7，mid=3，左边0-3有4个数
								//右边3-7，有5个数
				s1 = m1+1;		//舍弃A中间点以前的部分同时舍弃中间点
				d2 = m2;		//舍弃B中间点以后的部分且保留中间点
			}
		}
		else
		{
			
			if((s2+d2)%2 == 0)
			{					//元素个数为奇数		
				d1 = m1;		//舍弃A中间点以后的部分且保留中间点
				s2 = m2;		//舍弃B中间点以前的部分且保留中间点
			}else{				//元素个数为偶数
				d1 = m1;		//舍弃A中间点以后的部分且保留中间点
				s2 = m2+1;		//舍弃B中间点以后的部分同时舍弃中间点
			}
		}
	}
	//最后没查找到一样的，选一个返回
	return A[s1]<B[s2] ? A[s1]:B[s2];
}
/**************************************************************************************************
* 函数:                                   Majority
* 说明:   查找(整数)数组中的（主元素）, 主元素是数组中相同个数超过一半
*		外部索引逻辑是1-N
* 输入:  
*		   int A[]		
*		int size		
* 关联变量: 
* 返回:  
* 作者:  日南方  6/19/2020
**************************************************************************************************/
uint8_t arrayMajorElements(int A[], int size)
{
	int i, count;
	int Maj_temp;
	Maj_temp = A[0];
	count = 1;
	//主元素一定在这种加减计数中胜出，因为主元素超过一半
	for (i = 1; i < size; ++i)	
	{
		if (A[i] == Maj_temp)
		{
			count++;
		}else{
			if(count >0)
			{
				count--;
			}else{

				Maj_temp = A[i];
				count=1;
			}
		}
	}							
	//有可能没有主元素，恰巧是末尾计数的，确认主元素
	if(count>0)			
	{
		for (i = 0, count =0; i < size; ++i)
		{
			if (A[i] == Maj_temp)
			{
				count++;
			}
		}
	}
	if (count > size/2)
	{
		return Maj_temp;
	}else{
		return ERROR;
	}
}
/**************************************************************************************************
* 函数:                                   arryMiniPositInteger
* 说明:   查找（整数）数组中，未出现的最小（正整数）
*		外部索引逻辑是1-N
* 输入:  
*		   int A[]		
*		int size		
* 关联变量: 
* 返回:  
* 作者:  日南方  10/19/2020
**************************************************************************************************/
int arryMiniPositInteger(int A[],int size)
{
	 int i, *B;
	 //数组为n个，他如果最满就是[1,2,3,4,5,6,7,8,9],有几个索引就有从最小到大的正整数
	 //如果其中有其他被替换，对应的正整数的索引一定有缺
	 B = (int *)malloc(sizeof(int)*size);
	 memset(B, 0, sizeof(int)*size);
	 //有的正整数对应索引置一
	 for (i = 0; i < size; ++i)	
	 {
	 	if(A[i] > 0 && A[i] <= size)		
	 	{
			B[A[i]-1] = 1;    	//下标0映射1，1映射2
		}
	 }
	 //找到最小没有置一的索引
	 for (i = 0; i < size; ++i)
	 {
		 if (B[i] == 0)
		 {
		 	return i+1;
		 }
	 }
	 return size+1;
}

/**************************************************************************************************
* 使用示例（20200601版本未更新）
**************************************************************************************************
* 函数:                                   main
* 说明:  
* 输入:  
*		   
* 关联变量: 
* 返回:  
* 作者:  日南方  10/19/2020
**************************************************************************************************/
#if 0
int main()
{
        
    SqList L;
	SqList Lb;
    
    sqStatus e;
    sqStatus i;
    int j,k;
    i=InitList(&L);
    printf("初始化L后：L->length=%d\n",L->length);
    for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
    printf("在L的表头依次插入1～5后：L->data=");
    ListTraverse(L); 

    printf("L->length=%d \n",L->length);
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    i=ClearList(&L);
    printf("清空L后：L->length=%d\n",L->length);
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);
    printf("在L的表尾依次插入1～10后：L->data=");
    ListTraverse(L); 

    printf("L->length=%d \n",L->length);

    ListInsert(&L,1,0);
    printf("在L的表头插入0后：L->data=");
    ListTraverse(L); 
    printf("L->length=%d \n",L->length);

    GetElem(L,5,&e);
    printf("第5个元素的值为：%d\n",e);
    for(j=3;j<=4;j++)
    {
            k=LocateElem(L,j);
            if(k)
                    printf("第%d个元素的值为%d\n",k,j);
            else
                    printf("没有值为%d的元素\n",j);
    }
    

    k=ListLength(L); /* k为表长 */
    for(j=k+1;j>=k;j--)
    {
            i=ListDelete(&L,j,&e); /* 删除第j个数据 */
            if(i==ERROR)
                    printf("删除第%d个数据失败\n",j);
            else
                    printf("删除第%d个的元素值为：%d\n",j,e);
    }
    printf("依次输出L的元素：");
    ListTraverse(L); 

    j=5;
    ListDelete(&L,j,&e); /* 删除第5个数据 */
    printf("删除第%d个的元素值为：%d\n",j,e);

    printf("依次输出L的元素：");
    ListTraverse(L); 

	//构造一个有10个数的Lb
	i=InitList(&Lb);
    for(j=6;j<=15;j++)
            i=ListInsert(&Lb,1,j);

	unionL(&L,Lb);

	printf("依次输出合并了Lb的L的元素：");
    ListTraverse(L); 

    return 0;
}
#endif

