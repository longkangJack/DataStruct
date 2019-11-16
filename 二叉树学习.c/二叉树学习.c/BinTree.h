#ifndef _BINTREE_
#define _BINTREE_
#include"Common.h"
typedef struct BinTreeNode
{
	DataType data;
	struct BinTreeNode *LeftChild;
	struct BinTreeNode *RightChild;
}BinTreeNode;
//typedef BinTreeNode* BinTree;
typedef struct BinTree
{
	struct BinTreeNode *root;//�������ڵ�
}BinTree;
//�������Ĵ���
void BinTreeInit(BinTree *t);
void _BinTreeCreate_1(BinTreeNode **t);
void BinTreeCreate(BinTree *t);
BinTreeNode* _BinTreeCreate_2();
//�������ı���
void _PreOrder(BinTreeNode *t);
void PreOrder(BinTree *t);
void _InOrder(BinTreeNode *t);
void InOrder(BinTree *t);
void _PostOrder(BinTreeNode *t);
void PostOrder(BinTree *t);
void BinTreeInit(BinTree *t)
{
	t->root = NULL;
}
void BinTreeCreate(BinTree *t)
{
	//_BinTreeCreate_1(&(t->root));
	t->root = _BinTreeCreate_2();
}
void _BinTreeCreate_1(BinTreeNode **t)
{
	DataType item;
		scanf_s("%c", &item);
		if (item == '#')//Ϊ #˵�����ڵ����һ���ڵ�Ϊ��
		{
			*t = NULL;
		}
		else
		{
			*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));//��Ϊ�� ������һ���ڵ���Ϊ�����ӽڵ�
			assert(*t != NULL);
			(*t)->data = item;
			_BinTreeCreate_1(&((*t)->LeftChild));//�ݹ鴴����һ���ڵ� ����
			_BinTreeCreate_1(&((*t)->RightChild));//�ݹ鴴����һ���ڵ� ����
		}
}
BinTreeNode* _BinTreeCreate_2()
{
	DataType item;
		scanf_s("%c", &item);
		if (item == '#')//Ϊ #˵�����ڵ����һ���ڵ�Ϊ��
		{
			return NULL;
		}
		else
		{
			BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));//��Ϊ�� ������һ���ڵ���Ϊ�����ӽڵ�
			assert(t != NULL);
			t->data = item;
			t->LeftChild = _BinTreeCreate_2();//�ݹ鴴����һ���ڵ� ����
			t->RightChild = _BinTreeCreate_2();//�ݹ鴴����һ���ڵ� ����
			return t;
		}
}
void PreOrder(BinTree *t)//ǰ�����
{
	_PreOrder(t->root);
}
void _PreOrder(BinTreeNode *t)
{
	if (t != NULL)
	{
		printf("%c ", t->data);
		_PreOrder(t->LeftChild);//�ݹ��������
		_PreOrder(t->RightChild);//�ݹ��������
	}
}
void InOrder(BinTree *t)
{
	_InOrder(t->root);
}
void _InOrder(BinTreeNode *t)//�������
{
	if (t != NULL)
	{
		_InOrder(t->LeftChild);//�ݹ��������
		printf("%c ", t->data);//���ʸ�
		_InOrder(t->RightChild);//�ݹ��������
	}
}
void PostOrder(BinTree *t)
{
	_PostOrder(t->root);
}
void _PostOrder(BinTreeNode *t)//�������
{
	if (t != NULL)
	{
		_PostOrder(t->LeftChild);//�ݹ��������
		_PostOrder(t->RightChild);//�ݹ��������
		printf("%c ", t->data);//���ʸ�
	}
}

//void BinTreeInit(BinTree *t);
//void BinTreeCreate_1(BinTree *t);
//BinTreeNode* BinTreeCreate_2();��һ�ַ�ʽ����������
///////////////////////////////
//
//void BinTreeInit(BinTree *t)
//{
//	*t = NULL;
//}
////V L R
//void BinTreeCreate_1(BinTree *t)
//{
//	DataType item;
//	scanf_s("%c", &item);
//	if (item == '#')//Ϊ #˵�����ڵ����һ���ڵ�Ϊ��
//	{
//		*t = NULL;
//	}
//	else
//	{
//		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));//��Ϊ�� ������һ���ڵ���Ϊ�����ӽڵ�
//		assert(*t != NULL);
//		(*t)->data = item;
//		BinTreeCreate_1(&((*t)->LeftChild));//�ݹ鴴����һ���ڵ� ����
//		BinTreeCreate_1(&((*t)->RightChild));//�ݹ鴴����һ���ڵ� ����
//	}
//}
//BinTreeNode* BinTreeCreate_2()
//{
//	DataType item;
//	scanf_s("%c", &item);
//	if (item == '#')//Ϊ #˵�����ڵ����һ���ڵ�Ϊ��
//	{
//		return NULL;
//	}
//	else
//	{
//		BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));//��Ϊ�� ������һ���ڵ���Ϊ�����ӽڵ�
//		assert(t != NULL);
//		t->data = item;
//		t->LeftChild = BinTreeCreate_2();//�ݹ鴴����һ���ڵ� ����
//		t->RightChild = BinTreeCreate_2();//�ݹ鴴����һ���ڵ� ����
//		return t;
//	}
//}
#endif