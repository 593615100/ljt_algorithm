#include<iostream>
using namespace std;

int a[10] = {12,35,99,18,76,21,58,99,81,67};

void Quik_Sort(int left,int right)
{
	int temp = a[left];
	int i = left,j = right;
	int t;

	if(left >= right)
		return;

	while(i != j)
	{
		while(a[j] >= temp && j > i)
			j--;

		while(a[i] <= temp && i < j)
			i++;

		if(i < j){
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	
	a[left] = a[j];
	a[j] = temp;

	Quik_Sort(left,i -1);
	Quik_Sort(i + 1,right);
}
int quik_main()
{
	std::cout<<"ÅÅÐòÇ°"<<endl;
	for(int i = 0;i < 10;i++)
	{
		std::cout<<a[i]<<" ";
	}

	std::cout<<endl;

	Quik_Sort(0,9);

	std::cout<<"ÅÅÐòºó"<<endl;
	for(int i = 0;i < 10;i++)
	{
		std::cout<<a[i]<<" ";
	}
	std::cout<<endl;
	system("pause");
	return 0;
}