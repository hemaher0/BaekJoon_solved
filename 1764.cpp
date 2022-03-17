#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
bool compare(string s1, string s2)
{
	int x = 0;    while (s1[x] == s2[x])
	{
		if (x < s1.length() - 1 && x < s2.length() - 1)
			x++;
		else
			break;
	}
	if (s1[x] == s2[x])
	{
		return s1.length() < s2.length();
	}
	else
	{
		return s1[x] < s2[x];
	}
}
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	unordered_map<string, string> neverseen;
	unordered_map<string, string> neverheard;
	vector<string> q;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		neverheard.insert(make_pair(s, s));
	}
	for (int j = 0; j < M; j++)
	{
		string s;
		cin >> s;
		neverseen.insert(make_pair(s, s));
	}
	auto k = neverheard.begin();
	for (k; k != neverheard.end(); k++)
	{
		auto l = neverseen.find(k->second);
		if (l != neverseen.end())
		{
			q.push_back(k->second);
		}
	}
	cout << q.size() << '\n';
	sort(q.begin(), q.end(), compare);
	for (auto i = q.begin(); i != q.end(); i++)
		cout << *i << '\n';
	return 0;
}