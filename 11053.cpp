#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int>s;
    int dp[1001] = { 0, };
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        s.push_back(k);
    }
    fill(dp, dp + 1001, 1);
    int res = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (s[i] > s[j] && dp[i] <= dp[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
                if (dp[i] > res) res = dp[i];
            }
        }
    }
    cout << res;
    return 0;
}