#ifndef _BINTREE_H_
#define _BINTREE_H_
#include"common.h"
typedef struct BinTreeNode
{
	DataType data;//数据
	struct BinTreeNode* leftChild;
	struct BinTreeNode* rightChild;
}BinTreeNode;
typedef struct BinTree
{
	BinTreeNode *root; //根节点
}BinTree;
//二叉树创建
void BinTreeInit(BinTree *t);
void BinTreeCreate(BinTree *t);
void _BinTreeCreate_1(BinTreeNode **t);//内部创建1
BinTreeNode* _BinTreeCreate_2();//内部创建2
BinTreeNode* _BinTreeCreatByStr(char *str, int *i);
void BinTreeCreatByStr(BinTree *t, char *str, int *i);
//////////////////////
//二叉树遍历 递归实现
void _PreOrder(BinTreeNode *t);//V L R遍历
void PreOrder(BinTree *t);
void BinTreeCreate(BinTree *t)//接口
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
			t->rightChild = _BinTreeCreate_2();//递归调用
			return t;
	}
}
void BinTreeCreateByStr(BinTree *t, char *str, int *i)
{
	t->root = _BinTreeCreateByStr(str, i);
}
BinTreeNode* _BinTreeCreateByStr(char *str, int *i)
{
	if (str[*i] == '#' || str[*i] == '\0')
		return NULL;
	else
	{
		BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		t->data = str[*i];
		(*i)++;
		t->leftChild = _BinTreeCreateByStr(str, i);
		(*i)++;
		t->rightChild = _BinTreeCreateByStr(str, i);
		return t;
	}
}
void PreOrder(BinTree *t)//前序
{
	_PreOrder(t->root);
}
void _PreOrder(BinTreeNode *t)
{
	
}
//typedef BinTreeNode* BinTree;//二级指针目的是用一级指针，所以函数内部要用二级指针
//void BinTreeInit(BinTree *t);
//void BinTreeCreate_1(BinTree *t);
//BinTreeNode* BinTreeCreate_2();
//////////////////////////////
//void BinTreeInit(BinTree *t)//二级指针修改一级指针
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
//		t->rightChild = BinTreeCreate_2();//递归调用
//		return t;
//	}
//}
#endif
