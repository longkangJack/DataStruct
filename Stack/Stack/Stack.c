//函数的实现
#include"Stack.h"
bool SeqStackIsFull(SeqStack *pst)
{
	if (pst->top == pst->capacity)
		return true;
	return false;
}
bool SeqStackIsEmpty(SeqStack *pst)
{
	if (pst->top == 0)
		return true;
	return false;
}

void StackInit(SeqStack *pst, int sz)
{
	pst->capacity = sz > STACK_CAPACITY_SIZE ? sz : STACK_CAPACITY_SIZE;
	pst->Base = (DataType*)malloc(sizeof(DataType)*pst->capacity);
	pst->top = 0;
}
void SeqStackPush(SeqStack *pst, DataType x)
{
	if (SeqStackIsFull(pst))
	{
		printf("栈已满,%d不能插入\n", x);
		return;
	}
	pst->Base[pst->top] = x;
	pst->top++;
}
DataType SeqStackTop(SeqStack *pst)
{
	if (SeqStackIsEmpty(pst))
	{
		printf("栈已空，不能取栈");
		return;
	}
	return pst->Base[pst->top - 1];
}
void SeqStackPop(SeqStack *pst)
{
	if (SeqStackIsEmpty(pst))
	{
		printf("栈已空，不能出栈");
		return;
	}
	pst->top--;
}
void SeqStackShow(SeqStack *pst)
{
	for (int i = pst->top - 1; i >= 0; i--)
	{
		printf("%d\n", pst->Base[i]);
	}
}