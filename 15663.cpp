#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<int> arr[9];
int res[9];
void btk(int level, int v[9]) {
	int visited[9];
	if (level <= M) {
		for (int i = 0; i<N; i++) {
			for (int i = 0; i < N; i++) {
				visited[i] = v[i];
			}
			if (visited[i]<arr[i].size()) {
				visited[i] += 1;
				res[level] = arr[i].back();
				btk(level + 1, visited);
			}
			
		}
	}
	else {
		for (int i = 1; i <= M; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
	}
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	int tmp[9];
	for (int i = 0; i < N; i++) {
		cin >> tmp[i];
	}
	sort(tmp, tmp + N);
	int rem = tmp[0];
	int arrsize = 0;
	arr[0].push_back(tmp[0]);
	for (int i = 1; i < N; i++) {
		if (tmp[i] != rem){
			++arrsize;
			rem = tmp[i];
		}
		arr[arrsize].push_back(tmp[i]);
	}
	N = arrsize + 1;
	int visited[9] = { 0, };
	res[0] = 0;
	btk(1, visited);
	return 0;
}