#include"stack.h"
//函数的实现
//顺序栈

//bool SeqStackFull(SeqStack* pst)
//{
//	if (pst->top >= pst->capacity)
//		return true;
//	return false;
//}
//bool SeqStackEmpty(SeqStack *pst)
//{
//	if (pst->top == 0)
//		return true;
//	return false;
//}
//void SeqStackInit(SeqStack *pst,int sz)
//{
//	pst->capacity = sz > STACK_SIZE ? sz : STACK_SIZE;
//	pst->Base = (DataType*)malloc(sizeof(DataType)*pst->capacity);
//	pst->top = 0;
//}
//bool SeqStackPush(SeqStack *pst, int x)
//{
//	if (SeqStackFull(pst))
//	{
//		printf("栈已满,%d不能入栈\n", x);
//		return false;
//	}
//	pst->Base[pst->top++] = x;
//	return true;
//}
//void SeqStackShow(SeqStack* pst)
//{
//	for (int i = pst->top-1; i >= 0; i--)
//	{
//		printf("%d\n", pst->Base[i]);
//	}
//}
//DataType SeqStackTop(SeqStack* pst)
//{
//	if (SeqStackEmpty(pst))
//	{
//		printf("栈已空,不能取栈\n");
//		return false;
//	}
//	return pst->Base[pst->top - 1];
//}
//bool SeqStackPop(SeqStack* pst)
//{
//	if (SeqStackEmpty(pst))
//	{
//		printf("栈已空,不能出栈\n");
//		return false;
//	}
//	pst->top--;
//}
DataType ListStackTop(ListStack *pst)
{
	assert(*pst != NULL);
	return (*pst)->data;

}
void ListStackInit(ListStack* pst)
{
	*pst = NULL;
}
void ListStackPush(ListStack* pst, DataType x)
{
	StackNode *node = (StackNode*)malloc(sizeof(StackNode));
	assert(node != NULL);
	node->data = x;
	node->next = *pst;
	*pst = node;
}
void ListStackShow(ListStack pst)
{
	StackNode *p = pst;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}
void ListStackPop(ListStack* pst)
{
	StackNode* p = *pst;//一级指针访问节点 二级指针访问链表
	(*pst) = p->next;
	free(p);
}
