#ifndef _COMMON_
#define _COMMON_

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#define DataType int

typedef struct SListNode
{
	DataType data;//�������������
	struct SListNode* next;//�������ָ����
}SListNode;

typedef struct SList
{
	SListNode *First;
	SListNode *Last;
	size_t size;
}SList;//�����е�ͷ��βָ�� ��Ҫ�ýṹ�嶨������.
SListNode* _Buynode(DataType x);
void InitList(SList* plist);
bool SListpushback(SList* plist,DataType x);
void SListshowlist(SList* plist);
bool SListpushfront(SList* plist,DataType x);
bool SListPopBack(SList* plist, DataType x);
SListNode* SListFindByVal(SList* plist, DataType x);
bool SListDeleByVal(SList* plist, DataType x);
bool SListPopFront(SList* plist, DataType x);
SListNode* ReservrList(SList* plist);
int SListLength(SList* plist);
void SListClear(SList* plist);
void DestorySList(SList* plist);
void InsertByVal(SList* plist,DataType x);
#endif