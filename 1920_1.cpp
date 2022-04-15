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
		while (i1 <= i2)
		{
			m = (i1 + i2) / 2;
			if (v[m] < x)
				i1 = m + 1;
			else if (v[m] > x)
				i2 = m - 1;
			else
				break;
		}
		if (v[m] == x)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
	return 0;
}