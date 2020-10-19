/**************************************************************************************************
* 文件:  sqList.h
*        
* 说明:  
*        
* 作者:  日南方  10/19/2020
**************************************************************************************************/
#ifndef __SQLIST_H__
#define __SQLIST_H__

/* ------------------------------------------- include ----------------------------------------- */
#include "def.h"
//默认	
#include "stdio.h"      
#include "math.h"  
#include "string.h"

/* ------------------------------------- define/typedef/enum ----------------------------------- */
//在def.h中定义
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

typedef uint8_t sqStatus;      			/* sqStatus是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int16_t sqElemType;  				/* sqElemType类型根据实际情况而定，这里假设为int */

#define SQMAXSIZE 20 					/* 存储空间初始分配量 */
typedef struct
{
	sqElemType data[SQMAXSIZE+1];  		/* 数组，存储数据元素 */
	int length;                      	/* 线性表当前长度,外部逻辑是1-N */
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
//打印

extern sqStatus sqVisit (sqElemType c);								//打印一个元素
extern sqStatus sqListTraverse (SqList L);							//打印全部

//内部操作函数，外部索引逻辑是1-n
extern sqStatus sqInitList (SqList *L); 							//初始
extern sqStatus sqClearList (SqList *L);							//清除
extern sqStatus sqListEmpty (SqList L);								//空？
extern sqStatus sqGetElem (SqList L, int i, sqElemType *e);			//取元素
extern int16_t sqListLength (SqList L);								//取长度
extern int16_t sqLocateElem (SqList L, sqElemType e);				//查找
extern sqStatus sqListDelete (SqList *L, int i, sqElemType *e);	//删除
extern sqStatus sqListInsert (SqList *L, int i, sqElemType e);		//插入

//高级操作
extern sqStatus sqDelMin (SqList *L , sqElemType *value);			//删最小
extern void sqDelAllX (SqList *L , sqElemType x);					//删x
extern void sqDelAllX_Opt1 (SqList *L, sqStatus x);					//删x优化
extern void sqDelAllX_Opt2 (SqList *L, sqElemType x);				//删x优化
extern void sqUnionList (SqList *La, SqList Lb);					//拼接sqA,sqB
extern void sqInversion (SqList *L);								//逆置

//有序
extern boolean_t sqDelSeqListEqual (SqList *L);						//删相等
extern sqStatus sqDelSeqListMin2Max (SqList *L, sqElemType min_data, sqElemType max_data);		//删min到max
extern boolean_t sqDelSeqListMin2Max2 (SqList *L, sqElemType min_data, sqElemType max_data);//删min到max
extern boolean_t sqUnionSeqList (SqList A, SqList B, SqList *C);	//拼接sqA,sqB拼完还是有序


//数组
extern int16_t arraySeqArraySearchInsert (int16_t A[], int size_max, sqElemType x);	//查找有序数组，没有就插入
extern uint8_t arrayMajorElements (int A[], int size);					//取数组主元素
extern int arrayABMedian (int A[], int B[], int n);						//取数组A,B的中位数
extern int arryMiniPositInteger (int A[], int size);					//取数组最小未出现的正整数
extern boolean_t arrayInverse (int16_t A[], int left, int right, int arraySize); //指定数组区域逆置
extern void arrayAB2BA (int16_t A[], int m, int n, int arraySize);		//让数组[A，B]变成[B，A]
extern void arrayRotateLeft (int16_t R[], int n, int p);				//让数组循环左移



#endif  /*  __SQLIST_H__  */
