#ifndef _COMMON_H_
#define _COMMON_H_
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<Windows.h>
#define DataType char
void Swap(char *a, char *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
#endif
