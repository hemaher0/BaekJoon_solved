#include<iostream>
#include<vector>
using namespace std;
int getlcm(int M, int N)
{
    int x[2] = { M, N };
    vector<int> ml;
    ml.push_back(1);
    int i = 2;
    int result = 1;
    while (x[0] != 1 || x[1] != 1)
    {
        int mode = 0;
        for (int k = 0; k < 2; k++)
        {
            if (x[k] != 1 && !(x[k] % i))
            {
                x[k] /= i;
                mode++;
            }
        }
        if (mode)
        {
            ml.push_back(i);
        }
        else
        {
            i++;
        }
    }
    while (!ml.empty())
    {
        result *= ml.back();
        ml.pop_back();
    }
    return result;
}
int check(int lcm, int M, int N, int x, int y)
{
    vector<int> v;
    for (int i = 0; i < lcm / M; i++)
    {
        int k = M * i + x;
        if ((k - y) % N) {}
        else
        {
            return k;
        }
        
    }
    return -1;
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        cout << check(getlcm(M, N), M, N, x, y)<<'\n';
    }
    return 0;
}