#include"common.h"
//函数的实现
void SeqListInit(SeqList* psl, DataType sz)
{
	psl->capacity = sz > CAPACITY ? sz : CAPACITY;
	psl->Base = (DataType*)malloc(sizeof(DataType)* (psl->capacity));
	psl->size = 0;
}
bool SeqlistInc(SeqList* psl)
{
	assert(psl != NULL);
	psl->Base = realloc(psl->Base, sizeof(DataType)* 2);
	if (psl->Base == NULL)
	{
		printf("内存开辟失败>");
		psl->capacity += 2;
		return true;
	}
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
		psl->size = 0;
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
void SeqListReverse(SeqList* psl)
{
	DataType i = 0;
	DataType Left = 0;
	DataType Right = (psl->size) - 1;
	DataType tmp = 0;
	while (Left < Right)
	{
		tmp = psl->Base[Left];
		psl->Base[Left] = psl->Base[Right];
		psl->Base[Right] = tmp;
		Left++;
		Right--;
	}
}
bool SeqListModiftByPos(SeqList* psl, int pos, DataType item)
{
	assert(psl != NULL);
	if (SeqListIsempty(psl))
	{
		return false;
	}
	if (pos<0 || pos>psl->size - 1)
	{
		printf("输入的位置不合法\n");
		return false;
	}
	psl->Base[pos] = item;
	return true;
}
void ModifyByValue(SeqList* psl,int val,int x)
{
	DataType i = 0;
	while (psl != NULL&& psl->Base[i] != val)
	{
		i++;
	}
	psl->Base[i] = x;
}
int FindByPos(SeqList* psl, int pos,DataType* ret)
{
	if (pos<0 || pos>psl->size)
	{
		printf("输入的位置不合法>");
		return 0;
	}
	*ret = psl->Base[pos];
	return *ret;
}
int FindByVal(SeqList* psl, int val, DataType* ret)
{
	DataType i = 0;
	while (psl != NULL && psl->Base[i] != val&&i<psl->size)
	{
		i++;
	}
	if (i < psl->size)
	{
		*ret = psl->Base[i];
		return *ret;
	}
	return -1;
}
bool Pop_back(SeqList* psl)
{
	DataType i = 0;
	if (psl->size == 0)
	{
		printf("顺序表为空，不能删除>");
		return false;
	}
	psl->size--;
	return true;
}
bool Pop_Front(SeqList* psl)
{
	int i = 0;
	if (SeqListIsempty(psl))
	{
		printf("顺序表为空，不能头删>");
		return false;
	}
		for (i = 0; i <psl->size-1; i++)
		psl->Base[i] = psl->Base[i + 1];
		psl->size--;
	return true;
}
void Destort_Seqlist(SeqList* psl)
{
	free(psl->Base);
	psl->Base = NULL;
	psl->capacity = psl->size = 0;
}
