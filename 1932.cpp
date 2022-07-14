#include<iostream>
#include<algorithm>
int tri[501][501];
int tmp[501][501];
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> tri[i][j];
            if (i == 1 && j == 1) {
                tmp[1][1] = tri[1][1];
            }
            else {
                if (j == 1) {
                    tmp[i][j] = tmp[i - 1][j];
                }
                else if (i == j) {
                    tmp[i][j] = tmp[i - 1][j - 1];
                }
                else {
                    tmp[i][j] = max(tmp[i - 1][j - 1], tmp[i - 1][j]);
                }
                tmp[i][j] += tri[i][j];
            }

        }
    }
    int x = 0;
    for (int i = 1; i <= n; i++) {
        x = max(tmp[n][i], x);
    }
    cout << x;
}