#include <iostream>
#include<vector>
#include <queue>
#include<tuple>
using namespace std;
int box[101][101][101];
bool visited[101][101][101];
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int N, M, L, urtom, days;
queue<tuple<int, int, int>> q;
queue<tuple<int, int, int>> p;
void bfs()
{
    while (!q.empty()) {
        int xx = get<2>(q.front());
        int yy = get<1>(q.front());
        int zz = get<0>(q.front());
        q.pop();
        for (int i = 0; i < 6; i++) {
            int dxx = xx + dx[i];
            int dyy = yy + dy[i];
            int dzz = zz + dz[i];
            if (dxx >= 1 && dxx <= M) {
                if (dyy >= 1 && dyy <= N) {
                    if (dzz >= 1 && dzz <= L) {
                        int val = box[dzz][dyy][dxx];
                        if (!visited[dzz][dyy][dxx]) {
                            visited[dzz][dyy][dxx] = true;
                            if (val == 1) {
                                q.push(make_tuple(dzz, dyy, dxx));
                            }
                            else if (val == 0) {
                                p.push(make_tuple(dzz, dyy, dxx));
                            }
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
        int xx = get<2>(p.front());
        int yy = get<1>(p.front());
        int zz = get<0>(p.front());
        p.pop();
        visited[zz][yy][xx] = false;
        q.push(make_tuple(zz, yy, xx));
        box[zz][yy][xx] = 1;
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
    cin >> M >> N >> L;
    for (int z = 1; z <= L; z++) {
        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= M; x++) {
                cin >> box[z][y][x];
                int k = box[z][y][x];
                if (!k) {
                    urtom++;
                }
                else if (k == 1) {
                    q.push(make_tuple(z, y, x));
                }
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