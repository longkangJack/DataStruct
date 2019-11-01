#ifndef _BINTREE_H_
#define _BINTREE_H_
#include"common.h"
typedef struct BinTreeNode
{
	DataType data;//����
	struct BinTreeNode* leftChild;
	struct BinTreeNode* rightChild;
}BinTreeNode;
typedef struct BinTree
{
	BinTreeNode *root; //���ڵ�
}BinTree;
void BinTreeInit(BinTree *t);
void BinTreeCreate(BinTree *t);
void _BinTreeCreate_1(BinTreeNode **t);//�ڲ�����1
BinTreeNode* _BinTreeCreate_2();//�ڲ�����2
//////////////////////
void BinTreeCreate(BinTree *t)//�ӿ�
{
	/*_BinTreeCreate_1(&t->root);*/
	t->root = _BinTreeCreate_2();
	
}
void _BinTreeCreate_1(BinTreeNode **t)
{
	DataType item;
		scanf_s("%c", &item);
		if (item == '#')
		{
			*t = NULL;
		}
		else
		{
			*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
			assert(*t != NULL);
			(*t)->data = item;
			_BinTreeCreate_1(&((*t)->leftChild));
			_BinTreeCreate_1(&((*t)->rightChild));
		}
}
void BinTreeInit(BinTree* t)
{
	t->root = NULL;
}
BinTreeNode* _BinTreeCreate_2()
{
	DataType item;
		scanf_s("%c", &item);
		if (item == '#')
		{
			return NULL;
		}
		else
		{
			BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
			assert(t != NULL);
			t->data = item;
			t->leftChild = _BinTreeCreate_2();
			t->rightChild = _BinTreeCreate_2();//�ݹ����
			return t;
	}
}

//typedef BinTreeNode* BinTree;//����ָ��Ŀ������һ��ָ�룬���Ժ����ڲ�Ҫ�ö���ָ��
//void BinTreeInit(BinTree *t);
//void BinTreeCreate_1(BinTree *t);
//BinTreeNode* BinTreeCreate_2();
//////////////////////////////
//void BinTreeInit(BinTree *t)//����ָ���޸�һ��ָ��
//{
//	*t = NULL;
//}
//void BinTreeCreate_1(BinTree *t)
//{
//	DataType item;
//	scanf_s("%c", &item);
//	if (item == '#')
//	{
//		*t = NULL;
//	}
//	else
//	{
//		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
//		assert(*t != NULL);
//		(*t)->data = item;
//		BinTreeCreate_1(&((*t)->leftChild));
//		BinTreeCreate_1(&((*t)->rightChild));
//	}
//}
//BinTreeNode* BinTreeCreate_2()
//{
//	DataType item;
//	scanf_s("%c", &item);
//	if (item == '#')
//	{
//		return NULL;
//	}
//	else
//	{
//		BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
//		assert(t != NULL);
//		t->data = item;
//		t->leftChild = BinTreeCreate_2();
//		t->rightChild = BinTreeCreate_2();//�ݹ����
//		return t;
//	}
//}
#endif
