#include<iostream>
#include<queue>
using namespace std;
int computer[101][101] = { 0, };
int visited[101] = { 0, };
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, M, count;
	cin >> N >> M;
	count = 0;
	queue<int> temp;
	for (int j = 0; j < M; j++)
	{
		int k, l;
		cin >> k >> l;
		computer[k][l] = 1;
		computer[l][k] = 1;
	}
	for (int k = 1; k <= N; k++)
	{
		if (computer[1][k])
		{
			temp.push(k);
			visited[k] = 1;
		}
	}
	while (!temp.empty())
	{
		int pivot = temp.front();
		temp.pop();
		for (int l = 1; l <= N; l++)
			if (computer[pivot][l])
				if (!visited[l])
				{
					temp.push(l);
					visited[l] = 1;
				}
	}
	for (int l = 2; l <= N; l++)
	{
		if (visited[l])
			count++;
	}
	cout << count;
	return 0;
}
