#include"Common.h"
#define DataType int
typedef struct ListNode
{
	DataType  data;
	struct ListNode *next;
}ListNode;
typedef struct SList
{
	struct ListNode *first;
	struct ListNode *last;
	size_t size;
}SList;
ListNode* BuyNode(int x);
void SListInit(SList *plist);
void SListPushback(SList *plist, DataType x);
void SListShow(SList *plist);
void SListReserve(SList *plist);
///////////////
ListNode* BuyNode(int x)
{
	ListNode *S = (ListNode*)malloc(sizeof(ListNode));
	assert(S != NULL);
	S->next = NULL;
	S->data = x;
	return S;
}
void SListInit(SList *plist)
{
	ListNode *S = BuyNode(0);
	plist->first = plist->last = S;
	plist->size = 0;
}
void SListPushback(SList *plist, DataType x)
{
	ListNode *S = BuyNode(x);
	if (S == NULL)
		return;
	plist->last->next = S;
	plist->last = S;
	plist->size++;
}
void SListShow(SList *plist)
{
	ListNode *p;
	p = plist->first->next;
	while (p != NULL)
	{

		printf("%d->", p->data);
		p = p->next;
	}
	printf("--over\n");
}
void SListReserve(SList *plist)
{
	ListNode *p;
	ListNode *q;
	if (plist->first->next&&plist->first->next->next)
	{
		p = plist->first->next;
		q = p->next;
		p->next = NULL;
		while (q)
		{
			p = q;
			q = q->next;
			p->next = plist->first->next;
			plist->first->next = p;
		}
	}
}

