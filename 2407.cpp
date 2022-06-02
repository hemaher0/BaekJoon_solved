#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long result[101];
vector<int> sum(vector<int> A, vector<int> B)
{
	vector<int> result;
	int num = 0;
	int kC{ 0 };
	while (!A.empty() || !B.empty())
	{
		int kA{0}, kB{0};
		if (!A.empty())
		{
			kA = A.back();
			A.pop_back();
		}
		if (!B.empty())
		{
			kB = B.back();
			B.pop_back();
		}
		int kS = kA + kB + kC;
		if (kS >= 10)
		{
			kC = 1;
			kS = kS % 10;
		}
		else
		{
			kC = 0;
		}
		result.push_back(kS);
	}
	if (kC)
	{
		result.push_back(kC);
	}
	reverse(result.begin(), result.end());
	return result;
}
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v[101];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0||j == i)
				v[i].push_back(vector<int> (1, 1));
			else
			{
				vector<int> tmp = sum(v[i - 1][j - 1], v[i - 1][j]);
				v[i].push_back(tmp);
			}
		}
	}
	for (int i = 0; i < v[n][m].size(); i++)
	{
		cout << v[n][m][i];
	}
	return 0;
}