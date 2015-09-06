#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int num_count = 1;

//判断下一个位置是否可以放置
bool isSafe(int row,int col,int* QueenList)
{
	bool place = true;
	for (int temp_col = 0;temp_col < col;temp_col++)
	{
		int temp_row = QueenList[temp_col];
		if (temp_row == row)
		{
			place = false;
			break;
		}

		if (col == temp_col)  //应该执行不到吧。。
		{
			place = false;
			break;
		}

		if (abs(temp_row - temp_col) == abs(row - col))
		{
			place = false;
			break;
		}
	}
	return place;
}

bool placeQueen(int col,int* QueenList)
{
	int row = 0;
	int foundSafePos = false;

	if (col == 8) //寻找到第八列则说明已经全部摆下
	{
		num_count++;
		foundSafePos = true;
		std::cout<<num_count<<std::endl;
	}else{
		while (row < 8 && !foundSafePos)  // 从第一行开始搜寻
		{
			if(isSafe(row,col,QueenList))  //如果某一个位置合适 则向下一个位置搜寻
			{
				QueenList[col] = row;
				foundSafePos = placeQueen(col + 1,QueenList); //下一列
				if (!foundSafePos) //如果没有全部放下..为什么行++ （上一步的行++）
				{
					row++;
				}
			}else{
				row++;
			}
		}
	}
	return foundSafePos;
}

int main1()
{
	int queenList[8] = {0};
	for (int i = 0;i < 8;i++)
	{
		std::cout<<"---------------------------------"<<i<<std::endl;
		queenList[0] = i;
		bool res = placeQueen(1,queenList);

		if (res) //搜寻成功
		{
			std::cout<<"  ";
			for (int k = 0;k < 8;k++)
			{
				std::cout<<" "<<k;
			}
			std::cout<<std::endl;
			for (int m = 0;m < 8;m++)
			{
				std::cout<<" "<<m;
				for (int n = 0;n < 8;n++)
				{
					if (m == queenList[n])
					{
						std::cout<<" Q";
					}else{
						std::cout<<" #";
					}
				}
				std::cout<<std::endl;
			}
			std::cout<<"---------------------------------"<<std::endl;
		}else
		{
			std::cout<<"失败！"<<std::endl;
		}
	}

	system("pause");
	return 0;
}

#define N 8
bool matrix[N + 1][N + 1] = {0};

bool isLegal(bool matrix[N + 1][N + 1],int &row,int &col)
{
	for (int i = 1;i <= row - 1;i++ )
		for (int j = 1;j <= N;j++)
		{
			if (matrix[i][j] == 1) //之前的位置上已有棋子，则判断是否与当前位置冲突
			{
				//if(j == col || abs(i - row) == abs(j - col))
				if(j == col || abs(i + j) == abs(row + col))
					return false;
			}
		}
		return true;
}

void printMatrix(bool matrix[N + 1][N + 1])
{
	std::cout<<std::endl;
	std::cout<<"case:  "<<num_count++<<std::endl;
	for (int i = 1;i < N + 1;i++){
		for (int j = 1; j< N + 1;j++)
		{
			if (matrix[i][j] == 1)
			{
				std::cout<<" @ ";
			}else{
				std::cout<<" . ";
			}
		}
		std::cout<<std::endl;
	}
}

void Trial(int i)  
{  
	//  进入本函数时，在N*N的棋盘前i-1行已放置了互不攻击的i-1个棋子  
	//  现从第i行起继续为后续棋子选择合适位置  

	if (i > N)   //  输出当前的合法布局  
		printMatrix(matrix);  
	else  
		for (int j = 1; j <= N; ++j) {  
			matrix[i][j] = 1;  
			if ( isLegal(matrix, i, j) )  
				Trial(i + 1);  
			matrix[i][j] = 0;  
		}  
}  

int main2()
{
	Trial(1);

	system("pause");
	return 0;
}