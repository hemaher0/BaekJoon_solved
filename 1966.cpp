#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int print(queue<pair<int, int>>, int, int);
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (auto i = 0; i < n; i++)
	{
		int M, N;
		cin >> N >> M;
		int max = 0;
		queue<pair<int, int>> printer;
		for (auto j = 0; j < N; j++)
		{
			int rank;
			cin >> rank;
			printer.push(make_pair(rank, j));
			if (rank > max)
			{
				max = rank;
			}
		}
		int count = 0;
		cout<<print(printer, max, M)<<'\n';
	}

	return 0;
}
int print(queue<pair<int, int>> p, int max, int M)
{
	queue<pair<int, int>>q;
	queue<pair<int, int>>small;
	int count = 0;
	int tmax;
	int Nsize = p.size();
	while (Nsize != 0)
	{
		tmax = 0;
		for (int i = 0; i < Nsize; i++)
		{
			if (p.front().first == max)
			{
				q.push(p.front());
				while (!small.empty())
				{
					p.push(small.front());
					small.pop();
				}
			}
			else if (p.front().first < max)
			{
				if (tmax < p.front().first)
				{
					tmax = p.front().first;
					while (!small.empty())
					{
						p.push(small.front());
						small.pop();
					}
				}
				small.push(p.front());
			}
			p.pop();
		}
		while (!q.empty())
		{
			Nsize--;
			max = tmax;
			if (q.front().second == M)
			{
				return count + 1;
			}
			else
				count++;
			q.pop();
		}
		while (!p.empty())
		{
			small.push(p.front());
			p.pop();
		}
		swap(p, small);
	}
	return count;
}