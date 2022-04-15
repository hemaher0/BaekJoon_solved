#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	int* v = new int[N];;
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	sort(v, v + N);
	int M;
	cin >> M;
	for (int j = 0; j < M; j++)
	{
		int x;
		int i1 = 0;
		int i2 = N - 1;
		int m = (i1 + i2) / 2;
		cin >> x;
		while (v[m] != x)
		{
			if (i2 - i1 <= 1)
			{
				break;
			}
			else
			{
				if (v[m] < x)
				{
					i1 = m + 1;
				}
				else
				{
					i2 = m - 1;
				}
				m = (i1 + i2) / 2;
			}
		}
		if (v[m] == x or v[i1] == x or v[i2] ==x)
		{
			cout << 1 << '\n';
		}
		else
		{
			cout << 0 << '\n';
		}
	}	
	return 0;
}