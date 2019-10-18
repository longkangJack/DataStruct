#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#define STACK_SIZE 8
#define DataType int
//typedef struct SeqStack
//{
//	DataType *Base;
//	size_t capacity;
//	int  top;
//}SeqStack;
//
//void SeqStackInit(SeqStack *pst, int sz);
//bool SeqStackPush(SeqStack* pst, int x);
//bool SeqStackPop(SeqStack* pst);
//void SeqStackShow(SeqStack* pst);
//DataType SeqStackTop(SeqStack* pst);
typedef struct StackNode
{
	DataType data;
	struct StackNode *next;
}StackNode;
typedef StackNode* ListStack;
void ListStackInit(ListStack* pst);
void ListStackPush(ListStack* pst, DataType x);
void ListStackShow(ListStack pst);
void ListStackPop(ListStack* pst);







