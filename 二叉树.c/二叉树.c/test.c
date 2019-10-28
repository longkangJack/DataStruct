#include"common.h"
#include"bintree.c"



int main()

{

	char *str = "ABC##DE##F##G#H##";

	char *str1 = "ABC##D#F##GE##H##";

	int i = 0, j = 0;

	BinTree bt, bt1;

	BinTreeInit(&bt);

	BinTreeInit(&bt1);

	//BinTreeCreate(&bt);

	BinTreeCreateByStr(&bt, str, &i);

	BinTreeCreateByStr(&bt1, str1, &j);



	printf("VLR   :");

	PreOrder(&bt);

	printf("\n");

	printf("VLR NR:");

	PreOrderNoR(&bt);

	printf("\n");



	printf("LVR:");

	InOrder(&bt);

	printf("\n");

	printf("LRV:");

	PostOrder(&bt);

	printf("\n");

	printf("Level:");

	LevelOrder(&bt);

	printf("\n");



	printf("Size = %d\n", Size(&bt));

	printf("Hegith = %d\n", Height(&bt));



	BinTreeNode *p = Find(&bt, 'B');

	p = Parent(&bt, 'H');



	//Clone(&bt, &bt1);

	bool flag = Equal(&bt, &bt1);



	return 0;

}



/*

int main()

{

LinkQueue LQ;

LinkQueueInit(&LQ);

LinkQueueEn(&LQ, 1);

LinkQueueEn(&LQ, 2);

LinkQueueEn(&LQ, 3);

LinkQueueEn(&LQ, 4);

LinkQueueEn(&LQ, 5);



LinkQueueShow(&LQ);



LinkQueueDestroy(&LQ);

return 0;

}