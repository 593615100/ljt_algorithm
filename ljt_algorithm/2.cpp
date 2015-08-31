#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int Bubble_Sort()
{
	int flag[10] = {12,35,99,18,76,21,58,99,81,67};
	int index = 0;
	printf("排序前：\n");
	for(int i = 0;i < 10;i++)
	{
		printf("%d ",flag[i]);
	}
	printf("\n");

	for(int i = 0;i < 10 - 1;i++)
		for(int j = 0;j < 10 - 1 - i;j++)
			if(flag[j] <= flag[j+1])
			{
				int temp = flag[j];
				flag[j] = flag[j+1];
				flag[j+1] = temp;
			}


	printf("排序后：\n");
	for(int i = 0;i < 10;i++)
	{
		printf("%d ",flag[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}