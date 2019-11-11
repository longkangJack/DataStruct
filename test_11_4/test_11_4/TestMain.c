#include"Common.h"
#include"SList.h"
#include"sort.h"
int Compare(const void *e1, const void *e2)//快排
{
	const int *elem1 = (const int*)e1;
	const int *elem2 = (const int*)e2;//返回<0 说明e1<e2
	return (*elem1 - *elem2);
}
int main()
{
	int arr[8] = { 1, 2, 8, 4, 5, 6, 7, 3 };
	int temp[8];
	int n = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = n - 1;
	PrintArr(arr, left,right);
	//qsort(arr,8,sizeof(int),Compare);
	//TwoWayInsert(arr,temp ,n );//二路插入排序
	//TestSort(arr, 0, n - 1);
	PrintArr(arr, left,right);
    //TestSortEfficiency();
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