#include"common.h"
int main()
{
	SeqList mylist;
	SeqListInit(&mylist, CAPACITY);//初始化顺序表;
	int select = 1;
	DataType item = 0;
	while (select)
	{
		printf("**************************************\n");
		printf("****1.push_back     2.push_front******\n");
		printf("****3.show_list     0.list_exit*******\n");
		printf("****4.length        5.clear***********\n");
		printf("****6.sort          7.        ********\n");
		printf("**************************************\n");
		printf("**************************************\n");
		printf("请选择>");
		scanf_s("%d",&select);
		if (select == 0)
		{
			break;
		}
		switch (select)
		{
		case 1:
			printf("请输入你要插入的数据,打印-1退出\n");
			while (scanf_s("%d", &item), item != -1)
			{
				SeqListPushBack(&mylist, item);
			}
			break; 
		case 2:
			printf("请输入你要插入的数据,打印-1退出\n");
			while (scanf_s("%d", &item), item != -1)
			{
				SeqListPushFront(&mylist, item);
			}
			break;
		case 3:
			SeqList_show(&mylist);
			break;
		case 4:
			printf("%d", SeqListLength(&mylist));
			printf("\n");
			break;
		case 5:
			SeqListclear(&mylist);
			break;
		case 6:
			SeqListSort(&mylist);
			break;
		default :
			printf("输入错误,请重新输入>");
		}

	}
	return 0;
}