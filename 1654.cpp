#include<iostream>
#include<vector>
using namespace std;
int upperbound(vector<long long>, int, long long, int);
int totalsum(vector<long long>, long long, int);
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int K;
	int N;
	cin >> K >> N;
	long long max;
	long long min;
	vector<long long>line;
	for (int i = 0; i < K; i++)
	{
		long long length;
		cin >> length;
		line.insert(line.begin(), length);
		if (i == 0)
		{
			max = length;
			min = length;
		}
		if (length > max)
			max = length;
		if (length < min)
			min = length;
	}
	long long x = upperbound(line, K, max, N);
	while (totalsum(line, x+1, K)>=N)
	{
		++x;
	}
	cout << x;
}
int upperbound(vector<long long> line, int K, long long max, int N)
{
	long long  st = 0;
	long long ed = max;
	long long mid = (st + ed) / 2;
	while (st < ed)
	{
		if (st % 2 + ed % 2)
		{
			mid = (st + ed + 1) / 2;
		}
		else
		{
			mid = (st + ed) / 2;
		}
		int totale = totalsum(line, ed, K);
		int totalm = totalsum(line, mid, K);
		if (totalm < N)
			ed = mid - 1;
		else
			if (totale == N)
			{
				return ed;
			}
			else
			{
				if (totale < totalm)
				{
					if (totalm == N)
					{
						return mid;
					}
					else
					{
						st = mid;
					}
				}
				else if (totale == totalm)
				{
					ed = mid - 1;
				}
			}
	}
	return st;
}
int totalsum(vector<long long> line, long long mid, int K)
{
	int total = 0;
	for (int j = 0; j < K; j++)
	{
		total = total + line[j] / mid;
	}
	return total;
}