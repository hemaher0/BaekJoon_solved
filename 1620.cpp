#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	string* li = new string[N + 1];
	unordered_map<string, int> pokeguide;
	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		pokeguide[s] = i;
		li[i] = s;
	}
	for (int j = 0; j < M; j++)
	{
		string name;
		cin >> name;
		int num = 0;
		int first = name[0] - '0';
		if (0 < first && 10 > first)
		{
			num = stoi(name);
			cout << li[num] << '\n';
		}
		else
		{
			auto po = pokeguide.begin();
			po = pokeguide.find(name);
			cout << po->second << '\n';
		}
	}
	return 0;
}
