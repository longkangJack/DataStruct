//Ö÷º¯Êý
#include"Stack.h"
int main()
{
	int ret = 0;
	SeqStack st;
	StackInit(&st, STACK_CAPACITY_SIZE);
	SeqStackPush(&st, 1);
	SeqStackPush(&st, 2);
	SeqStackPush(&st, 3);
	SeqStackPush(&st, 4);
	SeqStackPush(&st, 5);
	SeqStackPush(&st, 6);
	SeqStackPush(&st, 7);
	SeqStackPush(&st, 8);
	ret = SeqStackTop(&st);
	SeqStackPop(&st);
	SeqStackPush(&st, 9);
	SeqStackShow(&st);
	return 0;
}