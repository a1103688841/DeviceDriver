/**************************************************************************************************
* 文件:  StaticLinkList.h
*        
* 说明:  
*        
* 作者:  日南方  10/22/2020
**************************************************************************************************/
#ifndef __STATICLINKLIST_H__
#define __STATICLINKLIST_H__

/* ------------------------------------------- include ----------------------------------------- */
#include "def.h"

/* ------------------------------------- define/typedef/enum ----------------------------------- */
//这个常量非常重要的，判断第一个元素就是用他的游标，名字一改，很多函数都要跟着改
#define SLLISTMAXSIZE 1000 /* 存储空间初始分配量 */

typedef int slListStatus;           /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef char slListElemType;        /* ElemType类型根据实际情况而定，这里假设为char */

/* 线性表的静态链表存储结构 */
////空出来两个功能游标
////StaticLinkList[0]是空闲空间的游标
////StaticLinkList[SLLISTMAXSIZE-1]是使用空间的游标
////StaticLinkList申请的变量名可以作为指针使用
typedef struct 
{
    slListElemType data;
    int cur;  /* 游标(Cursor) ，为0时表示无指向 */
} SLListComponent,StaticLinkList[SLLISTMAXSIZE];

/* ------------------------------------------- variable ---------------------------------------- */
#ifdef __STATICLINKLIST_C__
	#define STATICLINKLIST_EXT
#else
	#define STATICLINKLIST_EXT		extern
#endif

STATICLINKLIST_EXT StaticLinkList test_ssl;


#if 0
STATICLINKLIST_EXT S32 var
#ifdef __STATICLINKLIST_C__
= 0
#endif
;
#endif

/* ------------------------------------------- funtion ----------------------------------------- */

/* externs */
//打印
extern void slListPrintfTraverse (StaticLinkList L);		//打印
//底层申请和释放空间
extern int slList_Malloc (StaticLinkList space);			//申请
extern void slList_Free (StaticLinkList space, int k);		//释放
//内部操作
extern slListStatus slListInit (StaticLinkList space);		//初始化
extern slListStatus slListClear (StaticLinkList space);		//清空
extern slListStatus slListEmpty (StaticLinkList space);		//空？
extern int slListLength (StaticLinkList L);					//长度
extern slListStatus slListInsert (StaticLinkList L, int i, slListElemType e);		//插入
extern slListStatus slListDelete (StaticLinkList L, int i);							//删除





#endif  /*  __STATICLINKLIST_H__  */

