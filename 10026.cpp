#include<iostream>
#include<string>
#include<queue>
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N;
using namespace std;
int counter(vector<char> section[100], bool mode, bool visited[][100])
{
	queue<pair<int, int>> q;
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			pair<int, int> x = pair<int, int>(i, j);
			if (!visited[i][j]) {
				q.push(x);
				visited[i][j] = true;
				result++;
			}
			while (!q.empty()) {
				x = q.front();
				q.pop();
				char pivot = section[x.first][x.second];
				for (int k = 0; k < 4; k++) {
					int xx = x.first + dx[k];
					int yy = x.second + dy[k];
					if (xx >= 0 && xx < N) {
						if (yy >= 0 && yy < N) {
							if (!visited[xx][yy]) {
								if (pivot == section[xx][yy]) {
									visited[xx][yy] = true;
									q.push(pair<int, int>(xx, yy));
								}
								else {
									if (!mode) {
										char p = section[xx][yy];
										if (pivot != 'B' && p != 'B') {
											visited[xx][yy] = true;
											q.push(pair<int, int>(xx, yy));
										}
									}
								}
							}
						}
					}

				}
			}
		}
	}
	return result;
}
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	vector<char> section[100];
	bool visited1[100][100];
	bool visited2[100][100];
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			section[i].push_back(s[j]);
			visited1[i][j] = false;
			visited2[i][j] = false;
		}
	}
	int normal{ 0 }, abnormal{ 0 };
	normal = counter(section, true, visited1);
	abnormal = counter(section, false, visited2);
	cout << normal << " " << abnormal;
	return 0;
}