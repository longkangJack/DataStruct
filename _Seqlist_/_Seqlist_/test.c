#include"common.h"
int main()
{
	SeqList mylist;
	SeqListInit(&mylist, CAPACITY);//初始化顺序表;
	int select = 1;
	int pos = 0;
	DataType item = 0;
	DataType ret = 0;
	DataType flag = 0;
	while (select)
	{
		printf("**************************************\n");
		printf("****1.push_back     2.push_front******\n");
		printf("****3.show_list     0.list_exit*******\n");
		printf("****4.length        5.clear***********\n");
		printf("****6.sort          7. reverse********\n");
		printf("****8.Modify_pos    9.Modify_value****\n");
		printf("****10.Find_pos     11.Find_value ****\n");
		printf("****12.Pop_back     13.Pop_front  ****\n");
		printf("**         14.Destory_Seqlist       **\n");
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
		case 7:
			SeqListReverse(&mylist);
			break;
		case 8:
			printf("请输入你要插入的位置\n");
			scanf_s("%d", &pos);
			printf("请输入你要插入的数据\n");
			scanf_s("%d", &item);
			SeqListModiftByPos(&mylist, pos, item);
			break;
		case 9:
			printf("请输入要被修改的数据>");
			scanf_s("%d", &pos);
			printf("请输入要改的数据>");
			scanf_s("%d", &item);
			ModifyByValue(&mylist, pos,item);
			break;
		case 10:
			printf("请输入要查找的位置>");
			scanf_s("%d", &item);
			flag = FindByPos(&mylist,item,&ret);
			printf("%d\n", flag);
		case 11:
			printf("请输入要查找的值>");
			scanf_s("%d", &item);
		flag = FindByVal(&mylist, item, &ret);
		if (flag == -1)
		{
			printf("找不到\n");
		}
		else
		printf("%d\n", flag);
			break; 
		case 12:
			Pop_back(&mylist);
			break;
		case 13:
			Pop_Front(&mylist);
			break;
		case 14:
			Destort_Seqlist(&mylist);
			break;
		default :
			printf("输入错误,请重新输入>");
		}

	}
	return 0;
}