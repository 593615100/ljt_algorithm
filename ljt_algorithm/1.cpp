#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int book_sort_1()
{
	int flag[11];
	int index = 0;
	for(int i = 0;i < 11;i++)
	{
		flag[i] = 0;
	}

	for(int i = 0;i < 5;i++)
	{
		scanf("%d",&index);
		flag[index]++;
	}

	for(int j = 0;j < 11;j++)
		for(int i = 0;i < flag[j];i++)
			printf("%d\n",j);

	system("pause");
	return 0;
}