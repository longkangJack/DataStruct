#include"Common.h"
#include"BinTree.h"
int main()
{
	BinTree bt;
	BinTreeInit(&bt);
	/*BinTreeCreate_1(&bt);*/
	/*bt = BinTreeCreate_2();*/
	BinTreeCreate(&bt);
	printf("VLR:");
	PreOrder(&bt);
	printf("\n");
	//
	printf("LVR:");
	InOrder(&bt);
	printf("\n");
	//
	printf("LRV:");
	PostOrder(&bt);
	printf("\n");
	return 0;
}
