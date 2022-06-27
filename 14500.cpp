#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
int paper[500][500];
int result[500][500];
bool visited[500][500];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<pair<int, int>> arr;
void tat()
{
	if (arr.size()<4) {		
        for (int i = 0; i < 4; i++) {
			int xx = arr.back().second + dx[i];
			int yy = arr.back().first + dy[i];
			if (xx >= 0 && xx < M) {
				if (yy >= 0 && yy < N) {
					if (!visited[yy][xx]) {
						visited[yy][xx] = true;
						arr.push_back(make_pair(yy, xx));
            tat();
            visited[yy][xx] = false;
            arr.pop_back();
					}
				}
			}
		}
	}
  else{
	  int sum = 0;
	  for (int i = 0; i < 4; i++) {
		  sum+=paper[arr[i].first][arr[i].second];
  	}
    if(sum>result[arr[0].first][arr[0].second]){
  	result[arr[0].first][arr[0].second] = sum;
      }
  }
}
int extra(int y, int x) {
	int ex[5] = {0, 1, -1, 0, 0};
	int ey[5] = {0, 0, 0, 1, -1};
	int tmp = 0;
	for (int i = 1; i <= 4; i++) {
		int sum = 0;
		for (int j = 0; j <= 4; j++) {
			if (i != j) {
				int xx = x + ex[j];
				int yy = y + ey[j];
				if (xx >= 0 && xx < M) {
					if (yy >= 0 && yy < N) {
						sum += paper[yy][xx];
					}
				}
			}
		}
		if (tmp < sum) {
			tmp = sum;
		}
	}
	return tmp;
}
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int MAX = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> paper[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr.push_back(make_pair(i, j));
			visited[i][j] = true;
			tat();
      arr.pop_back();
      visited[i][j] = false;
			if (result[i][j] > MAX) {
				MAX = result[i][j];
			}
			MAX = max(extra(i, j), MAX);
		}
	}
	cout << MAX;
	return 0;
}