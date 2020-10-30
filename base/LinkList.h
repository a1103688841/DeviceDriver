/**************************************************************************************************
* �ļ�:  LinkList.h
*        
* ˵��:  
*        
* ����:  ���Ϸ�  10/20/2020
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

typedef int linkStatus;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int linkElemType;/* ElemType���͸���ʵ������������������Ϊint */

typedef struct LinkListNode
{
	linkElemType data;
	struct LinkListNode* next;
}LinkListNode_S;
//�Ѿ���һ��ָ���ˣ��ں������ݱ�����ʱ��
//һ��ָ��ĵ�ַ�䣬����ֵ���䣬���Ǳ����ĵ�ַ���䣬�Ϳ����޸�ȫ�ֱ����ˡ�
typedef struct LinkListNode* LinkList; /* ����LinkList */


/* ------------------------------------------- variable ---------------------------------------- */
#ifdef __LINKLIST_C__
	#define LINKLIST_EXT
#else
	#define LINKLIST_EXT		extern
#endif
//��һ��(�Զ�malloc free)
LINKLIST_EXT LinkList linkList_point1_head;
	
//�ڶ��飨�ֶ�����������ڲ������ú�׺manu���߼�����Ĭ��mallocע���޸ģ�
//�ֶ�����������ܹ鲻��ֻ��ʹ���ڹ̶����ĳ��ȡ�
//Ҫ�Ǽ������֧��malloc������ָ������Ļ�������ʹ�þ�̬����
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

//��ӡ
extern void linkListPrintTraverse (LinkList L);					//��ӡ˳��
extern void linkListPrintInversion (LinkList L);				//��ӡ����

//�ڲ�����
extern linkStatus 	linkListInit (LinkList* L);					//��ʼ����malloc��
extern void 		linkListRandomHeadInsertion (LinkList* L, int n);				//�����ʼ��
extern void 		linkListRandomTailInsertion (LinkList* L, int n);				//�����ʼ��
extern void 		linkListClear (LinkList* L);				//��գ�free��
extern linkStatus 	linkListEmpty (LinkList L);					//�գ�
extern int16_t 		linkListLength (LinkList L);				//����
extern linkStatus 	linkListGetElem (LinkList L, int i, linkElemType* e);			//����
extern int16_t 		linkListLocateElem (LinkList L, linkElemType e);				//����
extern linkStatus 	linkListInsert (LinkList* L, int i, linkElemType e);			//�����������루malloc��
extern linkStatus 	linkListDelete (LinkList* L, int i, linkElemType* e);			//ɾ��ָ������(free)
////�ֶ���������Ĳ�ͬ�ط�
extern linkStatus 	linkListAssign ();							//��ʼ��
extern void 		linkListClearManu (LinkList L);				//���
extern linkStatus 	linkListInsertManu (LinkList L, LinkList node, int i, linkElemType e);	//������������
extern linkStatus 	linkListDeleteManu (LinkList L, int i, linkElemType* e);					//ɾ��ָ������


//�߼�����
extern void LinkListDelx (LinkList* L, int x);					//ɾ��x���ݹ飨Ĭ��free��
extern void LinkListDelx1 (LinkList L, int x);					//ɾ��x��Ĭ��free��
extern void LinkListDelMin (LinkList L);						//ɾ����С��Ĭ��free��
extern void linkListDelMin2Max (LinkList L, int min, int max);	//ɾ�������ڵ�ֵ��Ĭ��free��
extern void linkListInversion (LinkList L);						//����



#endif  /*  __LINKLIST_H__  */

