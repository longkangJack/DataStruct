#ifndef _SORT_
#define _SORT_
#include"Common.h"

void PrintArr(int arr[], int n);
void TwoWayInsert(int arr[], int temp[], int n);
////////////////////////////////////
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
void PrintArr(int arr[], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}
#endif
