#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> v;
	int* k = new int[N];
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
		k[i] = x;
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int j = 0; j < N; j++)
	{
		cout << lower_bound(v.begin(), v.end(), k[j]) - v.begin() << ' ';
	}
	return 0;
}