#include<iostream>
#include<queue>
using namespace std;
int main()
{
	int M, N;
	cin >> M >> N;
	queue<int>p;
	while (M <= N)
	{
		int j;
		bool r = true;
		for (j = 2; j*j <= M; j++)
		{
			if (M % j == 0)
			{
				r = false;
				break;
			}
		}
		if (r)
		{
			if (M != 1)
			{
				if (p.empty())
					p.push(M);
				else
					if (p.back() != M)
						p.push(M);
			}
		}
		M++;
	}
	while (!p.empty())
	{
		cout << p.front() << '\n';
		p.pop();
	}
	return 0;
}