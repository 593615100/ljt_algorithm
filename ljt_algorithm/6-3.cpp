#include<iostream>
using namespace std;

int main63()
{

	int dis[6] = {999,999,999,999,999,999};
	int u[6] = {0,2,1,1,4,3},v[6] = {0,3,2,5,5,4},w[6] = {0,2,-3,5,2,3};
	dis[1] = 0;
	int i,j,k;

	
	for (i = 1;i < 6; i++)
	{
		std::cout<<u[i]<<" "<<v[i]<<" "<<w[i]<<std::endl;
	}
	std::cout<<std::endl;

	for (i = 1;i < 6;i++)
		for(j = 1;j < 6;j++)
			if(dis[v[j]] > dis[u[j]] + w[j])
				dis[v[j]] = dis[u[j]] + w[j];


	for (i = 1;i < 6;i++)
	{
		std::cout<<dis[i]<<std::endl;
	}
	std::cout<<std::endl;
	system("pause");
	return 0;
}