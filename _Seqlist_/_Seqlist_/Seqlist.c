#include"common.h"
//函数的实现
void SeqListInit(SeqList* psl, DataType sz)
{
	psl->capacity = sz > CAPACITY ? sz : CAPACITY;
	psl->Base = (DataType*)malloc(sizeof(DataType)* (psl->capacity));
	psl->size = 0;
}
bool SeqListIsempty(SeqList* psl)
{

	DataType i = 0;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->Base[i] != 0)
		{
			return false;
		}
	}
	return true;
}
bool SeqListIsFull(SeqList* psl)
{
	return psl->size >= psl->capacity;
}
bool SeqListPushBack(SeqList* psl, DataType x)
{
	assert(psl!=NULL);
	if (SeqListIsFull(psl))
	{
		printf("顺序表已满,%d不能插入\n", x);
	}
	psl->Base[psl->size] = x;
	psl->size++;
	return true;
}
void SeqList_show(SeqList* psl)
{
	DataType i = 0;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->Base[i]);
	}
	printf("\n");
}
bool SeqListPushFront(SeqList* psl, DataType x)
{
	DataType i = 0;
	assert(psl != NULL);
	if (SeqListIsFull(psl))
	{
		printf("顺序表已满 x不能插入\n", x);
	}
	for (i = psl->size; i>0; i--)
	{
		psl->Base[i] = psl->Base[i-1];
	}
	psl->Base[i] = x;
	psl->size++;
	return true;
}
size_t SeqListLength(SeqList* psl)
{
	assert(psl);
	return psl->size;
}
void SeqListclear(SeqList* psl)
{
	assert(psl);
	if (SeqListIsempty(psl))
	{
		printf("顺序表为空");
		
	}
	else
	{
		DataType i = 0;
		for (i = 0; i < psl->size; i++)
		{
			psl->Base[i] = 0;
		}
	}
}
void SeqListSort(SeqList* psl)
{
	DataType BegainNumber = 0;
	DataType LastNumber = 0;
	DataType tmp = 0;
	for (BegainNumber = 0; BegainNumber < (psl->size)-1; BegainNumber++)
	{
		for (LastNumber = 0; LastNumber < (psl->size) - BegainNumber - 1; LastNumber++)
		{
			if (psl->Base[LastNumber]>psl->Base[LastNumber + 1])
			{
				tmp = psl->Base[LastNumber];
				psl->Base[LastNumber] = psl->Base[LastNumber + 1];
				psl->Base[LastNumber + 1] = tmp;
			}
		}
	}
}