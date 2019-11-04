#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a ;
	char c ;
	scanf_s("=<", &a, &c);
	printf("%d,%c",a, c);
	system("pause");
	return 0;
}