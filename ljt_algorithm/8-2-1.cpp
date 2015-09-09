#include<iostream>
using namespace std;
int dis821[7],book821[7] = {0,0,0,0,0,0,0};
int h821[7],pos821[7],size;

void swap(int x,int y)
{
	int t ;
	t = h821[x];
	h821[x] = h821[y];
	h821[y] = t;

	t = pos821[h821[x]];
	pos821[h821[x]] = pos821[h821[y]];
	pos821[h821[y]] = t;
}


void siftdown(int v)
{
	int t,flag = 0;
	while(v*2 <= size && flag == 0)
	{
		if(dis821[h821[v]] > dis821[h821[2 * v]])
			t = v * 2;
		else
			t = v;

		if (v*2 + 1 <= size)
		{
			if(dis821[h821[t]] > dis821[h821[2 * v + 1]])
				t = v * 2 + 1;
		}

		if(t != v)
		{
			swap(t,v);
			v = t;
		}else
			flag = 1;
	}
	return;
}

void siftup(int v)
{
	int flag = 0;
	if(v == 1) return;

	while (v != 1 && flag == 0)
	{
		if(dis821[h821[v]] < dis821[h821[v/2]])
			swap(v,v/2);
		else
			flag = 1;
		v = v/2;
	}
	return;
}

int pop()
{
	int t;
	t = h821[1];
	pos821[t] = 0;
	h821[1] = h821[size];
	pos821[h821[1]] = 1;
	size--;
	siftdown(1);
	return t;
}
int main()
{
	int n,m,i,j,k,count = 0,min,sum = 0;
	int u[19],v[19],w[19],first[19],next[19];
	int inf = 99999;

	std::cin>>n>>m;

	for(i = 1;i <= m;i++)
		std::cin>>u[i]>>v[i]>>w[i];

	for(i = m + 1;i <= 2*m;i++){
		u[i] = v[i - m];
		v[i] = u[i - m];
		w[i] = w[i - m];
	}

	for(i = 1;i <= n;i++)
		first[i] = -1;

	for (i = 1;i <= 2*m;i++)
	{
		next[i] = first[u[i]];
		first[u[i]] = i;
	}

	book821[1] = 1;
	count++;
	
	dis821[1] = 0;
	for(i = 2;i <= n;i++)
		dis821[i] = inf;

	k = first[1];
	while (k != -1)
	{
		dis821[v[k]] = w[k];
		k = next[k];
	}

	size = n;
	for (i = 1;i <= size;i++)
	{
		h821[i] = i;
		pos821[i] = i;
	}

	for (i = size/2 ;i >= 1;i--)
	{
		siftdown(i);
	}

	pop();

	while(count < n){
		j = pop();
		book821[j] = 1;
		count++;
		sum = sum + dis821[j];
		
		k = first[j];
		while (k != -1)
		{
			if(book821[v[k]] == 0 && dis821[v[k]] > w[k])
			{
				dis821[v[k]] = w[k];
				siftup(pos821[v[k]]);
			}

			k = next[k];
		}
	}
}