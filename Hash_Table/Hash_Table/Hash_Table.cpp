#include"Common.h"
#include"Hash_table.h"
int main()
{
	int arr[] = { 49, 10, 32, 54,38, 65,97, 76, 13,27 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 0;
	HashTable ht;//定义一个哈希表数组
	HashTableInit(ht);
	for (int i = 0; i < P; i++)
	{
		HashTableInsert(ht, arr[i]);
	}
	HashTableShow(ht);
	printf("==========================\n");
	printf("请输入要删除的值\n");
	scanf_s("%d",&x);
	HashTableRemove(ht, x);
	HashTableShow(ht);
	return 0;
}




