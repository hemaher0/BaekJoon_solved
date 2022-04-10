#include<iostream>
using namespace std;
int dp[12];
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 0; i < T; i++)
	{
		int s;
		cin >> s;
		for (int j = 4; j <= s; j++)
		{
			if(!dp[j])
				dp[j] = dp[j - 3] + dp[j - 2] + dp[j - 1];
		}
		cout << dp[s]<<'\n';
	}
	return 0;
}
