#include<iostream>
#include<algorithm>
using namespace std;
int N, M;
int v[9];
int res[9];
void btrk(int level) {
	if (level <= M) {
		for (int i = res[level - 1]; i < N; i++) {
			res[level] = i;
			btrk(level + 1);
		}
	}
	else {
		for (int i = 1; i <= M; i++) {
			cout << v[res[i]] << " ";
		}
		cout << "\n";
	}
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v, v + N);
	res[0] = 0;
	btrk(1);
	return 0;
}