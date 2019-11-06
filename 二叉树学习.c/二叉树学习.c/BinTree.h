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
	struct BinTreeNode *root;//创建根节点
}BinTree;
//二叉树的创建
void BinTreeInit(BinTree *t);
void _BinTreeCreate_1(BinTreeNode **t);
void BinTreeCreate(BinTree *t);
BinTreeNode* _BinTreeCreate_2();
//二叉树的遍历
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
		if (item == '#')//为 #说明根节点的下一个节点为空
		{
			*t = NULL;
		}
		else
		{
			*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));//不为空 则申请一个节点作为它的子节点
			assert(*t != NULL);
			(*t)->data = item;
			_BinTreeCreate_1(&((*t)->LeftChild));//递归创建下一个节点 左树
			_BinTreeCreate_1(&((*t)->RightChild));//递归创建下一个节点 右树
		}
}
BinTreeNode* _BinTreeCreate_2()
{
	DataType item;
		scanf_s("%c", &item);
		if (item == '#')//为 #说明根节点的下一个节点为空
		{
			return NULL;
		}
		else
		{
			BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));//不为空 则申请一个节点作为它的子节点
			assert(t != NULL);
			t->data = item;
			t->LeftChild = _BinTreeCreate_2();//递归创建下一个节点 左树
			t->RightChild = _BinTreeCreate_2();//递归创建下一个节点 右树
			return t;
		}
}
void PreOrder(BinTree *t)//前序遍历
{
	_PreOrder(t->root);
}
void _PreOrder(BinTreeNode *t)
{
	if (t != NULL)
	{
		printf("%c ", t->data);
		_PreOrder(t->LeftChild);//递归访问左树
		_PreOrder(t->RightChild);//递归访问右树
	}
}

void InOrder(BinTree *t)
{
	_InOrder(t->root);
}
void _InOrder(BinTreeNode *t)//中序遍历
{
	if (t != NULL)
	{
		_InOrder(t->LeftChild);//递归访问左树
		printf("%c ", t->data);//访问根
		_InOrder(t->RightChild);//递归访问右树
	}
}
void PostOrder(BinTree *t)
{
	_PostOrder(t->root);
}
void _PostOrder(BinTreeNode *t)//后序遍历
{
	if (t != NULL)
	{
		_PostOrder(t->LeftChild);//递归访问左树
		_PostOrder(t->RightChild);//递归访问右树
		printf("%c ", t->data);//访问根
	}
}

//void BinTreeInit(BinTree *t);
//void BinTreeCreate_1(BinTree *t);
//BinTreeNode* BinTreeCreate_2();第一种方式创建二叉树
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
//	if (item == '#')//为 #说明根节点的下一个节点为空
//	{
//		*t = NULL;
//	}
//	else
//	{
//		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));//不为空 则申请一个节点作为它的子节点
//		assert(*t != NULL);
//		(*t)->data = item;
//		BinTreeCreate_1(&((*t)->LeftChild));//递归创建下一个节点 左树
//		BinTreeCreate_1(&((*t)->RightChild));//递归创建下一个节点 右树
//	}
//}
//BinTreeNode* BinTreeCreate_2()
//{
//	DataType item;
//	scanf_s("%c", &item);
//	if (item == '#')//为 #说明根节点的下一个节点为空
//	{
//		return NULL;
//	}
//	else
//	{
//		BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));//不为空 则申请一个节点作为它的子节点
//		assert(t != NULL);
//		t->data = item;
//		t->LeftChild = BinTreeCreate_2();//递归创建下一个节点 左树
//		t->RightChild = BinTreeCreate_2();//递归创建下一个节点 右树
//		return t;
//	}
//}
#endif