#ifndef _TEST_
#define _TEST_
#include"common.h"
#include"bintree.h"
#include"HHeap.h"

void main()
{
	int ar[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int n = sizeof(ar) / sizeof(int);
	Heap hp;
	int i;
	HeapInit(&hp, n);
	for (i = 0; i<n; ++i)
   {
		HeapInsert(&hp, ar[i]);
	}
	HeapShow(&hp);
	HeapRemove(&hp);
	HeapShow(&hp);
	HeapRemove(&hp);
	HeapShow(&hp);
	HeapDestroy(&hp);
}
int main()
{
	char *str = "ABC##DE##F##G#H##";
	char *str1 = "ABC##D#F##GE##H##";
	BinTree bt,bt1;//节点一级指针
	int i = 0;
	int j = 0;
	BinTreeInit(&bt);
	BinTreeInit(&bt1);
	//BinTreeCreate(&bt);
	BinTreeCreateByStr(&bt,str,&i);
	BinTreeCreatByStr(&bt1,str1,&j);
	//BinTreeInit(&bt);
	/*bt = BinTreeCreate_2();*/
	return 0;
} 
#endif