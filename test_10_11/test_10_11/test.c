#include"common.h"
int main()
{
	int input = 0;
	int select = 1;
	List mylist;
	List yourlist;
	InitList(&mylist);
	InitYourList(&yourlist);
	while (select)
	{	
		printf("*********************************\n");
		printf("***1.PushMyList  2.ShowMyList  **\n");
		printf("***3.reserve    0. exit       ***\n");
		printf("***4.Contact    5.Destory     ***\n");
		printf("***6.PushYourList7.ShowYourList**\n");
		printf("***8.ShowNewList              ***\n");
		printf("*********************************\n");
		scanf_s("%d", &select);
		if (select == 0)
		{
			break;
		}
		switch (select)
		{
		case 1:
			while (scanf_s("%d",&input), input != -1)
			{
				ListmyPush(&mylist, input);
			}
			break;
		case 2:
			ShowmyList(&mylist);
			break;
		case 3:
			reservelist(&mylist,&yourlist);
			break;
		case 4:
			ContactList(&mylist, &yourlist);
			break;
		case 5:
			break;
		case 6:
			while (scanf_s("%d", &input), input != -1)
			{
				ListyourPush(&yourlist, input);
			}			
			break;
		case 7:
			showyourlist(&yourlist);
			break;
		case 8:
			break;
		case 0:
			DestoryList(&mylist, &yourlist);
			break;
		default :
			printf("输入数据不合法,请重新输入\n");
		}
	}
	return 0;
}