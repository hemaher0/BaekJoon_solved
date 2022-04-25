#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    s = s + '-';
    int tmp = 0;
    int sum = 0;
    int k = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            tmp = tmp * 10 + s[i] - '0';
        }
        else
        {
            sum += tmp * k;
            tmp = 0;
        }
        if (s[i] == '-')
        {
            k = -1;
        }
    }
    
    cout << sum;
    return 0;
}