#include<iostream>
using namespace std;

int f73[1000] = {0},n73,m73,sum73 = 0;

void init()
{
	int i;
	for(i = 1;i <= n73;i++)
		f73[i] = i;
}

int getf(int v)
{
	if(f73[v] == v)
		return v;
	else{
		f73[v] = getf(f73[v]);
		return f73[v];
	}
}

int find(int x)
{
	int r =x;
	while(r != f73[x])
		r = f73[r];
	int i = x,j;
	while(f73[i] != r){
		j = f73[i];
		f73[i] = r;
		i = j;
	}
	return r;
}
void merge(int v,int u){
	int t1,t2;
	//t1 = getf(v);
	//t2 = getf(u);
	t1 = find(v);
	t2 = find(u);
	if(t1 != t2)
		f73[t2] = t1;
}

int main()
{
	int x,y;
	std::cin>>n73>>m73;
	init();
	for(int i = 1;i <=m73;i++)
	{
		std::cin>>x>>y;
		merge(x,y);
	}

	for (int i = 1;i <= n73;i++)
	{
		if(f73[i] == i)
			sum73++;
	}

	std::cout<<sum73<<std::endl;

	system("pause");
	return 0;
}
