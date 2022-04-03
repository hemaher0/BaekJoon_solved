#include<iostream>
#include<algorithm>
using namespace std;
int dp[301];
int score[301];
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> score[i];
	dp[1] = score[1];
	dp[2] = score[1] + score[2];
	for (int j = 3; j <= N; j++)
		dp[j] = max(dp[j - 2] + score[j], dp[j - 3] + score[j - 1] + score[j]);
	cout << dp[N];
	return 0;
}