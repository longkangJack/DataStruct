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
void ListmyPush(List* plist,DataType x)
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
void ListyourPush(List* plist, DataType x)
{
	ListNode* s = _BuyNode(x);
	assert(s != NULL);
	if (s == NULL)
		return;
	plist->Last->next = s;
	plist->Last = s;
	plist->size++;
}
void reservelist(List* plist,List* pylist)
{
	ListNode* p;
	ListNode* q;
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
	}
	if (pylist->First->next&&pylist->First->next->next)
	{
		p = pylist->First->next;
		q = p->next;
		p->next = NULL;
		while (q)
		{
			p = q;
			q = q->next;
			p->next = pylist->First->next;
			pylist->First->next = p;
		}
	}
}
void DestoryList(List* plist, List* pylist)
{
	ListNode* p = plist->First->next;
	ListNode* q = pylist->First->next;
	while (p != NULL)
	{
		plist->First->next = p->next;
		free(p);
		p = plist->First->next;
	}
	plist->First = plist->Last = NULL;
	plist->size = 0;
	while (p != NULL)
	{
		pylist->First->next = p->next;
		free(p);
		p = pylist->First->next;
	}
	pylist->First = pylist->Last = NULL;
	pylist->size = 0;
}
void ContactList(List* plist, List* pylist)
{
	
	ListNode* p = plist->First->next;
	ListNode* q = pylist->First->next;
	ListNode* x = p;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = q;
	plist->Last = pylist->Last;
	plist->size += pylist->size;	
	pylist->size = 0;
	pylist->Last = pylist->First;
}
