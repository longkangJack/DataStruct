//Í·ÎÄ¼þ

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#define DataType int
#define STACK_CAPACITY_SIZE 8
#define STACK_INT_SIZE 5

void StackInit(SeqStack *pst, int sz);
void SeqStackPush(SeqStack *pst, DataType x);
bool SeqStackIsFull(SeqStack *pst);
bool SeqStackIsEmpty(SeqStack *pst);
void SeqStackPop(SeqStack *pst);
DataType SeqStackTop(SeqStack *pst);
void SeqStackShow(SeqStack *pst);
typedef struct SeqStack
{
	DataType* Base;
	size_t capacity;
	int top;
}SeqStack;

