/**************************************************************************************************
* 文件:  LinkList.h
*        
* 说明:  
*        
* 作者:  日南方  10/20/2020
**************************************************************************************************/
#ifndef __LINKLIST_H__
#define __LINKLIST_H__

/* ------------------------------------------- include ----------------------------------------- */
#include "def.h"
//malloc free srand
#include <stdlib.h>
// time rand
#include <time.h>

/* ------------------------------------- define/typedef/enum ----------------------------------- */

typedef int linkStatus;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int linkElemType;/* ElemType类型根据实际情况而定，这里假设为int */

typedef struct LinkListNode
{
	linkElemType data;
	struct LinkListNode* next;
}LinkListNode_S;
//已经是一阶指针了，在函数传递变量的时候，
//一阶指针的地址变，但是值不变，就是变量的地址不变，就可以修改全局变量了。
typedef struct LinkListNode* LinkList; /* 定义LinkList */


/* ------------------------------------------- variable ---------------------------------------- */
#ifdef __LINKLIST_C__
	#define LINKLIST_EXT
#else
	#define LINKLIST_EXT		extern
#endif
//第一组(自动malloc free)
LINKLIST_EXT LinkList linkList_point1_head;
	
//第二组（手动申请变量，内部操作用后缀manu，高级操作默认malloc注意修改）
//手动申请变量，总归不灵活，只能使用在固定死的长度。
//要是计算机不支持malloc函数等指针操作的话，可以使用静态数组
LINKLIST_EXT LinkList linkList_point2_head;
LINKLIST_EXT LinkListNode_S linkList_var2_head;
	
LINKLIST_EXT LinkList linkList_point2_1;
LINKLIST_EXT LinkListNode_S linkList_var2_1;
	
LINKLIST_EXT LinkList linkList_point2_2;
LINKLIST_EXT LinkListNode_S linkList_var2_2;
	
LINKLIST_EXT LinkList linkList_point2_3;
LINKLIST_EXT LinkListNode_S linkList_var2_3;
	
LINKLIST_EXT LinkList linkList_point2_4;
LINKLIST_EXT LinkListNode_S linkList_var2_4;





#if 0
LINKLIST_EXT S32 var
#ifdef __LINKLIST_C__
= 0
#endif
;
#endif

/* ------------------------------------------- funtion ----------------------------------------- */
/* externs */

//打印
extern void linkListPrintTraverse (LinkList L);					//打印顺序
extern void linkListPrintInversion (LinkList L);				//打印逆置

//内部函数
extern linkStatus 	linkListInit (LinkList* L);					//初始化（malloc）
extern void 		linkListRandomHeadInsertion (LinkList* L, int n);				//随机初始化
extern void 		linkListRandomTailInsertion (LinkList* L, int n);				//随机初始化
extern void 		linkListClear (LinkList* L);				//清空（free）
extern linkStatus 	linkListEmpty (LinkList L);					//空？
extern int16_t 		linkListLength (LinkList L);				//长度
extern linkStatus 	linkListGetElem (LinkList L, int i, linkElemType* e);			//索引
extern int16_t 		linkListLocateElem (LinkList L, linkElemType e);				//搜索
extern linkStatus 	linkListInsert (LinkList* L, int i, linkElemType e);			//在索引处插入（malloc）
extern linkStatus 	linkListDelete (LinkList* L, int i, linkElemType* e);			//删除指定索引(free)
////手动变量申请的不同地方
extern linkStatus 	linkListAssign ();							//初始化
extern void 		linkListClearManu (LinkList L);				//清空
extern linkStatus 	linkListInsertManu (LinkList L, LinkList node, int i, linkElemType e);	//在索引处插入
extern linkStatus 	linkListDeleteManu (LinkList L, int i, linkElemType* e);					//删除指定索引


//高级函数
extern void LinkListDelx (LinkList* L, int x);					//删除x，递归（默认free）
extern void LinkListDelx1 (LinkList L, int x);					//删除x（默认free）
extern void LinkListDelMin (LinkList L);						//删除最小（默认free）
extern void linkListDelMin2Max (LinkList L, int min, int max);	//删除区间内的值（默认free）
extern void linkListInversion (LinkList L);						//逆置



#endif  /*  __LINKLIST_H__  */

