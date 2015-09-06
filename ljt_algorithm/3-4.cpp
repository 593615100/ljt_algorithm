#include<iostream>
using namespace std;

int n,book[10],a_3_4[10],num;

void dfs(int step)
{
	if (step == n + 1)
	{
		num++;
		for (int i = 1;i <= n;i++)
		{
			std::cout<<a_3_4[i]<<" ";
		}
		std::cout<<std::endl;
		return;
	}
	for (int i = 1;i <= n;i++)
	{
		if (book[i] == 0)
		{
			a_3_4[step] = i;
			book[i] = 1;
			dfs(step + 1);
			book[i] = 0;
		}
	}
	return;
}

int main_3_4()
{
	n = 3;
	dfs(1);

	std::cout<<num<<std::endl;
	system("pause");
	return 0;
}