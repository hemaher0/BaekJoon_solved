#include<iostream>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int k;
		cin >> k;
		priority_queue<int> max;
		priority_queue<int, vector<int>, greater<int>> min;
		unordered_multimap<int, int>mx;
		unordered_multimap<int, int>mn;
		for (int i = 0; i < k; i++) {
			char c;
			int n;
			cin >> c >> n;
			if (c == 'I') {
				max.push(n);
				min.push(n);
			}
			else {
				int tp;
				if (n == 1) {
					if (!max.empty()) {
						tp = max.top();
						max.pop();
						mn.insert(make_pair(tp, i));
					}
				}
				else {
					if (!min.empty()) {
						tp = min.top();
						min.pop();
						mx.insert(make_pair(tp, i));
					}
				}
				while (!mn.empty()) {
					auto k = mn.find(min.top());
					if (k != mn.end()) {
						min.pop();
						mn.erase(k);
					}
					else break;
				}
				while (!mx.empty()) {
					auto k = mx.find(max.top());
					if (k != mx.end()) {
						max.pop();
						mx.erase(k);
					}
					else break;
				}
			}
		}
		if (min.empty() && max.empty()) {
			cout << "EMPTY" << "\n";
		}
		else {
			cout << max.top() << " " << min.top() << "\n";
		}
	}
	return 0;
}