#include"common.h"
int main()
{
	SList mylist;
	InitList(&mylist);
	DataType select = 1;
	DataType input = 0;
	while (select)
	{
		printf("*****************************************\n");
		printf("*****1.push_back  2.push_front***********\n");
		printf("*****3.show_list  0.   exit   ***********\n");
		printf("*****5.pop_back   6.pop_front ***********\n");
		printf("*****7.FindByVal  8.           **********\n");
		printf("*****9.DeleByVal ************************\n");
		printf("*****************************************\n");
		printf("*****************************************\n");
		printf("*****************************************\n");
		printf("��ѡ��>");
		scanf_s("%d", &select);
		if (select == 0)
		{
			break;
		}
		switch (select)
		{
		case 1:
			printf("��������Ҫ���������>");
			while (scanf_s("%d",&input),input!=-1)
			{
				SListpushback(&mylist,input);
			}
			break;
		case 2:
			printf("��������Ҫ���������>");
			while (scanf_s("%d", &input), input != -1)
			{
				SListpushfront(&mylist, input);
			}
			break;
		case 3:
			SListshowlist(&mylist);
			break;
		case 5:
			printf("��������Ҫɾ��������>");
			SListPopBack(&mylist, input);
			break;
		case 6:
			printf("��������Ҫɾ��������>");
			SListPopFront(&mylist, input);
			break;
		case 7:
			printf("��������Ҫ���ҵ�����>");
			SListFindByVal(&mylist, input);
			break;
		case 9:
			printf("��������Ҫɾ������>");
			SListDeleByVal(&mylist, input);
			break;
		default :
			printf("���벻�Ϸ�>");
			break;
		}
	}
	return 0;
}