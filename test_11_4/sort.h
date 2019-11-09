#ifndef _SORT_
#define _SORT_
#include"Common.h"

void PrintArr(int *arr, int left, int right);
void TwoWayInsert(int arr[], int temp[], int n);//二路插入排序
void InsertSort(int *arr, int left, int right);//插入排序
void InsertSort_1(int *arr, int left, int right);//插入优化
void InsertSort_2(int *arr, int left, int right);//插入优化
void Swap(int *a, int *b);
void BinInsertSort(int *arr, int left, int right);//二分插入排序
void TestSort(int *ar, int left, int right);
void SelectSort(int *arr, int left, int right);//选择排序
void HeapSort(int *arr, int left, int right);//堆排序
void BubbleSort(int *arr, int left, int right);//冒泡排序
void QuickSort(int *arr, int left, int right);//快速排序
void TestSortEfficiency();
////////////////////////////////////
void PrintArr(int *arr, int left,int right)
{
	for (int i = left; i < right; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void BinInsertSort(int *arr, int left, int right)//二分排序
{
	for (int i = left+1; i <= right; i++)
	{
		int tmp = arr[i];
		int low = left;
		int high = i - 1;
		int mid = 0;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (arr[i] >= arr[mid])
				low = mid + 1;
			if (arr[i] < arr[mid])
				high = mid - 1;
		}
		for (int j = i; j>low; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[low] = tmp;
	}
}
void InsertSort(int *arr, int left, int right)//插入排序
{
	for (int i = left + 1; i <= right; i++)
	{
		int j = i;
		while (j > left &&arr[j] < arr[j - 1])
		{
			Swap(&arr[j], &arr[j - 1]);
			j--;
		}
	}
}
//插入排序的优化算法
void InsertSort_1(int *arr, int left, int right)
{
	for (int i = left + 1; i <= right; i++)
	{
		int tmp = arr[i];
		int j = i;
		while (j > left&&tmp < arr[j - 1])
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = tmp;
	}
}
void InsertSort_2(int *arr, int left, int right)
{
	for (int i = left+1; i <= right; i++)
	{
		arr[i] = arr[0];
		int j = i;
		while (arr[0] < arr[j - 1])
		{
			arr[i] = arr[j - 1];
			j--;
		}
		arr[j] = arr[0];
	}

}
void TwoWayInsert(int arr[], int temp[], int n)
{
	int first = 0;
	int final = 0;
	int i = 0;
	int k = 0;
	temp[0] = arr[0];
	for (i = 1; i < n; i++)
	{
		if (arr[i] < temp[first])//要插入的元素比第一个元素小
		{
			first = (first - 1 + n) % n;//回到第一个元素前一个位置
			temp[first] = arr[i];
		}
		else if (arr[i]>temp[final])//要插入的元素比第一个元素大
		{
			final = (final + 1 + n) % n;
			temp[final] = arr[i];
		}
		else
		{
			k = (final + 1 + n) % n;
			//当插入值比当前值小时，要移动当前值的位置
			while (temp[(k - 1 + n) % n] > arr[i])
			{
				temp[(k + n) % n] = temp[(k - 1 + n) % n];
				k = (k - 1 + n) % n;
			}
			//插入该值
			temp[(k + n) % n] = arr[i];
			//因为最大值的位置改变，所以需要实时更新final的位置
			final = (final + 1 + n) % n;
		}

	}
	// 将排序记录复制到原来的顺序表里
	for (k = 0; k < n; k++) {
		arr[k] = temp[(first + k) % n];
	}
}
//选择排序
int  GetMinIndex(int *arr, int left, int right)
{
	int mul_val = arr[left];
	int index = left;
	for (int i = left+1; i <=right; i++)
	{
		if (mul_val>arr[i])
		{
			mul_val = arr[i];
			index = i;
		}
	}
	return index;
}
void SelectSort(int *arr, int left, int right)
{
	int i = 0;
	for (i = left; i < right; i++)
	{
		int index = GetMinIndex(arr, i, right);
		if (index != i)
		{
			Swap(&arr[index], &arr[i]);
		}
	}
}
void HeapSort(int *arr, int left, int right)
{

}
void BubbleSort(int *arr, int left, int right)
{
	int i = 0;
	int j = 0;
	for (i = left; i < right - 1; i++)
	{
		for (j = left; j < right-i; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}
void QuickSort(int *arr, int left, int right)
{
	if (left > right)
		return;
}
/////////////////////////////////////
//测试代码的优化程度 堆排->选择排序
void TestSort(int *arr, int left, int right)
{
	InsertSort(arr, left, right);
	InsertSort_1(arr, left, right);
	InsertSort_2(arr, left, right);
	BinInsertSort(arr, left, right);
	BubbleSort(arr, left, right);
	SelectSort(arr, left, right);

}
//计算效率
void TestSortEfficiency()
{
	int n = 10000;
	int *a = (int*)malloc(sizeof(int)* n);
	int *a1 = (int*)malloc(sizeof(int)* n);
	int *a2 = (int*)malloc(sizeof(int)* n);
	int *a3 = (int*)malloc(sizeof(int)* n);
	int *a4 = (int*)malloc(sizeof(int)* n);
	int *a5 = (int*)malloc(sizeof(int)* n);
	//int *a6 = (int*)malloc(sizeof(int)* n);
	srand(time(0));
	for (int i = 0; i<n; ++i)
	{
		a[i] = rand();
		a1[i] = a[i];
		a2[i] = a[i];
		a3[i] = a[i];
		a4[i] = a[i];
		a5[i] = a[i];
	}
	time_t start = clock();
	InsertSort(a, 0, n - 1);
	time_t end = clock();
	printf("InsertSort: %u\n", end - start);

	start = clock();
	InsertSort_1(a1, 0, n - 1);
	end = clock();//时间函数
	printf("InsertSort_1: %u\n", end - start);

	start = clock();
	InsertSort_2(a2, 0, n - 1);
	end = clock();//时间函数
	printf("InsertSort_2: %u\n", end - start);

	start = clock();
	BinInsertSort(a3, 0, n - 1);
	end = clock();
	printf("BinInsertSort: %u\n", end - start);

	start = clock();
	BubbleSort(a4, 0, n - 1);
	end = clock();
	printf("BubbleSort: %u\n", end - start);


	start = clock();
	SelectSort(a5, 0, n - 1);
	end = clock();
	printf("SelectSort: %u\n", end - start);

}
#endif
