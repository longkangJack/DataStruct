#include<stdio.h>
#include<string.h>
//char* ReserveArr(char* arr,int n)
//{
//	char* Head;
//	char* Tail;
//	Head = arr;
//	char* q = Head;
//	Tail = &arr[n-1];
//	for (int i = 0; i < n / 2; i++)
//	{
//		char tmp = *q;
//		*q = *Tail;
//		*Tail = tmp;
//		q++;
//		Tail--;
//	}
//	return Head;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%s\n", arr);
//	int n = strlen(arr);
//	int i = 0;
//	char *ret = ReserveArr(arr,n);
//	printf("%s\n", ret);
//	return 0;
//}
//typedef struct InFor
//{
//	char name[10];
//	int Num;
//	float score;
//}StuInFo;
//int main()
//{
//	StuInFo stu[10];
//	int N = 0;
//	int i = 0;
//	int j = 0;
//	scanf_s("%d", &N);
//	for (i = 0; i < N; i++)
//	{
//		scanf_s("%s %d %f",stu[i].name, &stu[i].Num, &stu[i].score);
//	}
//	for (j = 0; j < N-1; j++)// 1 2 3
//	{
//		for (i = 0; i < N - j - 1; i++)
//		{
//			if (stu[i].score < stu[i + 1].score)
//			{
//				int tmp = stu[i].score;
//				stu[i].score = stu[i + 1].score;
//				stu[i + 1].score = tmp;
//			}
//		}
//	}
//	for (i = 0; i < N; i++)
//	{
//		printf("%s %d %f\n",stu[i].name, stu[i].Num, stu[i].score);
//	}
//	return 0;
//}
//#define N 1
//void Swap(float* a, float* b)
//{
//	float t = *a;
//	*a = *b;
//	*b = t;
//}
//struct student		//定义student的结构体
//{
//	int num;
//	char name[10];
//	float score;
//}stu[N];
//int main()
//{
//	int i;
//	printf("请输入学生的学号，姓名，成绩：\n");
//	for (i = 0; i < N; i++)
//	{
//		scanf_s("%d%s%f",&stu[i].num, &stu[i].name, &stu[i].score);
//	}
//	for (i = 0; i < N - 1; i++)
//	{
//		for (int j = 0; j < N - i - 1; j++)
//		{
//			Swap(&stu[i].score,&stu[i + 1].score);
//		}
//	}
//	printf("学号\t姓名\t成绩\n");
//	for (i = 0; i < N; i++)
//	{
//		printf("%d\t%s\t%f\t", stu[i].num, stu[i].name, stu[i].score);
//		printf("\n");
//	}
//	return 0;
//}
int main()
{
	int i = 0;
	int index = 0;
	int arr[11];
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	index = 0;
	for (i = 1; i < 10; i++)		
	{
			if (arr[i] < arr[index]) 
				{   
					index = i;           
				}
			}
	printf("%d %d\n", arr[index], index);
	return 0;
}
//#include<stdio.h>
//int main() 
//{
//	int a[11], n, i, index;
//	for (i = 0; i <10; i++) 
//	{
//		scanf_s("%d", &a[i]);
//	}
//	index = 0;             
//	for (i = 1; i < 10; i++) 
//	{
//		if (a[i] < a[index]) 
//		{   
//			index = i;           
//		}
//	}
//	printf("%d %d", a[index], index);
//	return 0;
//}
