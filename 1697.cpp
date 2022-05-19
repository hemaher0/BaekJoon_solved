#include<iostream>
#include<queue>
using namespace std;
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, K, X;
	vector<int> visited(100000, 0);
	queue<pair<int, int>> q;
	cin >> N >> K;
	q.push(make_pair(N, 0));
	X = q.front().first;
	while (!q.empty())
	{
		X = q.front().first;
		if (X != K)
		{
			if (X + 1 <= 100000)
			{
				if (!visited[X + 1])
				{
					visited[X + 1] = 1;
					q.push(make_pair(X + 1, q.front().second + 1));
				}
				if (2 * X <= 100000)
				{
					if (!visited[2 * X])
					{
						visited[2 * X] = 1;
						q.push(make_pair(2 * X, q.front().second + 1));
					}
				}
			}
			if (X - 1 >= 0)
			{
				if (!visited[X - 1])
				{
					visited[X - 1] = 1;
					q.push(make_pair(X - 1, q.front().second + 1));
				}
			}
			q.pop();
		}
		else
		{
			break;
		}
	}
	cout << q.front().second;
	return 0;
}