#include"stack.h"
int main()
{
	//int ret = 0;
	//SeqStack st;//����˳��ջ
	//SeqStackInit(&st, STACK_SIZE);
	//SeqStackPush(&st, 1);
	//SeqStackPush(&st, 2);
	//SeqStackPush(&st, 3);
	//SeqStackPush(&st, 4);
	//SeqStackPush(&st, 5);
	//SeqStackPush(&st, 6);
	//SeqStackPush(&st, 7);
	//SeqStackPush(&st, 8);
	//ret = SeqStackTop(&st);//���õ�ջ��Ԫ��
	//SeqStackPop(&st);//Ȼ���ջ
	//SeqStackPush(&st, 9);
	//SeqStackShow(&st);//��ʾջ
	ListStack st;//ָ��ջ  ��Ҫ���ö���ָ��
	ListStackInit(&st);
	ListStackPush(&st, 1);
	ListStackPush(&st, 2);
	ListStackPush(&st, 3);
	ListStackShow(st);//��ʾ��ջ 
	printf("==============\n");
	ListStackPop(&st);//��ջ
	ListStackShow(st);
	system("pause");
	return 0;
}