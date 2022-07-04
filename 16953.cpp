#include<iostream>
#include<queue>
using namespace std;
long long A, B;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> A >> B;
	queue<pair<long long, int>>q;
	q.push(make_pair(A, 1));
	while (!q.empty()) {
		auto f = q.front();
		q.pop();
		auto a = pair<long long, int>(f.first * 2, f.second + 1);
		auto b = pair<long long, int>(f.first * 10 + 1, f.second + 1);
		if (a.first < 1000000001) {
			if (a.first < B) {
				q.push(a);
			}
			else {
				if (a.first == B) {
					cout << a.second;
					break;
				}
			}
		}
		if (b.first < 1000000001) {
			if (b.first < B) {
				q.push(b);
			}
			else {
				if (b.first == B) {
					cout << b.second;
					break;
				}
			}
		}
		if (q.empty()) {
			cout << -1;
		}
	}
	return 0;
}