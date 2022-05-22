#include<iostream>
#include<string>
#include<queue>
using namespace std;
int N;
int M;
struct pr
{
	pr(int x = 0, int y = 0, int z = 0)
	{
		n = x;
		v = y;
		c = z;
	}
	int n;
	int v;
	int c;
};
pr** maze;
int travel()
{
	int r, c;
	r = 0;
	c = 0;
	queue<pair<int, int>> q;
	maze[0][0].v = 1;
	maze[0][0].c = 1;
	q.push(make_pair(0, 0));
	int min = maze[N - 1][M -1].c;
	while (!q.empty())
	{
		r = q.front().first;
		c = q.front().second;
		q.pop();
		if (r == N - 1 && c == M - 1)
		{
			if (min > maze[r][c].c + 1)
			{
				min = maze[r][c].c;
			}
		}
		else
		{
			
			if (r + 1 < N)
			{
				if (maze[r + 1][c].n && !maze[r + 1][c].v)
				{
					if (maze[r + 1][c].c > maze[r][c].c + 1)
					{
						maze[r + 1][c].c = maze[r][c].c + 1;
					}
					maze[r + 1][c].v = 1;
					q.push(pair<int, int>(r + 1, c));
				}
			}
			if (r - 1 >= 0)
			{
				if (maze[r - 1][c].n && !maze[r - 1][c].v)
				{
					if (maze[r - 1][c].c > maze[r][c].c + 1)
					{
						maze[r - 1][c].c = maze[r][c].c + 1;
					}
					maze[r - 1][c].v = 1;
					q.push(pair<int, int>(r - 1, c));
				}
			}
			if (c + 1 < M)
			{
				if (maze[r][c + 1].n && !maze[r][c + 1].v)
				{
					if (maze[r][c + 1].c > maze[r][c].c + 1)
					{
						maze[r][c + 1].c = maze[r][c].c + 1;
					}
					maze[r][c + 1].v = 1;
					q.push(pair<int, int>(r, c + 1));
				}
			}
			if (c - 1 >= 0)
			{
				if (maze[r][c - 1].n && !maze[r][c - 1].v)
				{
					if (maze[r][c - 1].c > maze[r][c].c + 1)
					{
						maze[r][c - 1].c = maze[r][c].c + 1;
					}
					maze[r][c - 1].v = 1;
					q.push(pair<int, int>(r, c - 1));
				}
			}
		}
	}
	return min;
}
using namespace std;
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	maze = new pr* [N];
	for (int i = 0; i < N; i++)
	{
		maze[i] = new pr [M];
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			maze[i][j].n = s[j]- '0';
			maze[i][j].v = 0;
			maze[i][j].c = 10001;
		}
	}
	cout << travel();
	return 0;
}