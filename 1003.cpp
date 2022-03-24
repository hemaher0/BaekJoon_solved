#include<iostream>
using namespace std;
struct num
{
    int zerocount = 0;
    int onecount = 0;
    num(int a = 0, int b = 0)
    {
        zerocount = a;
        onecount = b;
    }
};
num fibonacci(int n, num arr[], int checklist[])
{
    if (checklist[n])
    {
        return arr[n];
    }
    else
    {
        checklist[n] = 1;
        if (n == 0)
        {
            arr[n].zerocount++;
        }
        else if (n == 1)
        {
            arr[n].onecount++;
        }
        else
        {
            num a = fibonacci(n - 1, arr, checklist);
            num b = fibonacci(n - 2, arr, checklist);
            arr[n].zerocount = a.zerocount + b.zerocount;
            arr[n].onecount = a.onecount + b.onecount;
        }
        return arr[n];
    }
}
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        int* checklist = new int[N + 1];
        num* arr = new num[N + 1];
        for (int j = 0; j <= N; j++)
        {
            checklist[j] = 0;
        }
        fibonacci(N, arr, checklist);
        cout << arr[N].zerocount << " " << arr[N].onecount << '\n';
    }
	return 0;
}