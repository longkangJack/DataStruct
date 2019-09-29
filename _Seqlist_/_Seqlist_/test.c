#include"common.h"
int main()
{
	SeqList mylist;
	SeqListInit(&mylist, CAPACITY);//��ʼ��˳���;
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
		printf("��ѡ��>");
		scanf_s("%d",&select);
		if (select == 0)
		{
			break;
		}
		switch (select)
		{
		case 1:
			printf("��������Ҫ���������,��ӡ-1�˳�\n");
			while (scanf_s("%d", &item), item != -1)
			{
				SeqListPushBack(&mylist, item);
			}
			break; 
		case 2:
			printf("��������Ҫ���������,��ӡ-1�˳�\n");
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
			printf("��������Ҫ�����λ��\n");
			scanf_s("%d", &pos);
			printf("��������Ҫ���������\n");
			scanf_s("%d", &item);
			SeqListModiftByPos(&mylist, pos, item);
			break;
		case 9:
			printf("������Ҫ���޸ĵ�����>");
			scanf_s("%d", &pos);
			printf("������Ҫ�ĵ�����>");
			scanf_s("%d", &item);
			ModifyByValue(&mylist, pos,item);
			break;
		case 10:
			printf("������Ҫ���ҵ�λ��>");
			scanf_s("%d", &item);
			flag = FindByPos(&mylist,item,&ret);
			printf("%d\n", flag);
		case 11:
			printf("������Ҫ���ҵ�ֵ>");
			scanf_s("%d", &item);
		flag = FindByVal(&mylist, item, &ret);
		if (flag == -1)
		{
			printf("�Ҳ���\n");
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
			printf("�������,����������>");
		}

	}
	return 0;
}