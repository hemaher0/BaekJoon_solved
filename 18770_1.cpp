#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	pair<int, int>* X = new pair<int, int>[N];
	for (int i = 0; i < N; i++)
	{
		cin >> X[i].first;
		X[i].second = i;
	}
	sort(X, X + N);
	int count = 0;
	int* ans = new int[N];
	ans[X[0].second] = 0;
	for (int j = 1; j < N; j++)
	{
		if (X[j].first != X[j - 1].first)
		{
			++count;
		}
		ans[X[j].second] = count;
	}
	for (int k = 0; k < N; k++)
	{
		cout << ans[k] << ' ';
	}
	return 0;
}