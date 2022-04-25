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
    int p = 0;
    int m = 0;
    int tmp = 0;
    bool isminus = false;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '+' or s[i] == '-')
        {
            if (!isminus)
            {
                if (s[i] == '-')
                {
                    isminus = true;
                }
                p = p + tmp;
            }
            else
            {
                m = m + tmp;
            }
            tmp = 0;
        }
        else
        {
            tmp = tmp * 10 + s[i] - '0';
        }
    }
    if (tmp)
    {
        if (isminus)
        {
            m = m + tmp;
        }
        else
        {
            p = p + tmp;
        }
    }
    cout << p - m;
    return 0;
}