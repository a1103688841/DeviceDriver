/**************************************************************************************************
* ����:                              ��̬����
*        
* �ļ�:  StaticLinkList.c
*        
* ˵��:  
*        
* ����:  ���Ϸ�  10/22/2020
**************************************************************************************************/

#define __STATICLINKLIST_C__
/* ------------------------------------------- include ----------------------------------------- */
#include "StaticLinkList.h"

/* ------------------------------------- define/typedef/enum ----------------------------------- */


/* ------------------------------------------- variable ---------------------------------------- */


/* -------------------------------------------static funtion ----------------------------------------- */
#ifdef STATIC_FUNCTION
#endif	/* STATIC_FUNCTION */
//��ӡһ��Ԫ��
static slListStatus slListVisit(slListElemType c);

/* -------------------------------------------global funtion ----------------------------------------- */
#ifdef GLOBAL_FUNCTION
#endif	/* GLOBAL_FUNCTION */
/**************************************************************************************************
*	 ����
* 1����ӡ����   ������Ĵ�ӡ�߼����������е㲻һ����
* 2���ڲ���������
* 3) ʹ��ʾ��   ��20201022�汾��
**************************************************************************************************
*1�� ��ӡ����
**************************************************************************************************/
//��ӡһ��Ԫ��
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
*2�� �ڲ���������
**************************************************************************************************/
/* ��һά����space�и���������һ����������space[0].curΪͷָ�룬"0"��ʾ��ָ�� */
slListStatus slListInit(StaticLinkList space) 
{
	int i;
	for (i=0; i<SLLISTMAXSIZE-1; i++)  
	{
		space[i].cur = i+1;
	}
	space[SLLISTMAXSIZE-1].cur = 0; /* Ŀǰ��̬����Ϊ�գ����һ��Ԫ�ص�curΪ0 */
	return OK;
}
//���
slListStatus slListClear(StaticLinkList space) 
{
	int i;
	for (i=0; i<SLLISTMAXSIZE-1; i++)  
	{
		space[i].cur = i+1;
	}
	space[SLLISTMAXSIZE-1].cur = 0; /* Ŀǰ��̬����Ϊ�գ����һ��Ԫ�ص�curΪ0 */
	return OK;
}
//�գ�
slListStatus slListEmpty (StaticLinkList space)
{
	int32_t i = space[0].cur;
	if (i)
	{
		return FALSE;
	}
	return TRUE; 
}

/* �����ÿռ�����ǿգ��򷵻ط���Ľ���±꣬���򷵻�0 */
int slList_Malloc(StaticLinkList space) 
{ 
	int i = space[0].cur;           		/* ��ǰ�����һ��Ԫ�ص�cur���ֵ */
	                                		/* ����Ҫ���صĵ�һ�����ÿ��е��±� */
	if (space[0].cur)
	{
	    space[0].cur = space[i].cur;       /* ����Ҫ�ó�һ��������ʹ���ˣ� */
	}                                        /* �������Ǿ͵ð�������һ�� */
	                                        /* �������������� */
	return i;
}

/*  ���±�Ϊk�Ŀ��н����յ��������� */
void slList_Free(StaticLinkList space, int k) 
{  
    space[k].cur = space[0].cur;    /* �ѵ�һ��Ԫ�ص�curֵ����Ҫɾ���ķ���cur */
    space[0].cur = k;               /* ��Ҫɾ���ķ����±긳ֵ����һ��Ԫ�ص�cur */
}

/* ��ʼ��������̬����L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
int slListLength(StaticLinkList L)
{
	//j�Ǽ�����i��ɨ���α�
    int j = 0;
    int i = L[SLLISTMAXSIZE-1].cur;
	//ɨ�赽0���ǵ�����
    while(i)
    {
        i=L[i].cur;
        j++;
    }
    return j;
}

/*  ��L�е�i��Ԫ��֮ǰ�����µ�����Ԫ��e   */
slListStatus slListInsert(StaticLinkList L, int i, slListElemType e)   
{  
	//j�ǲ���ķ���ռ�,k��ɨ���α�,l����ʱ����
    int j, k, l; 
	//ɨ���ͱ�����ͷ���
    k = SLLISTMAXSIZE - 1;   /* ע��k���������һ��Ԫ�ص��±� */
	//����λ�ô���
	if (i < 1 || i > slListLength(L) + 1)   
    {
        return ERROR;   
    }
	//j != 0  ���Ƿ���ɹ�
	j = slList_Malloc(L);   /* ��ÿ��з������±� */
    if (j)   
    {   
		//ɨ��ﵽ����λ��
		for(l = 1; l <= i - 1; l++)   /* �ҵ���i��Ԫ��֮ǰ��λ�� */
		{
		   k = L[k].cur;           
		}
		//����
		L[j].data = e;   /* �����ݸ�ֵ���˷�����data */
		L[j].cur = L[k].cur;    /* �ѵ�i��Ԫ��֮ǰ��cur��ֵ����Ԫ�ص�cur */
		L[k].cur = j;           /* ����Ԫ�ص��±긳ֵ����i��Ԫ��֮ǰԪ�ص�ur */
		return OK;   
    }   
    return ERROR;   
}

/*  ɾ����L�е�i������Ԫ��   */
slListStatus slListDelete(StaticLinkList L, int i)   
{ 
	//j�ǲ���ķ���ռ�,k��ɨ���α�
    int j, k;  
	//ɾ������λ�ô���
    if (i < 1 || i > slListLength(L))
    {
        return ERROR;   
    }
	//ɨ���ͱ�����ͷ���
	k = SLLISTMAXSIZE - 1;   
	//ɨ�赽������λ��
	for (j = 1; j <= i - 1; j++)   
    {
        k = L[k].cur;   
    }
	//ɾ��
	j = L[k].cur;   
    L[k].cur = L[j].cur;   
    slList_Free(L, j);   
    return OK;   
} 
/**************************************************************************************************
*3�� ʹ��ʾ��
**************************************************************************************************/
#if 0
int main()
{
    slListStatus i;
    //��ʼ��
    i=slListInit(test_ssl);
    printf("��ʼ��L��L.length=%d\n",slListLength(test_ssl));
	//����
    i=slListInsert(test_ssl,1,'F');
    i=slListInsert(test_ssl,1,'E');
    i=slListInsert(test_ssl,1,'D');
    i=slListInsert(test_ssl,1,'B');
    i=slListInsert(test_ssl,1,'A');
    printf("\n��L�ı�ͷ���β���FEDBA�� L.data=");
    slListPrintfTraverse(test_ssl);
    i=slListInsert(test_ssl,3,'C');
    printf("\n��L�ġ�B���롰D��֮����롰C���� L.data=");
    slListPrintfTraverse(test_ssl); 
	//ɾ��
    i=slListDelete(test_ssl,1);
    printf("\n��L��ɾ����A����L.data=");
    slListPrintfTraverse(test_ssl); 
    printf("\n");
    //���
    i = slListClear(test_ssl);
    printf("���L��L.length=%d\n", slListLength(test_ssl));
    return 0;
}
#endif


