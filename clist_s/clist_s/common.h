#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//ͷ�ļ�
#include<stdio.h>
#include<stdio.h>
#include<stdbool.h>
#define DataType int
typedef struct DListNode
{
	DataType data; //������
	struct DListNode* next;//���ָ��
	struct DListNode* prev;//ǰ��ָ��
}DListNode;
typedef struct List
{
	DListNode* first;
	DListNode* last;
	size_t size;
}List;

void InitList(List* pdlist);
bool push_back(List* pdlist,DataType x);
bool push_front(List* pdlist,DataType x);
void show_list(List* pdlist);
int DListLength(List* pdlist);
void ClearList(List* pdlist);
