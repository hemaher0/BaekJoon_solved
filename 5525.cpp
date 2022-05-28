#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	int count = 0;
	vector<char>tmp;
	char * x = new char[M];
	cin >> x;
	for (int i = 0; i < M; i++)
	{
		char c = x[i];
		if (tmp.empty())
		{
			if (c == 'I')
			{
				tmp.push_back(c);
			}
				
		}
		else
		{
			if (tmp.back() == c)
			{
				if (tmp.size() == 2 * N + 1)
				{
					count = count + 1;
				}
				tmp.clear();
				if (c == 'I')
				{
					tmp.push_back(c);
				}
			}
			else
			{
				tmp.push_back(c);
				if (tmp.size() == 2 * N + 1)
				{
					count = count + 1;
					tmp.pop_back();
					tmp.pop_back();
				}
			}
		}
	}
	if (tmp.size() == 2 * N + 1)
	{
		count = count + 1;
	}
	cout << count;
	return 0;
}