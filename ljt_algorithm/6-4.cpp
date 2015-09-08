#include<iostream>
#include<queue>
using namespace std;


int main64()
{
	int n,m,i,j,k;
	int u[8],v[8],w[8],dis[8];
	int first[8],next[8],book[8];
	queue<int> que;

	std::cin>>n>>m;

	for(i = 0;i < 8;i++){
		dis[i] = 999;
		book[i] = 0;
		first[i] = -1;
	}

	dis[1] = 0;

	for(i = 1;i <= m;i++){
		std::cin>>u[i]>>v[i]>>w[i];
		next[i] = first[u[i]];
		first[u[i]] = i;
	}

	que.push(u[1]);
	book[1] = 1;

	while (!que.empty())
	{
		k = first[que.front()];
		while (k != -1)
		{
			if(dis[v[k]] > dis[u[k]] + w[k])
			{
				dis[v[k]] = dis[u[k]] + w[k];
				if(book[v[k]] == 0)
				{
					que.push(v[k]);
					book[v[k]] = 1;
				}
			}
			k = next[k];
		}
		book[que.front()] = 0;
		que.pop();
	}

	for (i = 1;i < 6;i++)
	{
		std::cout<<dis[i]<<std::endl;
	}
	std::cout<<std::endl;
	system("pause");
	return 0;
}