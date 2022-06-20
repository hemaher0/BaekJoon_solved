#include<iostream>
#include<vector>
using namespace std;
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector<int> v;
	v.push_back(1);
	while (!v.empty()) {
		for (int x = v.back() + 1; x <= N + 1; x++) {
			if (v.size() == M) {
				for (int k = 0; k < M; k++) {
					cout << v[k] << " ";
				}
				cout << "\n";
				v.pop_back();
			}
			if (x <= N) {
				v.push_back(x);
			}
			else {
				for (int b = v.size(); b > 0; b--) {
					if (v.back() == N - M + b) {
						v.pop_back();
					}
					else {
						v[v.size() - 1] += 1;
						break;
					}

				}
			}
		}
	}
	return 0;
}