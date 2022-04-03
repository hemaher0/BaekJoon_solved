#include<iostream>
#include<algorithm>
using namespace std;
int* dp;
int* twostep;
int* onestep;
int* score;
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	dp = new int[N + 1];
	twostep = new int[N + 1];
	onestep = new int[N + 1];
	score = new int[N + 1];
	for (int i = 1; i <= N; i++)
	{
		cin >> score[i];
	}
	dp[1] = score[1];
	dp[2] = score[1] + score[2];
	twostep[1] = dp[1];
	twostep[2] = score[2];
	for (int i = 3; i <= N; i++)
	{
		twostep[i] = dp[i - 2] + score[i];
		onestep[i] = twostep[i - 1] + score[i];
		dp[i] = max(onestep[i], twostep[i]);
	}
	cout << dp[N];
	return 0;
}