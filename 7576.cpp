#include <iostream>
#include<vector>
#include <queue>
using namespace std;
int box[1001][1001];
bool visited[1001][1001];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int N, M, urtom, days;
queue<pair<int, int>> q;
queue<pair<int, int>> p;
void bfs()
{
    while (!q.empty()) {
        int xx = q.front().second;
        int yy = q.front().first;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int dxx = xx + dx[i];
            int dyy = yy + dy[i];
            if (dxx >= 1 && dxx <= M) {
                if (dyy >= 1 && dyy <= N) {
                    int val = box[dyy][dxx];
                    if (!visited[dyy][dxx]) {
                        visited[dyy][dxx] = true;
                        if (val == 1) {
                            q.push(make_pair(dyy, dxx));
                        }
                        else if (val == 0) {
                            p.push(make_pair(dyy, dxx));
                        }
                    }
                }
            }
        }
    }
    bool mode = false;
    if (p.size()) {
        mode = true;
    }
    while (!p.empty()) {
        int xx = p.front().second;
        int yy = p.front().first;
        p.pop();
        visited[yy][xx] = false;
        q.push(make_pair(yy, xx));
        box[yy][xx] = 1;
        urtom--;
    }
    if (mode) {
        days++;
        bfs();
    }
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            cin >> box[y][x];
            int k = box[y][x];
            if (!k) {
                urtom++;
            }
            else if (k == 1) {
                q.push(make_pair(y, x));
            }
        }
    }
    bfs();
    if (urtom != 0) {
        cout << -1;
    }
    else {
        cout << days;
    }
    return 0;
}