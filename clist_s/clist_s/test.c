//主函数
#include"common.h"
int main()
{
	List mylist;
	InitList(&mylist);
	int select = 1;
	int input = 0;
	int ret = 0;
	while (select)
	{
			printf("*****************************************\n");
			printf("* [1] push_back         [2] push_front  *\n");
			printf("* [3] show_list         [0] quit_system *\n");
			printf("* [4] pop_back          [5] pop_front   *\n");
			printf("* [6] insert_pos        [7] insert_val  *\n");
			printf("* [8] delete_pos        [9] delete_val  *\n");
			printf("* [10] find_pos         [11] find_val   *\n");
			printf("* [12] sort             [13] reverse    *\n");
			printf("* [14] length           [15] clear      *\n");
			printf("* [16] modify_pos       [17] modify_val *\n");
			printf("*****************************************\n");
			printf("请选择>");
			scanf_s("%d", &select);
			if (select == 0)
				break;
			switch (select)
			{
			case 1:
				printf("请输入你要插入的数据:");
				while ((scanf_s("%d",&input))&&input!=-1)
				{
					push_back(&mylist,input);
				}
				break;
			case 2:
				printf("请输入你要插入的数据:");
				while ((scanf_s("%d", &input))&&input != -1)
				{
					push_front(&mylist,input);
				}
				break;
			case 3:
				show_list(&mylist);
				break;
			case 14:
			    ret = DListLength(&mylist);
				printf("%d\n", ret);
				break;
			case 15:
				ClearList(&mylist);
				break;
			default:
				printf("输入错误,请重新输入>");
			}
	}
	return 0;
}