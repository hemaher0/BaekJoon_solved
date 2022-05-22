#include<iostream>
#include<string>
#include<queue>
using namespace std;
int N;
int M;
int maze[100][100];
bool visited[100][100];
int cnt[100][100];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
int travel()
{
	int r = 0;
	int c = 0;
	queue<pair<int, int>> q;
	visited[r][c] = 1;
	cnt[r][c] = 1;

	q.push(make_pair(0, 0));
	int min = cnt[N - 1][M - 1];

	while (!q.empty())
	{
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = r + dx[i];
			int yy = c + dy[i];
			if (xx < N && xx >= 0 && yy < M && yy >= 0)
			{
				if (maze[xx][yy] && !visited[xx][yy])
				{
					cnt[xx][yy] = cnt[r][c] + 1;
					visited[xx][yy] = true;
					q.push(pair<int, int>(xx, yy));
				}
			}
		}
	}
	return cnt[N - 1][M - 1];
}
using namespace std;
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			maze[i][j] = s[j] - '0';
		}
	}
	cout << travel();
	return 0;
}