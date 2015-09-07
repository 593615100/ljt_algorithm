#include<iostream>
#include<queue>
using namespace std;

struct Note
{
	Note(int a,int b,int st = 0):x(a),y(b),step(st){}; //构造函数
	int x;
	int y;
	int step;
};

int a44[10][10] = {0};
int book44[10][10] = {0};
int next44[4][2] = {
	{0,1},{1,0},{0,-1},{-1,0}
};
int sum;

void dfs44(int x,int y)
{
	int tx,ty;
	for (int i = 0;i < 4;i++)
	{
		tx = x + next44[i][0];
		ty = y + next44[i][1];

		if(tx > 10 || ty > 10 || tx < 0 || ty < 0) //足迹越界
			continue;

		if (book44[tx][ty] == 0 && a44[tx][ty] == 0) //判断这个点是否符合条件
		{
			sum++;
			book44[tx][ty] = 1;

			dfs44(tx,ty);

			book44[tx][ty] = 0;

		}

	}
	return ;
}
int main44()
{
	bool flag = false;
	queue<Note> que;
	int tx,ty,p,q,step = 0;

	a44[0][0] = 1,a44[0][1]=2,a44[0][2]=1,a44[0][8]=2,a44[0][9]=3;
	a44[1][0] = 3,a44[1][2]=2,a44[1][4]=1,a44[1][5]=2,a44[1][6]=1,a44[1][8]=1,a44[1][9]=2;
	a44[2][0] = 4,a44[2][2]=1,a44[2][4]=1,a44[2][5]=2,a44[2][6]=3,a44[2][7]=2,a44[2][9]=1;
	a44[3][0]=3,a44[3][1]=2,a44[3][5]=1,a44[3][6]=2,a44[3][7]=4;
	a44[4][6]=1,a44[4][7]=5,a44[4][8]=3;
	a44[5][1]=1,a44[5][2]=2,a44[5][3]=1,a44[5][5]=1,a44[5][6]=5,a44[5][7]=4,a44[5][8]=3;
	a44[6][1]=1,a44[6][2]=2,a44[6][3]=3,a44[6][4]=1,a44[6][5]=3,a44[6][6]=6,a44[6][7]=2,a44[6][8]=1;
	a44[7][2]=3,a44[7][3]=4,a44[7][4]=8,a44[7][5]=9,a44[7][6]=7,a44[7][7]=5;
	a44[8][3]=3,a44[8][4]=7,a44[8][5]=8,a44[8][6]=6,a44[8][8]=1,a44[8][9]=2;
	a44[9][8]=2;

	que.push(Note(6,8,step++));
	book44[6][8] = 1;
	sum = 1;

	while (!que.empty())
	{
		for (int i = 0;i < 4;i++)
		{
			tx = que.front().x + next44[i][0];
			ty = que.front().y + next44[i][1];

			if(tx > 10 || ty > 10 || tx < 0 || ty < 0) //足迹越界
				continue;

			if (book44[tx][ty] == 0 && a44[tx][ty] == 0) //判断这个点是否符合条件
			{
				sum++;
				book44[tx][ty] = 1;
				que.push(Note(tx,ty,step++));

			}
		}
		que.pop();
	}
	std::cout<<"广度优先算法"<<std::endl;
	std::cout<<"面积："<<sum<<std::endl;

	sum = 1;
	for(int i = 0;i < 10;i++)
		for(int j = 0;j < 10;j++)
			book44[i][j] = 0;

	dfs44(6,8);

	std::cout<<"深度优先算法"<<std::endl;
	std::cout<<"面积："<<sum<<std::endl;


	system("pause");
	return 0;
}