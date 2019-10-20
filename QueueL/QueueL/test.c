#include"Common.h"
//int main()
//{
//	//定义
//	SeqQueue Q;//队列
//	SeqQueueInit(&Q,DEFAULT_QUEUE_SIZE);
//	SeqQueueEn(&Q, 1);
//	SeqQueueEn(&Q, 2);
//	SeqQueueEn(&Q, 3);
//	SeqQueueEn(&Q, 1);
//	SeqQueueEn(&Q, 1);
//	SeqQueueShow(&Q);
//	printf("====================\n");
//	int ret = SeqQueueFront(&Q);
//	printf("%d 出队成功\n", ret);
//	SeqQueueDe(&Q);
//	SeqQueueShow(&Q);
//	SeqQueueDestory(&Q);
//	system("pause");
//
//	return 0;
//}
//int main()
//
//{
//
//	SeqCyQueue CQ;
//
//	SeqQueueCyInit(&CQ, 8);
//
//	SeqQueueCyEn(&CQ, 1);
//
//	SeqQueueCyEn(&CQ, 2);
//
//	SeqQueueCyEn(&CQ, 3);
//
//	SeqQueueCyEn(&CQ, 4);
//
//	SeqQueueCyEn(&CQ, 5);
//
//
//
//	SeqQueueCyShow(&CQ);
//
//	SeqQueueCyDe(&CQ);
//
//	SeqQueueCyDe(&CQ);
//
//	SeqQueueCyShow(&CQ);
//
//
//
//	SeqQueueCyEn(&CQ, 6);
//
//	SeqQueueCyEn(&CQ, 7);
//
//	SeqQueueCyEn(&CQ, 8);
//
//	SeqQueueCyEn(&CQ, 9);
//
//
//
//	SeqQueueCyShow(&CQ);
//
//
//
//	SeqQueueCyEn(&CQ, 19);
//
//
//	system("pause");
//	return 0;
//}
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


	/*LinkQueueDestory(&LQ);*/
	system("pause");
	return 0;

}
	



