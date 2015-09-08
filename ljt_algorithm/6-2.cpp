#include<iostream>
using namespace std;


int a62[6][6] = {
	{0,1,12,999,999,999},
	{999,0,9,3,999,999},
	{999,999,0,999,5,999},
	{999,999,4,0,13,15},
	{999,999,999,999,0,4},
	{999,999,999,999,999,0}
};

int main62()
{
	int dis[6] = {999};
	int book[6] = {0};
	int min,u;
	for (int i = 0;i < 6;i++)
	{
		dis[i] = a62[0][i]; //记录一号点到各个点的距离
	}

	book[0] = 1;

	for (int j = 0; j < 6;j++)
	{
		min = 999;
		for (int i = 0;i < 6;i++)
		{
			if(book[i] == 0 && dis[i] < min)  //在距离数组中寻找一个距离最近的点，且这个点没有访问过
			{
				min = dis[i];
				u = i;
			}
		}

			//以u为起点，遍历所有的点，如果到某点的距离比之前的记录的小，则更新记录
			book[u] = 1;
			for (int k = 0; k < 6;k++)
			{
				if(a62[u][k] < 999)
					if(dis[k] > dis[u] + a62[u][k])
						dis[k] = dis[u] + a62[u][k];
			}
	}

	for (int i = 0;i < 6;i++)
	{
		std::cout<<dis[i]<<std::endl;
	}
	std::cout<<std::endl;

	system("pause");
	return 0;
}