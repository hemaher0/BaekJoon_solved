#include<iostream>
using namespace std;
int N, M;
int graph[1025][1025];
int dpsq[1025][1025];
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		dpsq[i][0] = 0;
		for (int j = 1; j <= N; j++) {
			cin >> graph[i][j];
			dpsq[i][j] = dpsq[i - 1][j] + dpsq[i][j - 1] - dpsq[i - 1][j - 1] + graph[i][j];
		}
	}
	while (M--) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		long long p1 = dpsq[x2][y2];
		long long p2 = dpsq[x1 - 1][y2];
		long long p3 = dpsq[x2][y1 - 1];
		long long p4 = dpsq[x1 - 1][y1 - 1];
		cout << p1 - p2 - p3 + p4<<"\n";
	}
	return 0;
}