#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main_2_3()
{
	int player_a[3] = {2,4,1};
	int player_b[3] = {3,1,3};

	queue<int> hand_a; 
	queue<int> hand_b; 
	stack<int> table;
	queue<int> table_temp_a;
	queue<int> table_temp_b;

	for(int i = 0;i < 3;i++)
	{
		hand_a.push(player_a[i]);
		hand_b.push(player_b[i]);
	}

	while(!hand_a.empty() && !hand_b.empty())
	{
		int temp_a = hand_a.front();
		bool flag = true;
		hand_a.pop();
		if (table.empty())
		{
			table.push(temp_a);
		}else{
			while(!table.empty())
			{
				int _temp = table.top();
				table_temp_a.push(_temp);
				table.pop();
				if(_temp == temp_a)
				{
					hand_a.push(temp_a);
					while(!table_temp_a.empty())
					{
						hand_a.push(table_temp_a.front());
						table_temp_a.pop();
					}
					flag = false;
					break;
				}
			}
			stack<int> stack_temp;
			while (!table_temp_a.empty())
			{			
				stack_temp.push(table_temp_a.front());
				table_temp_a.pop();
			}
			while(!stack_temp.empty())
			{
				table.push(stack_temp.top());
				stack_temp.pop();
			}
			if (flag)
			{
				table.push(temp_a);
			}
		}


		int temp_b = hand_b.front();
		hand_b.pop();
		if (table.empty())
		{
			table.push(temp_b);
		}else{
			while(!table.empty())
			{
				int _temp = table.top();
				table_temp_b.push(_temp);
				table.pop();
				if(_temp == temp_b)
				{
					hand_b.push(temp_b);
					while(!table_temp_b.empty())
					{
						hand_b.push(table_temp_b.front());
						table_temp_b.pop();
					}
					flag = false;
					break;
				}
			}
			stack<int> stack_temp;
			while (!table_temp_b.empty())
			{			
				stack_temp.push(table_temp_b.front());
				table_temp_b.pop();
			}
			while(!stack_temp.empty())
			{
				table.push(stack_temp.top());
				stack_temp.pop();
			}
			if (flag)
			{
				table.push(temp_b);
			}
		}
	}
	if (hand_a.empty())
	{
		std::cout<<"B WIN!"<<std::endl;
		while(!hand_b.empty())
		{
			std::cout<<hand_b.front()<<" "<<std::endl;
			hand_b.pop();
		}
	}else{
		std::cout<<"A WIN!"<<std::endl;
		while(!hand_a.empty())
		{
			std::cout<<hand_a.front()<<" "<<std::endl;
			hand_a.pop();
		}
	}
	system("pause");
	return 0;
}