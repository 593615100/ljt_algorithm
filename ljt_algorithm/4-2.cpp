#include<iostream>
using namespace std;


int min_step = 1000000;
int p = 6;
int q = 7;

int a[11][11];
int book[11][11];
void dfs(int x,int y,int step)
{
	int next[4][2] = {
		{0,1},{1,0},{0,-1},{-1,0}
	};

	int tx,ty;
	if(x == p && y == q)
	{
		if (step < min_step)
		{
			min_step = step;
		}
		return;
	}

	for (int i = 0;i <= 3;i++)
	{
		tx = x + next[i][0];
		ty = y + next[i][1];

		if(tx < 1 || tx > 11 ||ty < 1 || ty > 11 )
			continue;

		if (book[tx][ty] == 0 && a[tx][ty] == 0)
		{
			book[tx][ty] = 1;
			dfs(tx,ty,step + 1);
			book[tx][ty] = 0;
		}
	}
	return;
}

int main()
{
	int start = 1,end = 1;
	a[4][7] = 1;
	a[6][1] = 1;
	a[2][4] = 1;
	a[9][1] = 1;
	a[5][2] = 1;
	a[8][6] = 1;
	book[start][end] = 1;
	dfs(start,end,0);
	std::cout<<min_step<<std::endl;

	system("pause");
	return 0;
}