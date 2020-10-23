/**************************************************************************************************
* �ļ�:  StaticLinkList.h
*        
* ˵��:  
*        
* ����:  ���Ϸ�  10/22/2020
**************************************************************************************************/
#ifndef __STATICLINKLIST_H__
#define __STATICLINKLIST_H__

/* ------------------------------------------- include ----------------------------------------- */
#include "def.h"

/* ------------------------------------- define/typedef/enum ----------------------------------- */
//��������ǳ���Ҫ�ģ��жϵ�һ��Ԫ�ؾ����������α꣬����һ�ģ��ܶຯ����Ҫ���Ÿ�
#define SLLISTMAXSIZE 1000 /* �洢�ռ��ʼ������ */

typedef int slListStatus;           /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef char slListElemType;        /* ElemType���͸���ʵ������������������Ϊchar */

/* ���Ա�ľ�̬����洢�ṹ */
////�ճ������������α�
////StaticLinkList[0]�ǿ��пռ���α�
////StaticLinkList[SLLISTMAXSIZE-1]��ʹ�ÿռ���α�
////StaticLinkList����ı�����������Ϊָ��ʹ��
typedef struct 
{
    slListElemType data;
    int cur;  /* �α�(Cursor) ��Ϊ0ʱ��ʾ��ָ�� */
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
//��ӡ
extern void slListPrintfTraverse (StaticLinkList L);		//��ӡ
//�ײ�������ͷſռ�
extern int slList_Malloc (StaticLinkList space);			//����
extern void slList_Free (StaticLinkList space, int k);		//�ͷ�
//�ڲ�����
extern slListStatus slListInit (StaticLinkList space);		//��ʼ��
extern slListStatus slListClear (StaticLinkList space);		//���
extern slListStatus slListEmpty (StaticLinkList space);		//�գ�
extern int slListLength (StaticLinkList L);					//����
extern slListStatus slListInsert (StaticLinkList L, int i, slListElemType e);		//����
extern slListStatus slListDelete (StaticLinkList L, int i);							//ɾ��





#endif  /*  __STATICLINKLIST_H__  */

