//实现函数
#include"common.h"
SListNode* _Buynode(DataType x)
{
	SListNode* S = (SListNode*)malloc(sizeof(SListNode));
	assert(S != NULL);
	if (S == NULL)
		return NULL;
	S->next = NULL;
	S->data = x;
	return S;
}
void InitList(SList* plist)
{
	SListNode *S = _Buynode(0);
	plist->First = plist->Last = S;
	plist->size = 0;
}
bool SListpushback(SList* plist,DataType x)
{
	SListNode* S = _Buynode(x);
	if (S == NULL)
		return false;
	plist->Last->next = S;
	plist->Last = S;
	plist->size++;
	return true;
}
bool SListpushfront(SList* plist,DataType x)
{
	assert(plist != NULL);
	
	SListNode* p = _Buynode(x);
	if (p == NULL)
		return false;
	p->next = plist->First->next;
	plist->First->next = p;
	if (plist->size == 0)
		plist->Last = p;
	plist->size++;
	return true;
}
void SListshowlist(SList* plist)
{
	SListNode* p = plist->First->next;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("over.\n");
}
bool SListPopBack(SList* plist, DataType x)
{
	SListNode* p = plist->First;
	assert(plist != NULL);
	if (plist->size == 0)
	{
		return false;
	}
	while (p->next!=plist->Last)
	{
		p = p->next;
	}
	p->next = NULL;
	free(plist->Last);
	plist->Last = p;
	plist->size--;
	return true;
}
bool SListPopFront(SList* plist, DataType x)
{
	SListNode* p = plist->First->next;
	if (plist->size == 0)
		return false;
	plist->First->next = p->next;
	free(p);
	plist->size--;
	if (plist->size == 0)
		plist->Last = plist->First;
		return true;
}
SListNode* SListFindByVal(SList* plist, DataType x)
{
	SListNode* p = plist->First->next;
	/*while (p != NULL && p->data != x)
		p = p->next;
	return p;*/
	while (p != NULL)
	{
		if (p->data == x)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}
SListNode* ReservrList(SList* plist)
{
	SListNode* q;
	SListNode* p;
	if (plist->First->next&&plist->First->next->next)
	{
		p = plist->First->next;
		q = p->next;
		p->next = NULL;
		while (q)
		{
			p = q;
			q = q->next;
			p->next = plist->First->next;
			plist->First->next = p;
		}
		return plist->First;
	}
	return plist->First;
}
int SListLength(SList* plist)
{
	return plist->size;
}
void SListClear(SList* plist)
{
	SListNode* p = plist->First->next;
	while (p != NULL)
	{
		plist->First->next = p->next;
		free(p);
		p = plist->First->next;
	}
	plist->First = plist->Last = NULL;
	plist->size = 0;

}
void DestorySList(SList* plist)
{
	SListClear(plist);
	free(plist->First);
	plist->First = plist->Last = NULL;//防止在内存中成为野指针
}
void InsertByVal(SList* plist, DataType x)
{
	SListNode* p = plist->First;
	while (p->next != NULL&&x > p->next->data)
	{
		p = p->next;
	}
	SListNode* s = _Buynode(x);
	if (p->next == NULL)
	{
		p->next = s;
		plist->Last = s;
	}
	else
	{
		s->next = p->next;
		p->next = s;
	}
	plist->size++;
}
bool SListDeleByVal(SList* plist, DataType x)
{
	SListNode* q;
	SListNode* p = plist->First;

	while (p != NULL && p->next->data != x)
		p = p->next;
	if (p == NULL)
		return false;
	q = p->next;
	if (p->next == plist->Last)
		plist->Last = p;
	p->next = q->next;
	free(q);
	return true;
}