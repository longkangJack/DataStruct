#ifndef _SORT_
#define _SORT_
#include"Common.h"

void PrintArr(int *arr, int left, int right);
void TwoWayInsert(int arr[], int temp[], int n);//��·��������
void InsertSort(int *arr, int left, int right);//��������
void InsertSort_1(int *arr, int left, int right);//�����Ż�
void InsertSort_2(int *arr, int left, int right);//�����Ż�
void Swap(int *a, int *b);
void BinInsertSort(int *arr, int left, int right);//���ֲ�������
void TestSort(int *ar, int left, int right);
void SelectSort(int *arr, int left, int right);//ѡ������
void HeapSort(int *arr, int left, int right);//������
void BubbleSort(int *arr, int left, int right);//ð������
void QuickSort(int *arr, int left, int right);//��������
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
void BinInsertSort(int *arr, int left, int right)//��������
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
void InsertSort(int *arr, int left, int right)//��������
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
//����������Ż��㷨
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
		if (arr[i] < temp[first])//Ҫ�����Ԫ�رȵ�һ��Ԫ��С
		{
			first = (first - 1 + n) % n;//�ص���һ��Ԫ��ǰһ��λ��
			temp[first] = arr[i];
		}
		else if (arr[i]>temp[final])//Ҫ�����Ԫ�رȵ�һ��Ԫ�ش�
		{
			final = (final + 1 + n) % n;
			temp[final] = arr[i];
		}
		else
		{
			k = (final + 1 + n) % n;
			//������ֵ�ȵ�ǰֵСʱ��Ҫ�ƶ���ǰֵ��λ��
			while (temp[(k - 1 + n) % n] > arr[i])
			{
				temp[(k + n) % n] = temp[(k - 1 + n) % n];
				k = (k - 1 + n) % n;
			}
			//�����ֵ
			temp[(k + n) % n] = arr[i];
			//��Ϊ���ֵ��λ�øı䣬������Ҫʵʱ����final��λ��
			final = (final + 1 + n) % n;
		}

	}
	// �������¼���Ƶ�ԭ����˳�����
	for (k = 0; k < n; k++) {
		arr[k] = temp[(first + k) % n];
	}
}
//ѡ������
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
////
//ð������
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
//ð�������Ż�
void BubbleSort(int *arr, int left, int right)
{
	int i = 0;// 1 3 2 4 5 6 7 8 
	int j = 0; // 1 2 3 4 5 6 7 8 
	bool is_swap = false;
	for (i = left; i < right - 1; i++)
	{
		for (j = left; j < right - i; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				is_swap = true;
			}
		}
		if (!is_swap)
			break;
		else
			is_swap = false;
	}
}
void QuickSort(int *arr, int left, int right)
{
	if (left > right)
		return;
	if (right - left + 1 <= M)
	{
		InsertSort_1(arr, left, right);
	}

}
void HeapSort(int *arr, int left, int right)
{

}
/////////////////////////////////////
//���Դ�����Ż��̶� ����->ѡ������
void TestSort(int *arr, int left, int right)
{
	InsertSort(arr, left, right);
	InsertSort_1(arr, left, right);
	InsertSort_2(arr, left, right);
	BinInsertSort(arr, left, right);
	BubbleSort(arr, left, right);
	SelectSort(arr, left, right);

}
//����Ч��
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
	end = clock();//ʱ�亯��
	printf("InsertSort_1: %u\n", end - start);

	start = clock();
	InsertSort_2(a2, 0, n - 1);
	end = clock();//ʱ�亯��
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
