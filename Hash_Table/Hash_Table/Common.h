#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>
#include<string.h>
#define P 13
#define DataType int
typedef struct HashNode
{
	DataType data;
	struct HashNode* link;
}HashNode;//哈希节点
typedef HashNode* HashTable[P];
void HashTableInit(HashTable pht);
void HashTableShow(HashTable pht);
bool HashTableInsert(HashTable pht, DataType x);
HashNode* HashTableFind(HashTable pht, DataType x);
bool HashTableRemove(HashTable pht, DataType x);
////////////////////////////////
//除留余数法法求下标
int Hash(DataType Key)
{
	return (Key % P);
}
void HashTableInit(HashTable pht)
{
	for (int i = 0; i < P; i++)
	{
		pht[i] = NULL;
	}
}
bool HashTableInsert(HashTable pht, DataType x)
{
	int index = Hash(x);
	HashNode* s = (HashNode*)malloc(sizeof(HashNode));
	if (s == NULL)
		return false;
	s->data = x;
	s->link = pht[index];
	pht[index] = s;
	return true;
}
void HashTableShow(HashTable pht)
{
	for (int i = 0; i < P; i++)
	{
		printf("%d:>", i);
		HashNode* p = pht[i];
		while (p != NULL)
		{
			printf("%d-->", p->data);
			p = p->link;
		}
		printf("Nul.\n");
	}
}
HashNode* HashTableFind(HashTable pht, DataType x)
{
	int index = Hash(x);
	HashNode* p = pht[index];
	while (p != NULL && p->data != x)
	{
		p = p->link;
	}
	return p;
}
bool HashTableRemove(HashTable pht, DataType x)
{
	HashNode* p = HashTableFind(pht, x);
	if (p == NULL)
		return false;
	int index = Hash(x);
	HashNode* pre = pht[index];
	if (pre == p)
		pht[index] = p->link;
	else
	{
		while (pre->link != p)
			pre = pre->link;
	}
	free(p);
	return true;
}













