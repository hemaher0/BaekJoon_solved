#include<iostream>
#include<queue>
using namespace std;
void travel(queue<pair<int, int>> q, int ** visited, int **farm)
{
	int x = q.front().first;
	int y = q.front().second;
	q.pop();
	if (!visited[x + 1][y])
	{
		visited[x + 1][y] = 1;
		if (farm[x + 1][y])
		{
			q.push(make_pair(x + 1, y));
		}
	}
	if (!visited[x - 1][y])
	{
		visited[x - 1][y] = 1;
		if (farm[x - 1][y])
			q.push(make_pair(x - 1, y));
	}
	if (!visited[x][y + 1])
	{
		visited[x][y + 1] = 1;
		if (farm[x][y + 1])
			q.push(make_pair(x, y + 1));
	}
	if (!visited[x][y - 1])
	{
		visited[x][y - 1] = 1;
		if (farm[x][y - 1])
			q.push(make_pair(x, y - 1));
	}
	if (!q.empty())
	{
		travel(q, visited, farm);
	}
}
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T, M, N, K;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> K;
		int** farm;
		int** visited;
		farm = new int*[M + 2];
		visited = new int* [M + 2];
		for (int j = 0; j < M + 2; j++)
		{
			farm[j] = new int[N + 2];
			visited[j] = new int[N + 2];
			for (int k = 0; k < N + 2; k++)
			{
				farm[j][k] = 0;
				visited[j][k] = 0;
			}
		}
		for (int k = 0; k < K; k++)
		{
			int x, y;
			cin >> x >> y;
			farm[x + 1][y + 1] = 1;
		}
		int count = 0;
		for (int l = 1; l < M + 1; l++)
		{
			for (int m = 1; m < N + 1; m++)
			{
				queue<pair<int, int>> q;
				if (!visited[l][m])
				{
					visited[l][m] = 1;
					if (farm[l][m])
					{
						count++;
						q.push(make_pair(l, m));
						travel(q, visited, farm);
					}
				}
			}
		}
		cout << count << '\n';
	}
	return 0;
}