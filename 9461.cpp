#include<iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    long long dp[101] = { 0, };
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        for (int j = 4; j <= N; j++)
        {
            if (!dp[j])
            {
                dp[j] = dp[j - 3] + dp[j - 2];
            }
        }
        cout << dp[N] << endl;
    }
    return 0;
}