#include<iostream>
using namespace std;

int main82()
{
	int e[7][7],dis[7],book[7];
	int inf = 999999;
	int n,m,i,j,v,u,w,count = 0,min;

	std::cin>>n>>m;

	for(i = 1;i <=n;i++)
		for(j = 1;j <= m;j++)
			if(i == j)
				e[i][j] = 0;
			else
				e[i][j] = inf;

	for (i = 1;i <= m;i++)
	{
		std::cin>>u>>v>>w;
		e[u][v] = w;
		e[v][u] = w;
	}

	for(i = 1;i <= n;i++){
		dis[i] = e[1][i];
		book[i] = 0;
	}

	book[1] = 1;
	count++;

	while(count < n)
	{
		min = inf;
		for (i = 1;i <= n;i++)
		{
			if(book[i] == 0 && dis[i] < min)
			{
				min = dis[i];
				j = i;
			}
		}

		book[j] = 1;count++;

		for (int k = 1;k < n;k++)
		{
			if(book[k] == 0 && dis[k] > e[j][k])
				dis[k] = e[j][k];
		}
	}


}