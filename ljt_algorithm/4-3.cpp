#include<iostream>
#include<queue>
using namespace std;

int book43[11][11] = {0};
int a43[4][4] = {0};
struct Note
{
	Note(int a,int b,int st = 0):x(a),y(b),step(st){}; //构造函数
	int x;
	int y;
	int step;
};

int main_4_3()
{
	bool flag = false;
	queue<Note> que;
	int tx,ty,p,q,step;
	step = 0;
	p = 3;
	q = 2;
	a43[1][2] = 1;
	a43[3][1] = 1;
	a43[2][3] = 1;
	int next[4][2] = {
		{0,1},{1,0},{0,-1},{-1,0}
	};
	que.push(Note(1,1,step++));
	book43[1][1] = 1;
	while(!que.empty()){
		for (int i = 0;i < 4;i++)
		{
			tx = que.front().x + next[i][0];
			ty = que.front().y + next[i][1];

			if(tx > 11 || ty > 11 || tx < 1 || ty < 1) //足迹越界
				continue;

			if (tx == p && ty == q) //找到
			{
				flag = true;
				break;
			}

			if (book43[tx][ty] == 0 && a43[tx][ty] == 0) //判断这个点是否符合条件
			{
				book43[tx][ty] = 1;
				que.push(Note(tx,ty,step++));

			}
		}
		if(flag)
			break;
		que.pop();
	}

	std::cout<<que.back().x<<" -- "<<que.back().y<<std::endl;

	system("pause");
	return 0;

}