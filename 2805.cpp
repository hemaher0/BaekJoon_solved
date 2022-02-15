#include<iostream>
using namespace std;
long long totalsum(int*, long long, int, int);
int main()
{
	int N, M;
	cin>>N>>M;
	long long max = 0;
	int* tree = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin>>tree[i];
		if (max < tree[i])
			max = tree[i];
	}
	long long st = 0;
	long long ed = max;
	long long mid = (st + ed) / 2;
	long long totalm;
	long long height = st;
	while (st <= ed)
	{
		mid = (st + ed) / 2;
		totalm = totalsum(tree, mid, N, M);
		if (totalm < M)
			ed = mid - 1;
		else
		{
			if (totalm == M)
			{
				height = mid;
				break;
			}
			else
				st = mid + 1;
		}
	}
	totalm = totalsum(tree, mid, N, M);
	if (totalm == M)
		height = mid;
	else
		height = ed;
	
	cout<<height;
	return 0;
}
int height;
long long totalsum(int * tree, long long height, int N, int M)
{
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (tree[i] >= height)
		{
			sum = sum + tree[i] - height;
			if (sum > M)
				return sum;
		}
	}
	return sum;
}