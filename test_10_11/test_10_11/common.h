#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define DataType int
typedef struct ListNode
{
	DataType data;
	struct ListNode* next;
}ListNode;
typedef struct List
{
	ListNode* First;
	ListNode* Last;
	size_t size;
}List;
void InitList(List* plist);
void ListyourPop(List* plist,DataType x);
void InitYourList(List* plist);
void ShowmyList(List* plist);
void showyourlist(List* plist);
void ListmyPop(List* plist, DataType x);
void reservelist(List* plist);