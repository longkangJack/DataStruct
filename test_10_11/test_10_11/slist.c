#include"common.h"
//函数的实现
ListNode* _BuyNode(DataType x)
{
	ListNode* s = (ListNode*)malloc(sizeof(ListNode));
	assert(s != NULL);
	if (s == NULL)
		return NULL;
	s->next = NULL;
	s->data = x;
	return s;
}
void InitList(List* plist)
{
	ListNode* s = _BuyNode(0);
	plist->First = plist->Last = s;
	plist->size = 0;
}
void InitYourList(List* plist)
{
	ListNode* s = _BuyNode(0);
	plist->First = plist->Last = s;
	plist->size = 0;
}
//插入
void ListmyPop(List* plist,DataType x)
{
	ListNode* s = _BuyNode(x);
	plist->Last->next = s;
	plist->Last = s;
	plist->size++;
}
void ShowmyList(List* plist)
{
	ListNode* p = plist->First->next;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("over.\n");
}
void showyourlist(List* plist)
{
	ListNode* p = plist->First->next;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("--over.\n");
}
void ListyourPop(List* plist, DataType x)
{
	ListNode* s = _BuyNode(x);
	assert(s != NULL);
	if (s == NULL)
		return;
	plist->Last->next = s;
	plist->Last = s;
	plist->size++;
}
void reservelist(List* plist)
{
	ListNode* p;
	ListNode* q;
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
}
