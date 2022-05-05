#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int r, c;
int count(int x, int y, int size, long long cnt)
{
	if (size == 2)
	{
		if (r == x)
		{
			if (c == y)
			{
				return cnt;
			}
			else
			{
				return cnt + 1;
			}
		}
		else
		{
			if (c == y)
			{
				return cnt + 2;
			}
			else
			{
				return cnt + 3;
			}
		}
	}
	else
	{
		if (r < x + size / 2)
		{
			if (c >= y + size / 2)
			{
				cnt = cnt + (size / 2) * (size / 2);
				y = y + size / 2;
			}
		}
		else
		{
			if (c < y + size / 2)
			{
				cnt = cnt + 2 * (size / 2) * (size / 2);
			}
			else
			{
				cnt = cnt + 3 * (size / 2) * (size / 2);
				y = y + size / 2;
			}
			x = x + size / 2;
		}
		return count(x, y, size / 2, cnt);
	}
}
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N>>r>>c;
	int size = 1;
	while (N--)
	{
		size *= 2;
	}
	cout << count(0, 0, size, 0) ;
	return 0;
}