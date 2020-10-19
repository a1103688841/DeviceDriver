/**************************************************************************************************
* �ļ�:  sqList.h
*        
* ˵��:  
*        
* ����:  ���Ϸ�  10/19/2020
**************************************************************************************************/
#ifndef __SQLIST_H__
#define __SQLIST_H__

/* ------------------------------------------- include ----------------------------------------- */
#include "def.h"
//Ĭ��	
#include "stdio.h"      
#include "math.h"  
#include "string.h"

/* ------------------------------------- define/typedef/enum ----------------------------------- */
//��def.h�ж���
#ifndef OK
#define OK 1
#endif
#ifndef ERROR
#define ERROR 0
#endif
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

typedef uint8_t sqStatus;      			/* sqStatus�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int16_t sqElemType;  				/* sqElemType���͸���ʵ������������������Ϊint */

#define SQMAXSIZE 20 					/* �洢�ռ��ʼ������ */
typedef struct
{
	sqElemType data[SQMAXSIZE+1];  		/* ���飬�洢����Ԫ�� */
	int length;                      	/* ���Ա�ǰ����,�ⲿ�߼���1-N */
}SqList;


/* ------------------------------------------- variable ---------------------------------------- */
#ifdef __SQLIST_C__
	#define SQLIST_EXT
#else
	#define SQLIST_EXT		extern
#endif

#if 0
SQLIST_EXT S32 var
#ifdef __SQLIST_C__
= 0
#endif
;
#endif

/* ------------------------------------------- funtion ----------------------------------------- */
//��ӡ

extern sqStatus sqVisit (sqElemType c);								//��ӡһ��Ԫ��
extern sqStatus sqListTraverse (SqList L);							//��ӡȫ��

//�ڲ������������ⲿ�����߼���1-n
extern sqStatus sqInitList (SqList *L); 							//��ʼ
extern sqStatus sqClearList (SqList *L);							//���
extern sqStatus sqListEmpty (SqList L);								//�գ�
extern sqStatus sqGetElem (SqList L, int i, sqElemType *e);			//ȡԪ��
extern int16_t sqListLength (SqList L);								//ȡ����
extern int16_t sqLocateElem (SqList L, sqElemType e);				//����
extern sqStatus sqListDelete (SqList *L, int i, sqElemType *e);	//ɾ��
extern sqStatus sqListInsert (SqList *L, int i, sqElemType e);		//����

//�߼�����
extern sqStatus sqDelMin (SqList *L , sqElemType *value);			//ɾ��С
extern void sqDelAllX (SqList *L , sqElemType x);					//ɾx
extern void sqDelAllX_Opt1 (SqList *L, sqStatus x);					//ɾx�Ż�
extern void sqDelAllX_Opt2 (SqList *L, sqElemType x);				//ɾx�Ż�
extern void sqUnionList (SqList *La, SqList Lb);					//ƴ��sqA,sqB
extern void sqInversion (SqList *L);								//����

//����
extern boolean_t sqDelSeqListEqual (SqList *L);						//ɾ���
extern sqStatus sqDelSeqListMin2Max (SqList *L, sqElemType min_data, sqElemType max_data);		//ɾmin��max
extern boolean_t sqDelSeqListMin2Max2 (SqList *L, sqElemType min_data, sqElemType max_data);//ɾmin��max
extern boolean_t sqUnionSeqList (SqList A, SqList B, SqList *C);	//ƴ��sqA,sqBƴ�껹������


//����
extern int16_t arraySeqArraySearchInsert (int16_t A[], int size_max, sqElemType x);	//�����������飬û�оͲ���
extern uint8_t arrayMajorElements (int A[], int size);					//ȡ������Ԫ��
extern int arrayABMedian (int A[], int B[], int n);						//ȡ����A,B����λ��
extern int arryMiniPositInteger (int A[], int size);					//ȡ������Сδ���ֵ�������
extern boolean_t arrayInverse (int16_t A[], int left, int right, int arraySize); //ָ��������������
extern void arrayAB2BA (int16_t A[], int m, int n, int arraySize);		//������[A��B]���[B��A]
extern void arrayRotateLeft (int16_t R[], int n, int p);				//������ѭ������



#endif  /*  __SQLIST_H__  */
