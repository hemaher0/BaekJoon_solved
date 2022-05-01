#include<iostream>
#include<queue>
using namespace std;
int graph[1001][1001];
int visited[1001];
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;

	queue<int> q;
	for (int j = 0; j < M; j++)
	{
		int u, v;
		cin >> u >> v;
		graph[u][v] = 1;
		graph[v][u] = 1;
	}
	int count = 0;
	for (int k = 1; k <= N; k++)
	{
		bool mode = false;
		while (!visited[k] or !q.empty())
		{
			int x;
			if (!q.empty())
			{
				x = q.front();
				q.pop();
			}
			else
			{
				count++;
				x = k;
			}
			for (int i = 1; i <= N; i++)
			{
				if (!visited[i])
				{
					if (graph[x][i])
					{
						q.push(i);
						visited[i] = 1;
						mode = true;
					}
				}
			}
			if (!mode)
				break;
		}
	}
	cout << count;
	return 0;
}