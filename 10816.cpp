#include<iostream>
#include<algorithm>
using namespace std;
int lower_bound(int v[], int x, int size)
{
	int i1 = 0;
	int i2 = size - 1;
	while (i1 < i2)
	{
		int mid = (i1 + i2) / 2;
		if (v[mid] >= x)
		{
			i2 = mid;
		}
		else
		{
			i1 = mid + 1;
		}
	}
	return i2;
}
int upper_bound(int v[], int x, int size)
{
	int i1 = 0;
	int i2 = size - 1;
	while (i1 < i2)
	{
		int mid = (i1 + i2) / 2;
		if (v[mid] > x)
		{
			i2 = mid;
		}
		else
		{
			i1 = mid + 1;
		}
	}
	return i2;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N;
	int* v = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	sort(v, v + N);
	cin >> M;
	for (int j = 0; j < M; j++)
	{
		int k;
		cin >> k;
		int max = upper_bound(v, k, N);
		int min = lower_bound(v, k, N);
		if (v[max] == k)
			max += 1;
		cout<< max - min<<'\n';
		
	}
	return 0;
}