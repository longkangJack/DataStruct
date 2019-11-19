#include"Common.h"
//堆结构
int main()
{
	int ar[] = { 27, 15,19, 18, 28, 34, 65, 49, 25, 37 };
	int n = sizeof(ar) / sizeof(int);
	Heap hp;
	int i;
	HeapInit(&hp, n);
	for (i = 0; i < n; ++i)
	{
		HeapInsert(&hp, ar[i]);
	}
	HeapShow(&hp);
	HeapRemove(&hp);
	HeapShow(&hp);
	HeapRemove(&hp);
	HeapShow(&hp);
	HeapDestroy(&hp);
	system("color 90");
	return 0;
}

