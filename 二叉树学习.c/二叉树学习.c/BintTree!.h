#include"Common.h"
#include"BinTree.h"
void _PreOrderNoR(BinTreeNode *t);
void PreOrderNoR(BinTree *t);
void _InOrderNoR(BinTreeNode *t);
void InOrderNoR(BinTree *t);
void _PostOrderNoR(BinTreeNode *t);
void PostOrderNoR(BinTree *t);
void PreOrderNoR(BinTree *t)

{

	_PreOrderNoR(t->root);

}

void _PreOrderNoR(BinTreeNode *t)

{

	if (t != NULL)

	{

		BinTreeNode *p;

		ListStack st;

		ListStackInit(&st);

		ListStackPush(&st, t);



		while (!ListStackEmpty(&st))

		{

			p = ListStackTop(&st);

			ListStackPop(&st);

			printf("%c ", p->data);

			if (p->rightChild != NULL)

				ListStackPush(&st, p->rightChild);

			if (p->leftChild != NULL)

				ListStackPush(&st, p->leftChild);

		}

	}

}

void InOrderNoR(BinTree *t)

{

	_InOrderNoR(t->root);

}

void _InOrderNoR(BinTreeNode *t)

{

	if (t != NULL)

	{

		BinTreeNode *p;

		ListStack st;

		ListStackInit(&st);

		do

		{

			while (t != NULL)

			{

				ListStackPush(&st, t);

				t = t->leftChild;

			}



			p = ListStackTop(&st);

			ListStackPop(&st);

			printf("%c ", p->data);



			if (p->rightChild != NULL)

				t = p->rightChild;

		} while (!ListStackEmpty(&st) || t != NULL);

	}

}

void PostOrderNoR(BinTree *t)

{

	_PostOrderNoR(t->root);

}

void _PostOrderNoR(BinTreeNode *t)
{
	if (t != NULL)
	{
		BinTreeNode *p, *pre = NULL;
		ListStack st;
		ListStackInit(&st);
		do

		{

			while (t != NULL)

			{

				ListStackPush(&st, t);

				t = t->leftChild;

			}
			p = ListStackTop(&st);
			if (p->rightChild == NULL || p->rightChild == pre)
			{
				ListStackPop(&st);
   			 printf("%c ", p->data);			 
				pre = p;
			}
			else
			{
				t = p->rightChild;
			}
		} while (!ListStackEmpty(&st));
	}
}