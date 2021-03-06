#include<stdio.h>
#include<stdlib.h>
#include<string.h>
## 2.串

** 串（字符串）：是由 0 个或多个字符组成的有限序列。 通常记为：s = ‘ a1 a2 a3 … ai …an  ’(n≥0)。 * *

### 一些串的类型:

空串：不含任何字符的串，长度 = 0。

空格串：仅由一个或多个空格组成的串。

子串：由串中任意个连续的字符组成的子序列。

主串：包含子串的串。

位置：字符在序列中的序号。

子串在主串中的位置：子串的首字符在主串中的位置。

空串是任意串的子串，任意串是其自身的子串。

串相等的条件：当两个串的长度相等且各个对应位置的字符都相等时才相等。

实现：

因为串是特殊的线性表，故其存储结构与线性表的存储结构类似，只不过组成串的结点时单个字符

### 定长顺序存储表示

### 也称为静态存储分配的顺序串。 即用一组地址连续的存储单元依次存放串中的字符序列。

串长：可能首字符记录（显式）或\0结尾（隐式）

定长顺序存储表示时串操作的缺点 ：串的某些操作受限（截尾），如串的联接、插入、置换

### 堆分配存储表示  

存储空间在程序执行过程中动态分配，malloc() 分配一块实际串长所需要的存储空间（“堆”）

堆存储结构的优点：堆存储结构既有顺序存储 结构的特点，处理（随机取子串）方便，操作中对 串长又没有任何限制，更显灵活，因此在串处理的 应用程序中常被采用。

### 串的块链存储表示

为了提高空间利用率，可使每个结点存放多个字符 （这是顺序串和链串的综合(折衷) ），称为块链结构。
//模式匹配
/*int PatternMatch(char str1[], char str2[])
{
	int i = 0;
	int j = 0;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
		while (i < len1 && j < len2)
		{
			if (str1[i] == str2[j])
			{
				i++;
				j++;
			}
			else
			{
				i = i - j + 1;
				j = 0;
			}
		}
	if (j == len2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int main()
{
	char arr1[] = "aabaaabaaaababa";
	char arr2[] = "aabab";
	PatternMatch(arr1,arr2);
	int ret = PatternMatch(arr1, arr2);
	if (1 == ret)
	{
		printf("arr2是arr1的子串\n");
	}
	else
	{
		printf("不是子串\n");
	}
	return 0;
}*/
//判断一个字符串是否为对称字符串
/*int IsSym(char str[])
{
	int i = 0;
	int j = 0;
	while (str[j])
		j++;
	for (j--; i < j && str[i] == str[j]; i++, j--);
	return(i >= j);
}
int main()
{
	char arr1[] = "abba";
	int ret = IsSym(arr1);
	if (1 == ret)
	{
		printf("是对称串\n");
	}
	else
	{
		printf("不是对称串\n");
	}
	return 0;
}