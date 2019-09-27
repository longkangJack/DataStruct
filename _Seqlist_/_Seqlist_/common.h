#ifndef COMMON_H
#define COMMOM_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>

#define DataType int
#define CAPACITY 8
typedef struct SeqList
{
	DataType* Base;//指向表头的指针
	size_t size;//顺序表当前存储的个数
	size_t capacity;//顺序表容量
}SeqList;
bool SeqListIsFull(SeqList* psl);
void SeqListInit(SeqList* psl, DataType sz);
bool SeqListPushBack(SeqList* psl, DataType x);
void SeqList_show(SeqList* psl);
bool SeqListPushFront(SeqList* psl, DataType x);
size_t SeqListLength(SeqList* psl);
void SeqListclear(SeqList* psl);
bool SeqListIsempty(SeqList* psl);
void SeqListSort(SeqList* psl);
#endif