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
void PrintArr(int arr[], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}
#endif
