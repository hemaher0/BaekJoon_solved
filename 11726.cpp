#include<iostream>
using namespace std;
long long dp[1001];
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2])%10007;
	}
	cout << dp[n];
	return 0;
}