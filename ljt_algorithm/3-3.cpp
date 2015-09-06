#include<iostream>
using namespace std;

int number_match(int num)
{
	int result = 0;
	int flag[10] = {6,2,5,5,4,5,6,3,7,6};

	while (num/10 != 0)
	{
		result += flag[num%10];
		num /= 10;
	}
	result += flag[num];
	return result;
}
int main_3_3()
{
	int count = 0;
	int numberMatch = 18;
	int a,b,c;

	for (a = 0;a < 1111;a++)
		for (b = 0;b < 1111;b++)
		{
			c = a + b;
			if(number_match(a) + number_match(b) + number_match(c) == numberMatch - 4){
				count++;
				std::cout<<a<<" + "<<b<<" = "<<c<<std::endl;
			}
		}
	std::cout<<"总共可以组成:"<<count<<"个表达式"<<std::endl;
	system("pause");

	return 0;
}