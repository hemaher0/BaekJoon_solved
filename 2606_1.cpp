#include<iostream>
using namespace std;
int computer[101][101] = { 0, };
int visited[101] = { 0, };
int N = 0;
void dfs(int pivot)
{
	for (int l = 1; l <= N; l++)
		{
			if (computer[pivot][l] && !visited[l])
			{
				visited[l] = 1;
				dfs(l);
			}
		}
}
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int M, count = 0;
	cin >> N >> M;
	for (int j = 0; j < M; j++)
	{
		int k, l;
		cin >> k >> l;
		computer[k][l] = 1;
		computer[l][k] = 1;
	}
	dfs(1);
	for (int l = 2; l <= N; l++)
	{
		if (visited[l])
		{
			count++;
		}
	}
	cout << count;
	return 0;
}
