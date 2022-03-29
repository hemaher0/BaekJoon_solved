#include<iostream>
#include<algorithm>
using namespace std;
int* dp;
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	dp = new int[N];
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= N; i++)
	{
		dp[i] = 1 + dp[i - 1];
		if (i % 3 == 0)
			dp[i] = min(dp[i], 1 + dp[i / 3]);
		if (i % 2 == 0)
			dp[i] = min(dp[i], 1 + dp[i / 2]);
	}
	cout << dp[N];
	return 0;
}