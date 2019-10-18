#include"stack.h"
int main()
{
	//int ret = 0;
	//SeqStack st;//定义顺序栈
	//SeqStackInit(&st, STACK_SIZE);
	//SeqStackPush(&st, 1);
	//SeqStackPush(&st, 2);
	//SeqStackPush(&st, 3);
	//SeqStackPush(&st, 4);
	//SeqStackPush(&st, 5);
	//SeqStackPush(&st, 6);
	//SeqStackPush(&st, 7);
	//SeqStackPush(&st, 8);
	//ret = SeqStackTop(&st);//先拿到栈顶元素
	//SeqStackPop(&st);//然后出栈
	//SeqStackPush(&st, 9);
	//SeqStackShow(&st);//显示栈
	ListStack st;//指针栈  需要调用二级指针
	ListStackInit(&st);
	ListStackPush(&st, 1);
	ListStackPush(&st, 2);
	ListStackPush(&st, 3);
	ListStackShow(st);//显示链栈 
	printf("==============\n");
	ListStackPop(&st);//出栈
	ListStackShow(st);
	system("pause");
	return 0;
}