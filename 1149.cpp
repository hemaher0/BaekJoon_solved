#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
int street[1001][4];
int dp[1001][4];
int ans = 1000000;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> street[i][j];
		}
	}
	dp[1][1] = street[1][1];
	dp[1][2] = street[1][2];
	dp[1][3] = street[1][3];
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= 3; j++) {
			int level = 0;
			int arr[2];
			for (int k = 1; k <= 3; k++) {
				if (j != k) {
					arr[level] = k;
					level++;
				}
			}
			dp[i][j] = min(dp[i-1][arr[0]], dp[i-1][arr[1]]) + street[i][j];
		}
	}
	
	for (int i = 1; i <= 3; i++) {
		ans = min(ans, dp[N][i]);
	}
	cout << ans;
	return 0;
}

