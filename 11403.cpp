#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int v[101][101];
int N;
int travel(int i, int j)
{
	int visited[101] = { 0 };
	queue<int>x;
	x.push(i);
	while (!x.empty())
	{
		int k = x.front();
		x.pop();
		if (k == j && visited[k])
		{
			return 1;
		}
		else
		{
			for (int m = 1; m <= N; m++)
			{
				if (v[k][m])
				{
					if (!visited[m])
					{
						visited[m] = 1;
						x.push(m);
					}
				}
			}
		}
	}
	return 0;
}
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> v[i][j];
		}
	}
	for (int k = 1; k <= N; k++)
	{
		for (int l = 1; l <= N; l++)
		{
			cout << travel(k, l)<<" ";
		}
		cout << '\n';
	}
	return 0;
}