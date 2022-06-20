#include<iostream>
using namespace std;
int N, M;
int arr[9];
void func(int level)
{
    if (level > M)
    {
        for (int i = 1; i < level; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for (int j = arr[level - 1]; j <= N; j++)
        {
            arr[level] = j;
            func(level + 1);
        }
    }
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    arr[0] = 1;
    func(1);
    return 0;
}