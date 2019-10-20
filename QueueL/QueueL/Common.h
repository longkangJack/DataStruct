#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
//顺序队列
#define DataType int
#define DEFAULT_QUEUE_SIZE 8
//typedef struct SeqQueue
//{
//	DataType *Base;
//	size_t  capacity;
//	int front;
//	int tail;
//}SeqQueue;//定义一个顺序队列
//void SeqQueueInit(SeqQueue* Q,int sz);
//void SeqQueueEn(SeqQueue* Q, DataType x);
//void SeqQueueShow(SeqQueue* Q);
//void SeqQueueDe(SeqQueue* Q);//出队
//DataType SeqQueueFront(SeqQueue* Q);
//void SeqQueueDestory(SeqQueue* Q);
////
//bool SeqQueueFull(SeqQueue* Q)
//{
//	return Q->tail >= Q->capacity;
//}
//bool SeqQueueEmpty(SeqQueue* Q)
//{
//	return Q->front == Q->tail;
//}
//
//void SeqQueueInit(SeqQueue* Q,int sz)//初始化队列
//{
//	Q->capacity = sz > DEFAULT_QUEUE_SIZE ? sz : DEFAULT_QUEUE_SIZE;
//	Q->Base =(DataType*)malloc(sizeof(DataType)*Q->capacity);
//	Q->front = Q->tail = 0;
//}
////入队
//void SeqQueueEn(SeqQueue* Q, DataType x)
//{
//	if (SeqQueueFull(Q))
//	{
//		printf("队列已满,%d不能入队\n",x);
//		return;
//	}
//	Q->Base[Q->tail++] = x;
//}
//void SeqQueueShow(SeqQueue* Q)
//{
//	for (int i = Q->front; i < Q->tail; i++)
//	{
//		printf("%d ", Q->Base[i]);
//	}
//	printf("\n");
//}
//void SeqQueueDe(SeqQueue* Q)
//{
//	if (SeqQueueEmpty(Q))
//	{
//		printf("队列为空,不能出队\n");
//		return;
//	}
//	Q->front++;
//}
//DataType SeqQueueFront(SeqQueue* Q)
//{
//	if (SeqQueueEmpty(Q))
//	{
//		printf("队列一空,不能取\n");
//		return;
//	}
//	return Q->Base[Q->front];
//}
//void SeqQueueDestory(SeqQueue* Q)
//{
//	free(Q->Base);
//	Q->Base = NULL;
//	Q->capacity = Q->front = Q->tail = 0;
//}
//循环队列
//typedef struct SeqCyQueue
//{
//	DataType *Base;
//	size_t  capacity;
//	int front;
//	int tail;
//}SeqCyQueue;//定义一个循环队列
//void SeqQueueCyInit(SeqCyQueue* Q, int sz);
//void SeqQueueCyEn(SeqCyQueue* Q, DataType x);
//void SeqQueueCyShow(SeqCyQueue* Q);
//void SeqQueueCyDe(SeqCyQueue* Q);//出队
//DataType SeqQueueCyFront(SeqCyQueue* Q);
//void SeqQueueCyDestory(SeqCyQueue* Q);
//bool SeqQueueFull(SeqCyQueue* Q)
//{
//	return (Q->tail+1)% Q->capacity == Q->front;
//}
//bool SeqQueueEmpty(SeqCyQueue* Q)
//{
//	return Q->front == Q->tail;
//}
////
//void SeqQueueCyInit(SeqCyQueue* Q,int sz)
//{
//	Q->capacity = sz > DEFAULT_QUEUE_SIZE ? sz : DEFAULT_QUEUE_SIZE;
//	Q->Base = (DataType*)malloc(sizeof(DataType)*Q->capacity);
//	Q->front = Q->tail = 0;	
//}
//void SeqQueueCyEn(SeqCyQueue* Q, DataType x)
//{
//	if (SeqQueueFull(Q))
//	{
//		printf("循环队列已经满了,%d不能入队\n");
//		return;
//	}
//	Q->Base[Q->tail] = x;
//	Q->tail = (Q->tail + 1) % Q->capacity;//回到队头
//}
//DataType SeqQueueCyFront(SeqCyQueue* Q)
//{
//	if (SeqQueueEmpty(Q))
//	{
//		printf("队列已空， 不能取队头元素.\n");
//		return;
//	}
//	return Q->Base[Q->front];
//}
//void SeqQueueCyDe(SeqCyQueue* Q)
//{
//	if (SeqQueueEmpty(Q))
//	{
//		printf("队列已空， 不能取队头元素.\n");
//		return;
//	}
//	Q->front = (Q->front + 1) % Q->capacity;//回到表头下一个
//}
//void SeqQueueCyShow(SeqCyQueue *Q)
//{
//	for (int i = Q->front; i != Q->tail;)
//	{
//		printf("%d ", Q->Base[i]);
//		i = (i + 1) % Q->capacity;
//	}
//	printf("\n");
//}
//void SeqQueueCyDestroy(SeqCyQueue *Q)
//{
//	free(Q->Base);
//	Q->Base = NULL;
//	Q->capacity = Q->front = Q->tail = 0;
//
//}
//
//链表式队列
typedef struct LinkQueueNode
{
	DataType data;
	struct LinkQueueNode* next;//初始化节点
}LinkQueueNode;
typedef struct LinkQueue
{
	LinkQueueNode* front;
	LinkQueueNode* tail;
}LinkQueue;
bool LinkQueueEmpty(LinkQueue* Q)
{
	return Q->front = NULL;
}
void LinkQueueInit(LinkQueue* Q);
void LinkQueueEn(LinkQueue*Q, DataType x);//入队
void LinkQueueShow(LinkQueue*Q);
DataType LinkQueueFront(LinkQueue*Q);
void LinkQueueDe(LinkQueue* Q);
void LinkQueueDestory(LinkQueue* Q);
//
void LinkQueueInit(LinkQueue* Q)
{
	Q->front = Q->tail = NULL;
}
void LinkQueueEn(LinkQueue *Q, DataType x)
{
	LinkQueueNode *s = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	assert(s != NULL);
    s->data = x;
	s->next = NULL;
	if (LinkQueueEmpty(Q))
	{
		Q->front = Q->tail = s;
	}
	else
	{
		Q->tail->next = s;
		Q->tail = s;
	}
}
void LinkQueueShow(LinkQueue *Q)
{
	LinkQueueNode *p = Q->front;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
DataType LinkQueueFront(LinkQueue *Q)
{
	if (LinkQueueEmpty(Q))
	{
		printf("链队列为空");
		return;
	}
	return Q->front->data;
}
void LinkQueueDe(LinkQueue* Q)
{
	if (LinkQueueEmpty(Q))
	{
		printf("链队列为空");
		return;
	}
	LinkQueueNode* p = Q->front;
	Q->front = Q->front->next;
	free(p);
}
void LinkQueueDestory(LinkQueue* Q)
{
	LinkQueueNode* p;
	p = Q->front;
	while (p!= NULL)
	{
		Q->front = Q->front->next;
		free(p);
		p = Q->front;
	}
	Q->front = Q->tail = NULL;
}








