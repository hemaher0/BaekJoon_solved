#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int N, M;
int button[10] = { 0 };
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	int result = 0;
	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		button[x] = 1;
	}
	if (N - 100 >= 0) result = N - 100;
	else result = 100 - N;
	string s;
	bool mode;
	int channel = 100;
	int dis = result;
	int d = 100;
	for (int i = 0; i < 999901; i++) {
		int k = i - N;
		if (k < 0) k = -k;
		s = to_string(i);
		mode = true;
		if (dis <= k) continue;
		for (int j = 0; j < s.length(); j++) {
			if (button[s[j] - '0']) {
				mode = false;
				break;
			}
		}
		if (!mode) continue;
		dis = k;
		d = i;
	}
	string tmp = to_string(d);
	int x = d - N;
	int count = tmp.length();
	cout << min(result, count + dis);
	return 0;
}