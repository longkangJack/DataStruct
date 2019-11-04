#include"Common.h"
#include"SList.h"
#include"sort.h"
int main()
{
	int arr[8] = { 1, 2, 8, 4, 5, 6, 7, 3 };
	int temp[8];
	int n = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = n - 1;
	//InsertSort(arr, left, right);//直接插入排序
	PrintArr(arr, n);
	printf("\n");
	TwoWayInsert(arr,temp ,n );//二路插入排序
	PrintArr(arr, n);
	system("pause");
	return 0;
}




//int main()
//{
//	SList mylist;
//	int x = 0;
//	SListInit(&mylist);
//	SListPushback(&mylist,1);
//	SListPushback(&mylist, 2);
//	SListPushback(&mylist, 3);
//	SListPushback(&mylist, 4);
//	SListShow(&mylist);
//	SListReserve(&mylist);
//	SListShow(&mylist);
//	system("pause");
//	return 0;
//}