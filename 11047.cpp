#include<iostream>
using namespace std;
int main()
{
    int N, K, tmp, ans;
    cin >> N >> K;
    ans = 0;
    tmp = K;
    int* v = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> v[N - i - 1];
    }
    for (int i = 0; i < N; i++)
    {
        if (tmp / v[i] > 0)
        {
            ans = ans + tmp / v[i];
            tmp %= v[i];
        }
    }
    cout << ans;
}