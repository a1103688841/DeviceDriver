
/**************************************************************************************************
* ����:                              sqList
*        
* �ļ�:   sqList.c
*        
* ˵��: ʹ��������Ϊ������ 
*        
* ����:  ���Ϸ�  10/19/2020
**************************************************************************************************/

#define __SQLIST_C__
/* ------------------------------------------- include ----------------------------------------- */
#include "sqList.h"
/* ------------------------------------- define/typedef/enum ----------------------------------- */

/* ------------------------------------------- variable ---------------------------------------- */


/* -------------------------------------------static funtion ----------------------------------------- */
#ifdef STATIC_FUNCTION
#endif	/* STATIC_FUNCTION */
//��ӡһ��Ԫ��
static sqStatus sqVisit(sqElemType c);

/* -------------------------------------------global funtion ----------------------------------------- */
#ifdef GLOBAL_FUNCTION
#endif	/* GLOBAL_FUNCTION */
/**************************************************************************************************
*	 ����
* 1����ӡ����
* 2���ڲ���������
* 3���߼�������Ҫע����󷵻صĳ����Ƿ���ȷ
* 4) �����ĸ߼�����
* 5���ض�����������Ϊ���������
* 6) ʹ��ʾ����20200601�汾δ���£�
**************************************************************************************************
*1�� �޸ĺ���
**************************************************************************************************/
//��ӡһ�����鵥�����ֵ
static sqStatus sqVisit(sqElemType c)
{
		//ѡ����ӡ�ĺ���
		//Uart_Printf("this fifo[i] data is %d\n",__MODULE__,__LINE__,c);
    return OK;
}
/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* ������������ζ�L��ÿ������Ԫ����� */
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
* 2���ڲ�������������Щ��������Ҫ��ָ��
* �����б��������1-length�������ڲ�תΪʵ�ʵ�0-length-1
**************************************************************************************************/
/* ��ʼ��˳�����Ա� */
sqStatus sqInitList(SqList *L) 
{ 
    L->length=0;
    return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
//�ɲ���ָ�룬û���޸�FIFOԭ����ֵ
sqStatus sqListEmpty(SqList L)
{ 
	if(L.length==0)
		return TRUE;
	else
		return FALSE;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
sqStatus sqClearList(SqList *L)
{ 
    L->length=0;
    return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
//�ɲ���ָ�룬û���޸�FIFOԭ����ֵ
int16_t sqListLength(SqList L)
{
	return L.length;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* �����������e����L�е�i������Ԫ�ص�ֵ,ע��i��ָλ�ã���1��λ�õ������Ǵ�0��ʼ */
//�ɲ���ָ�룬û���޸�FIFOԭ����ֵ
sqStatus sqGetElem(SqList L,int i,sqElemType *e)
{
    if(L.length==0 || i<1 || i>L.length)
            return ERROR;
    *e=L.data[i-1];
    return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* �������������L�е�1����e�����ϵ������Ԫ�ص�λ�� */
/* ������������Ԫ�ز����ڣ��򷵻�ֵΪ0����������˳���Ǵ�1��ʼ*/
//�ɲ���ָ�룬û���޸�FIFOԭ����ֵ
//�����б��������1-length�������ڲ�תΪʵ�ʵ�0-length-1
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


/* ��ʼ������˳�����Ա�L�Ѵ���,1��i��ListLength(L)�� */
/* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
//i�������� 1-length��Ȼ��������ת��Ϊ0-length-1
sqStatus sqListInsert(SqList *L,int i,sqElemType e)
{ 
	int k;
	if (L->length==SQMAXSIZE)  			/* ˳�����Ա��Ѿ��� */
		return ERROR;
	
	//�����λ�ÿ����������б�����һλ�ĺ������length+1
	if (i<1 || i>L->length+1)			/* ��i�ȵ�һλ��С���߱����һλ�ú�һλ�û�Ҫ��ʱ */
		return ERROR;

	if (i<=L->length)        			/* ����������λ�ò��ڱ�β */
	{
		for(k=L->length-1;k>=i-1;k--)  /* ��Ҫ����λ��֮�������Ԫ������ƶ�һλ */
		{
			L->data[k+1]=L->data[k];
		}
	}
	
	L->data[i-1]=e;          /* ����Ԫ�ز��� */
	L->length++;

	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
sqStatus sqListDelete(SqList *L,int i,sqElemType *e) 
{ 
    int k;
    if (L->length==0)               /* ���Ա�Ϊ�� */
		return ERROR;
	
    if (i<1 || i>L->length)         /* ɾ��λ�ò���ȷ */
        return ERROR;

	*e=L->data[i-1];
    if (i<L->length)                /* ���ɾ���������λ�� */
    {
        for(k=i;k<L->length;k++)	/* ��ɾ��λ�ú��Ԫ��ǰ�� */
			L->data[k-1]=L->data[k];
    }
	
    L->length--;
	
    return OK;
}


/**************************************************************************************************
* 3���Լ�д�ĸ߼�����������Ҫע����󷵻صĳ����Ƿ���ȷ
**************************************************************************************************
* ����:                                   sqUnionList
* ˵��:	�ϲ�����������в�һ����Ԫ��
*		i�������� 1-length��Ȼ��������ת��Ϊ0-length-1
* ����:  
*		   	SqList *La		��һ������������
*			SqList Lb		�ڶ�����������ӵ�La��
* ��������: 
* ����:  
* ����:  ���Ϸ�  10/19/2020
**************************************************************************************************/
void sqUnionList(SqList *La,SqList Lb)
{
	int La_len,Lb_len,i;
	sqElemType *e = NULL;
	//�õ����� 
	La_len=sqListLength(*La);
	Lb_len=sqListLength(Lb);
	//ȡ��B�����ֵ������A����
	for (i=1;i<=Lb_len;i++)
	{
		sqGetElem(Lb,i,e);
		if (!sqLocateElem(*La,*e))
			sqListInsert(La,++La_len,*e);
	}
}

/**************************************************************************************************
* ����:                                   sqDelMin
* ˵��:   ɾ����������С��Ԫ����ĩβ�ƶ�����ɾ����ȱ��һ��ֻɾ��һ��
* ����:  
*		SqList &L		
*		sqStatus &value		
* ��������: 
* ����:   �ɹ� ʧ��
* ����:  ���Ϸ�  6/15/2020
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
	//ɾ�������ı�˳��Ҫ���ڲ�����ֵ�����ⲿ��
	//sqListDelete(L,min_data_i+1, value);
	//ɾ�����ı�˳��
	L->data[min_data_i] = L->data[L->length-1];
	L->length--;
	return OK;
}

/**************************************************************************************************
* ����:                                   sqInversion
* ˵��:  	����˳����ͷβ,�����û�
* ����:  
*		   SqList &L		
* ��������: 
* ����:  
* ����:  ���Ϸ�  6/15/2020
**************************************************************************************************/
void sqInversion(SqList *L)
{
	sqElemType 	temp;
	int 		i;
	//����ⲿ��9���ڲ���8��������0-3<->8-5
	//����ⲿ��8���ڲ���7��������0-3<->7-4
	for ( i = 0; i < L->length/2; ++i)
	{
		temp = L->data[ L->length-1-i];
		L->data[ L->length-1-i ] = L->data[i];
		L->data[i] = temp;
	}
}

/**************************************************************************************************
* ����:                    sqDelAllx sqDelAllX_Opt1 sqDelAllX_Opt2
* ˵��:  	ɾ��˳���������X
* ����:  
*		   	SqList &L		
*			sqStatus x		
* ��������: 
* ����:  
* ����:  ���Ϸ�  6/16/2020
**************************************************************************************************/
void sqDelAllX(SqList *L , sqElemType x)
{
	int i	= 0;
	int j	= L->length;
	//�������Ƭ��
	//sqElemType temp;
	
	while (i < j)
	{
		if (L->data[i] == x)
		{
			//ɾ�������ı�˳��Ҫ���ڲ�����ֵ�����ⲿ��
			//sqListDelete(L,i+1, temp);		
			//ɾ���ı�˳��
			L->data[i] = L->data[ L->length-1 ];
			j--;
		}
		else
		{
			i++;
		}
	}
	
}
//ɾ�����ı�˳����Ż���
void sqDelAllX_Opt1(SqList *L, sqStatus x)
{
	int i =0 , k = 0;
	for (i = 0, k = 0; i < L->length; ++i)
	{
		//�����k������¼��X��ȵ�������������ʾ��Ҫǰ�Ƽ�λ
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
	
	//i��ɨ������,k�Ǹ�ֵ���������������ԼӲ�һ����������и�ֵ
	for (i = 0, k = 0; i < L->length; ++i)
	{
		//��һ���ĸ�ֵ���������Լ�
		if (L->data[i] != x)
		{
			L->data[k] = L->data[i];
			k++;
		}
	}
	L->length = k;
}
/**************************************************************************************************
* 4�������ĸ߼�����
**************************************************************************************************
* ����:                                   sqDelSeqListMin2Max
* ˵��:   ɾ��(˳���)��min_data��max_data֮���Ԫ�أ���sqDelAllX_Opt2˼·һ��
* ����:  
*		   SqList *L		
*		sqElemType min_data		
*		sqElemType max_data		
* ��������: 
* ����:  
* ����:  ���Ϸ�  10/19/2020
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
		//i��ɨ������,k�Ǹ�ֵ���������������ԼӲ�һ����������и�ֵ
		//�����������С֮��Ľ��и�ֵ
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
* ����:                                   sqDelSeqListMin2Max2
* ˵��:  ɾ��(�����)��S��T�м��Ԫ�ض�ɾ��
* ����:  
*		   SqList & L		
*		sqElemType min_data		
*		sqElemType max_data		
* ��������: 
* ����:  
* ����:  ���Ϸ�  10/19/2020
**************************************************************************************************/
boolean_t sqDelSeqListMin2Max2(SqList *L, sqElemType min_data, sqElemType max_data)
{
	int min_data_i, max_data_i;
	if (min_data>=max_data || L->length==0)
	{
		return ERROR;
	}
	// ����С������
	for (min_data_i = 0; min_data_i < L->length&&L->data[min_data_i]<min_data; ++min_data_i);
	if (min_data_i>L->length)
	{
		return ERROR;
	}
	//����������
	for (max_data_i = min_data_i; max_data_i < L->length && L->data[max_data_i] <= max_data; ++max_data_i);
	if (max_data_i>L->length)
	{
		return ERROR;
	}
	//������С�������м���и�ֵ
	for (; max_data_i < L->length; min_data_i++,max_data_i++)
	{
		L->data[min_data_i] = L->data[max_data_i];
	}

	L->length=min_data_i+1;
	return OK;
}

/**************************************************************************************************
* ����:                                   sqDelSeqListEqual
* ˵��:  ���������ɾ����ͬԪ��,��sqDelAllX_Opt2˼·һ��
* ����:  
*		   SqList &L		
* ��������: 
* ����:  
* ����:  ���Ϸ�  6/17/2020
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
			k++;					//ָ����������
			L->data[k] = L->data[i];
		}
		
	}
	L->length=k+1;
	return OK;
}

/**************************************************************************************************
* ����:                                   sqUnionSeqList
* ˵��:  	����С������������ϳ�һ�������
* ����:  
*		   SqList A		
*		SqList B		
*		SqList &C		
* ��������: 
* ����:  
* ����:  ���Ϸ�  6/17/2020
**************************************************************************************************/
boolean_t sqUnionSeqList(SqList A, SqList B, SqList *C)
{
	
	int A_i,B_i,C_i;
	if(A.length+B.length >SQMAXSIZE)
	{
		return ERROR;
	}
	A_i=B_i=C_i=0;
	//�Ƚϴ�С�����и�ֵ
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
	//�ĸ���ʣ������ֵ
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
* �ض������µĺ�����������Ϊ���������
**************************************************************************************************
* ����:                                   arrayInverse
* ˵��:  	�ڴ�СΪarraySize�������У�����left�������ұߵ�right����
*       ������������֮������ֽ������ã�
*       ������0-(N-1),������1-N
* ����:  
*		sqStatus A[]		
*		int left		
*		int right		
*		int arraySize		
* ��������: 
* ����:  
* ����:  ���Ϸ�  6/17/2020
**************************************************************************************************/
boolean_t arrayInverse(int16_t A[], int left, int right,  int arraySize)
{
	int mid, i;
	int temp;
	if(left >= right || right >= arraySize )
	{
		return ERROR;
	}
	//arraySize=7,left=1,right=6,mid=3,����������1-2 <-> 6-5
	//arraySize=8,left=1,right=7,mid=4,����������1-3 <->      7-5
	mid = (left+right)/2;
	for (i = 0; i < mid-left; ++i)
	{
		//����
		temp = A[left+i];
		A[left+i] = A[right-i];
		A[right-i] = temp;
	}
	return OK;
}
/**************************************************************************************************
* ����:                                   arrayAB2BA
* ˵��:   ��(a1,a2,a3,b1,b2,b3),���ó�(b1,b2,b3,a1,a2,a3)
*		��������ѭ������
* ����:  
*		sqStatus A[]		
*		int m		
*		int n		
*		int arraySize		
* ��������: 
* ����:  
* ����:  ���Ϸ�  6/17/2020
**************************************************************************************************/
void arrayAB2BA(int16_t A[],  int m, int n, int arraySize)
{
	arrayInverse(A, 0, m+n-1, arraySize);
	arrayInverse(A, 0, n-1, arraySize);
	arrayInverse(A, n, m+n-1, arraySize);
}
/**************************************************************************************************
* ����:                                   arrayRotateLeft
* ˵��: ����A 	����ѭ������Pλ������a����ѭ�����Ƶ����� 
*		abתba,��a(-1)b������a(-1)b(-1)�����a(-1)b(-1)(-1)������ba
*		�����2021���������ݽṹ��20ҳ��10��
* ����:  
*		   int R[]		
*		int n		
*		int p		
* ��������: 
* ����:  
* ����:  ���Ϸ�  6/18/2020
**************************************************************************************************/
void arrayRotateLeft(int16_t R[], int n, int p)
{
	arrayInverse(R, 0, p-1, p-1);
	arrayInverse(R, p, n-1, n-1);
	arrayInverse(R, 0, n-1, n-1);
}

/**************************************************************************************************
* ����:                                   arSeqArraySearchInsert
* ˵��:  	������(����)����A�е�x���ҵ��ͺ��Ԫ��λ�ý�����û�ҵ�x������������
*		�����2021���������ݽṹ��20ҳ��Ŀ��Ҫ���ҵ��ͺ������
* ����:  
*		   sqStatus A[]		
*		int size_max		
*		sqStatus x		
* ��������: 
* ����:  
* ����:  ���Ϸ�  6/18/2020
**************************************************************************************************/
int16_t arraySeqArraySearchInsert(int16_t A[], int size_max,sqElemType x)
{
	int low=0, mid, hight=size_max-1;
	int i;
	//��������ֶ�
	//sqElemType temp;
	//�۰�
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
//		�����2021���������ݽṹ��20ҳ��Ŀ��Ҫ���ҵ��ͺ������
//		if(A[mid]==x && mid!=size_max-1)
//		{
//			temp = A[mid];
//			A[mid] = A[mid+1];
//			A[mid+1] = temp;
//		}
	if (x == A[mid])
	{
		//�ⲿ������1-N
		return mid+1;
	}
	//����ʧ��
	if(hight<low)	
	{
		//����+����
		for (i = size_max-1; i > hight; i--)
		{
			A[i+1]=A[i];
		}
		A[i+1]=x;
	}
	//�ⲿ������1-N
	return i+1+1;
}


/**************************************************************************************************
* ����:                                   arrayABMedian
* ˵��:  	���ȳ������������У�����A��B����λ�����߼����۰���Ҳ��
*		�����߼���1-N
*		�����2021���������ݽṹ��20ҳ��11��
* ����:  
*		   int A[]		
*		int B[]		
*		int n		
* ��������: 
* ����:  
* ����:  ���Ϸ�  6/19/2020
**************************************************************************************************/
int arrayABMedian(int A[], int B[], int n)
{
	//�ֱ��ʾ����A��B����λ����ĩλ������λ��
	int32_t s1 = 0, d1 = n-1, m1; 
	int32_t s2 = 0, d2 = n-1, m2; 
	while (s1 != d1 || s2 != d2)
	{
		m1 = (s1+d1)/2;
		m2 = (s2+d2)/2;
		//��λ��һ������ôA���+B��� = A�ұ�+B�ұ�
		//����A��B�������λ��
		if (A[m1] == B[m2])
		{
			return A[m1];
		}
		//A����λ����BС����ô����A�����,����B���ұߣ�ͬʱ����һ�������ֵ
		//���Բ����������ʱ���е���Ҫ+1
		if (A[m1] < B[m2])
		{
			//�жϵ�˫�����и�ֵ������߼����۰���Һ���
			if((s1+d1)%2 == 0)
			{					//Ԫ�ظ���Ϊ����		
				s1 = m1;		//����A�м����ǰ�Ĳ����ұ����м��
				d2 = m2;		//����B�м���Ժ�Ĳ����ұ����м��
			}else{				//Ԫ�ظ���Ϊż��->0-7��mid=3�����0-3��4����
								//�ұ�3-7����5����
				s1 = m1+1;		//����A�м����ǰ�Ĳ���ͬʱ�����м��
				d2 = m2;		//����B�м���Ժ�Ĳ����ұ����м��
			}
		}
		else
		{
			
			if((s2+d2)%2 == 0)
			{					//Ԫ�ظ���Ϊ����		
				d1 = m1;		//����A�м���Ժ�Ĳ����ұ����м��
				s2 = m2;		//����B�м����ǰ�Ĳ����ұ����м��
			}else{				//Ԫ�ظ���Ϊż��
				d1 = m1;		//����A�м���Ժ�Ĳ����ұ����м��
				s2 = m2+1;		//����B�м���Ժ�Ĳ���ͬʱ�����м��
			}
		}
	}
	//���û���ҵ�һ���ģ�ѡһ������
	return A[s1]<B[s2] ? A[s1]:B[s2];
}
/**************************************************************************************************
* ����:                                   Majority
* ˵��:   ����(����)�����еģ���Ԫ�أ�, ��Ԫ������������ͬ��������һ��
*		�ⲿ�����߼���1-N
* ����:  
*		   int A[]		
*		int size		
* ��������: 
* ����:  
* ����:  ���Ϸ�  6/19/2020
**************************************************************************************************/
uint8_t arrayMajorElements(int A[], int size)
{
	int i, count;
	int Maj_temp;
	Maj_temp = A[0];
	count = 1;
	//��Ԫ��һ�������ּӼ�������ʤ������Ϊ��Ԫ�س���һ��
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
	//�п���û����Ԫ�أ�ǡ����ĩβ�����ģ�ȷ����Ԫ��
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
* ����:                                   arryMiniPositInteger
* ˵��:   ���ң������������У�δ���ֵ���С����������
*		�ⲿ�����߼���1-N
* ����:  
*		   int A[]		
*		int size		
* ��������: 
* ����:  
* ����:  ���Ϸ�  10/19/2020
**************************************************************************************************/
int arryMiniPositInteger(int A[],int size)
{
	 int i, *B;
	 //����Ϊn�����������������[1,2,3,4,5,6,7,8,9],�м����������д���С�����������
	 //����������������滻����Ӧ��������������һ����ȱ
	 B = (int *)malloc(sizeof(int)*size);
	 memset(B, 0, sizeof(int)*size);
	 //�е���������Ӧ������һ
	 for (i = 0; i < size; ++i)	
	 {
	 	if(A[i] > 0 && A[i] <= size)		
	 	{
			B[A[i]-1] = 1;    	//�±�0ӳ��1��1ӳ��2
		}
	 }
	 //�ҵ���Сû����һ������
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
* ʹ��ʾ����20200601�汾δ���£�
**************************************************************************************************
* ����:                                   main
* ˵��:  
* ����:  
*		   
* ��������: 
* ����:  
* ����:  ���Ϸ�  10/19/2020
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
    printf("��ʼ��L��L->length=%d\n",L->length);
    for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
    printf("��L�ı�ͷ���β���1��5��L->data=");
    ListTraverse(L); 

    printf("L->length=%d \n",L->length);
    i=ListEmpty(L);
    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);

    i=ClearList(&L);
    printf("���L��L->length=%d\n",L->length);
    i=ListEmpty(L);
    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);

    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);
    printf("��L�ı�β���β���1��10��L->data=");
    ListTraverse(L); 

    printf("L->length=%d \n",L->length);

    ListInsert(&L,1,0);
    printf("��L�ı�ͷ����0��L->data=");
    ListTraverse(L); 
    printf("L->length=%d \n",L->length);

    GetElem(L,5,&e);
    printf("��5��Ԫ�ص�ֵΪ��%d\n",e);
    for(j=3;j<=4;j++)
    {
            k=LocateElem(L,j);
            if(k)
                    printf("��%d��Ԫ�ص�ֵΪ%d\n",k,j);
            else
                    printf("û��ֵΪ%d��Ԫ��\n",j);
    }
    

    k=ListLength(L); /* kΪ�� */
    for(j=k+1;j>=k;j--)
    {
            i=ListDelete(&L,j,&e); /* ɾ����j������ */
            if(i==ERROR)
                    printf("ɾ����%d������ʧ��\n",j);
            else
                    printf("ɾ����%d����Ԫ��ֵΪ��%d\n",j,e);
    }
    printf("�������L��Ԫ�أ�");
    ListTraverse(L); 

    j=5;
    ListDelete(&L,j,&e); /* ɾ����5������ */
    printf("ɾ����%d����Ԫ��ֵΪ��%d\n",j,e);

    printf("�������L��Ԫ�أ�");
    ListTraverse(L); 

	//����һ����10������Lb
	i=InitList(&Lb);
    for(j=6;j<=15;j++)
            i=ListInsert(&Lb,1,j);

	unionL(&L,Lb);

	printf("��������ϲ���Lb��L��Ԫ�أ�");
    ListTraverse(L); 

    return 0;
}
#endif

