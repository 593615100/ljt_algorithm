#include<iostream>
#include<stack>
using namespace std;

int a46[5][4] = {
	{5,3,5,3},
	{1,5,3,0},
	{2,3,5,1},
	{6,1,1,5},
	{1,5,5,4}
};

struct Note
{
	Note(int a,int b,int st = 0):x(a),y(b),step(st){}; //构造函数
	int x;
	int y;
	int step;
};

int book46[10][10] ={0};
bool flag = false;
stack<Note> sta;

void dfs46(int x,int y,int front)
{
	if (x == 4&&y == 4)
	{
		while (!sta.empty())
		{
			struct Note note = sta.top();
			std::cout<<"("<<note.x<<","<<note.y<<")"<<std::endl;
			sta.pop();
		}
		flag = true;
		return;
	}

	if(x > 5 || y > 4 || x < 0 || y < 0) //足迹越界
		return;

	if(book46[x][y] == 1)
		return;

	book46[x][y] = 1;
	sta.push(Note(x,y));
	if(a46[x][y] ==5 || a46[x][y] == 6)
	{
		if(front == 1)
			dfs46(x,y+1,1);

		if(front == 2)
			dfs46(x + 1,y,2);

		if(front == 3)
			dfs46(x,y -1,3);

		if(front == 4)
			dfs46(x - 1,y,4);
	}

	if(a46[x][y] >= 1 && a46[x][y] <= 4)
	{
		if(front == 1){
			dfs46(x + 1,y,2);
			dfs46(x - 1,y,4);
		}

		if(front == 2){
			dfs46(x,y+1,1);
			dfs46(x,y-1,3);
		}

		if(front == 3){
			dfs46(x - 1,y,4);
			dfs46(x + 1,y,2);
		}

		if(front == 4){
			dfs46(x,y+1,1);
			dfs46(x,y-1,3);
		}
	}
	book46[x][y] = 0;
	sta.pop();
	return;


}
int main46()
{
	dfs46(0,0,1);

	if (flag)
	{
		std::cout<<"有方案！"<<std::endl;
	} 
	else
	{
		std::cout<<"无方案！"<<std::endl;
	}

	system("pause");
	return 0;
}
