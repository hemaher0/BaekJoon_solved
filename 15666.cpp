#include<iostream>
#include<algorithm>
using namespace std;
int N, M;
int arr[9];
int res[9];
void btk(int level) {
	if (level <= M) {
		for (int i = res[level - 1]; i < N; i++) {
			res[level] = i;
			btk(level + 1);
		}
	}
	else {
		for (int i = 1; i < level; i++) {
			cout << arr[res[i]] << " ";
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
	arr[0] = tmp[0];
	for (int i = 1; i < N; i++) {
		if (tmp[i] != rem) {
			rem = tmp[i];
			arrsize++;
			arr[arrsize] = tmp[i];
		}
	}
	N = arrsize + 1;
	btk(1);
	return 0;
}