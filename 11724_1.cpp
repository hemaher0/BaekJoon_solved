#include<iostream>
#include<queue>
using namespace std;
vector<int> graph[1001];
queue<int> q;
int visited[1001];
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	for (int j = 0; j < M; j++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
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
			for (int i = 0; i < graph[x].size(); i++)
			{
				int val = graph[x][i];
				if (!visited[val])
				{
					if (val)
					{
						q.push(val);
						visited[val] = 1;
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