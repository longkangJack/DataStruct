//ÊµÏÖº¯Êý
#include"common.h"
DListNode* BuyNode(int x)
{
	DListNode* s = (DListNode*)malloc(sizeof(DListNode));
	if (s == NULL)
		return NULL;
	s->data = x;
	s->next = s->prev = NULL;
	return s;
}
void InitList(List* pdlist)
{
	DListNode* s = BuyNode(0);
	pdlist->first = pdlist->last = s;
	pdlist->size = 0;
}
bool push_back(List* pdlist,DataType x)
{
	DListNode* s = BuyNode(x);
	if (s == NULL)
		return false;
	pdlist->last->next = s;
	s->prev = pdlist->last;
	pdlist->last = s;
	pdlist->size++;	
	return true;
}
bool push_front(List* pdlist, DataType x)
{
	DListNode* s = BuyNode(x);
	if (s == NULL)
		return false;
	s->next = pdlist->first->next;
	s->prev = pdlist->first;
	pdlist->first->next = s;
	pdlist->size++;
	return true;
}
void show_list(List* pdlist)
{
	DListNode* p = pdlist->first->next;
	while (p)
	{
		printf("<-%d->", p->data);
		p = p->next;
	}
	printf("--over\n");
}

int DListLength(List* pdlist)
{
	DListNode* p = pdlist->first->next;
	if (p == NULL)
		return 0;
	else
	return pdlist->size;
}
void ClearList(List* pdlist)
{
	DListNode* p = pdlist->first->next;
	while (p)
	{
		p->next->prev = pdlist->first;
		pdlist->first->next = p->next;
		free(p);
		p = pdlist->first->next;
	}
	pdlist->size = 0;
}