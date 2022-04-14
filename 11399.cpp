#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, total;
	cin >> N;
	int* line = new int[N];
	int* sum = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> line[i];
	}
	sort(line, line + N);
	sum[0] = line[0];
	total = sum[0];
	for (int j = 1; j < N; j++)
	{
		sum[j] = sum[j - 1] + line[j];
		total += sum[j];
	}
	cout << total;
	return 0;
}