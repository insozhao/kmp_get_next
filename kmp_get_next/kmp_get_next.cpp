// kmp_get_next.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <stdlib.h>
#include <string.h>

void get_next(char *p, int *next);

void main()
{
	char str[] = "aabaabaaa";
	int *next = (int *)malloc(sizeof(int)*strlen(str));
	get_next(str, next);
	for (int i = 0; i < strlen(str); i++)
	{
		printf("%d", next[i]);
	}
	system("pause");
}

void get_next(char *p, int *next){
	int slen = strlen(p);
	next[0] = 0;
	for (int j = 0, i = 1; i < slen;i++)
	{
		while (j>0 && p[j] != p[i])
			j = next[j - 1];
		if (p[i] == p[j])
			j++;
		next[i] = j;
	}
}