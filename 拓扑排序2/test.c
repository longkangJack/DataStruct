#include<stdio.h>
#include<stdlib.h>

#define MaxVertexNum 100
#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

typedef int Boolean;
typedef int VertexType;
Boolean visit[MaxVertexNum];
typedef struct node
{
	int adjvex;
	struct node* next;
}EdgeNode;

typedef struct
{
	VertexType vertex;
	EdgeNode* firstedge;
}VertexNode;

typedef VertexNode AdjList[MaxVertexNum];

typedef struct
{
	AdjList adjlist;
	int n, e;
}ALGraph;

int FindVertex(ALGraph* G, int e, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (G->adjlist[i].vertex == e)
		{
			return i;
		}
	}
	return -1;
}
void create(ALGraph* G)			//�����ڽӱ�
{
	int i, j, k, w, v;
	EdgeNode* s;

	printf("���붥��ͱ���");
	scanf_s("%d %d", &G->n, &G->e);

	for (i = 0; i < G->n; i++)
	{

		printf("���������");
		fflush(stdin);
		scanf_s("%d", &G->adjlist[i].vertex);
		G->adjlist[i].firstedge = NULL;
	}
	printf("�����߱�\n");
	for (k = 0; k < G->e; k++)
	{
		printf("����(vi-vj)�Ķ�������");
		scanf_s("%d %d", &i, &j);

		i = FindVertex(G, i, G->n);
		j = FindVertex(G, j, G->n);
		if (i == -1 || j == -1)
		{
			printf("�Ҳ������㣬����������!\n");
			printf("����(vi-vj)�Ķ�������");
			scanf_s("%d %d", &i, &j);
			i = FindVertex(G, i, G->n);
			j = FindVertex(G, j, G->n);
		}
		s = (EdgeNode*)malloc(sizeof(EdgeNode));
		s->adjvex = (j);
		s->next = G->adjlist[i].firstedge;
		G->adjlist[i].firstedge = s;
	}
}

void TopoSort(ALGraph* G, int n)
{
	int i, j, k, top, m = 0;
	EdgeNode* p;
	int* d = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)		//��ʼ������
	{
		d[i] = 0;
	}
	for (i = 0; i < n; i++)		//ͳ�Ƹ������������������������������������
	{
		p = G->adjlist[i].firstedge;
		while (p != NULL)
		{
			j = p->adjvex;
			d[j]++;
			p = p->next;
		}
	}
	top = -1;
	for (i = 0; i < n; i++)			//���ҳ����������0�Ķ���
	{
		if (d[i] == 0)
		{
			d[i] = top;
			top = i;
		}
	}

	while (top != -1)
	{
		j = top;
		top = d[top];
		printf("%d ", j);
		m++;		//ͳ�ƶ���
		p = G->adjlist[j].firstedge;
		while (p)
		{
			k = p->adjvex;		//��l���ӵĶ���
			d[k]--;		//�����ӵĶ�����ȼ�1
			if (d[k] == 0)		//����������Ϊ0���¶��㣬�Ӹö������
			{
				d[k] = top;
				top = k;
			}
			p = p->next;
		}

	}
	if (m < n) printf("\n�л�·��\n");
	free(d);
}

void main()
{
	ALGraph* G = (ALGraph*)malloc(sizeof(ALGraph));
	EdgeNode* p;
	create(G);
	int i;
	printf("���ڽӱ�Ϊ('->'��ʾ����֮��������)��\n");
	for (i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstedge;
		printf("%d->", G->adjlist[i].vertex);
		while (p != NULL)
		{
			printf("%d->", G->adjlist[p->adjvex].vertex);
			p = p->next;
		}
		printf("\n");
	}
	printf("��������Ϊ��\n");
	TopoSort(G, G->n);
}