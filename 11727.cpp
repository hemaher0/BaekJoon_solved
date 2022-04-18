#include<iostream>
using namespace std;
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int* dp = new int[n];
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
	}
	cout << dp[n];
	return 0;
}