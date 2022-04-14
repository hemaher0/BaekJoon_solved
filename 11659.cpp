#include<iostream>
using namespace std;
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N>>M;
	int* v = new int[N + 1];
	long long* total = new long long[N];
	total[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
		total[i] = total[i - 1] + v[i];
	}
	for (int j = 0; j < M; j++)
	{
		int s1, s2;
		cin >> s1 >> s2;
		cout << total[s2] - total[s1 - 1]<<'\n';
	}
	return 0;
}