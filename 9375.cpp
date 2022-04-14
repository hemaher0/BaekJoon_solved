#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		vector<int> v;
		map<string, int> m;
		for (int j = 0; j < n; j++)
		{
			string name;
			string type;
			cin >> name >> type;
			auto k = m.find(type);
			if (k != m.end())
			{
				v[k->second - 1] += 1;
			}
			else
			{
				v.push_back(1);
				m.insert(make_pair(type, v.size()));
			}
		}
		int result = 1;
		for (int k = 0; k < v.size(); k++)
		{
			result = result * (v[k] + 1);
		}
		cout << result - 1 << '\n';
	}
	return 0;
}