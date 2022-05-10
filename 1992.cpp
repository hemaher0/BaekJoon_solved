#include<iostream>
#include<string>
using namespace std;
int ** graph;
void quadtree(int s, int e, int size)
{
	if (size == 1)
	{
		cout << graph[s][e];
	}
	else
	{
		int pivot = graph[s][e];
		bool mode = false;
		for (long long i = s; i < s + size; i++)
		{
			for (long long j = e; j < e + size; j++)
			{
				if (pivot != graph[i][j])
				{
					mode = true;
					break;
				}
			}
			if (mode)
				break;
		}
		if (mode)
		{
			cout << "(";
			quadtree(s, e, size / 2);
			quadtree(s, e + size / 2, size / 2);
			quadtree(s + size / 2, e, size / 2);
			quadtree(s + size / 2, e + size / 2, size / 2);
			cout << ")";
		}
		else
			cout << pivot;
	}
}
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	graph = new int* [N];
	for (long long i = 0; i < N; i++)
	{
		graph[i] = new int[N];
		string s;
		cin >> s;
		for (long long j = 0; j < N; j++)
		{
			graph[i][j] = s[j]-'0';
		}
	}
	quadtree(0, 0, N);
	return 0;
}