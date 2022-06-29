#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    vector<tuple<int, int, int>> edible;    // ���� �� �ִ� ������� �Ÿ�, X��ǥ, Y��ǥ
    int room[20][20] = { 0, };  // �� ����
    int visited[20][20] = { 0, };   // 
    int result = 0, dist;
    int N;
    cin >> N;

    int sharkx, sharky, sharksize = 2, sharktum = 0;
    for (int i = 0; i < N; i++) {   // N*N �� ���� �Է�
        for (int j = 0; j < N; j++) {
            cin >> room[i][j];
            if (room[i][j] == 9) {  // ��� ��ġ
                sharkx = i; sharky = j; room[i][j] = 0;
            }
        }
    }
    while (1) {
        dist = 400;
        edible.clear();
        for (int i = 0; i < 20; ++i) { for (int j = 0; j < 20; ++j) { visited[i][j] = 0; } }
        queue<pair<int, int>> movable;
        movable.push(make_pair(sharkx, sharky));
        while (!movable.empty()) {  // �̵� ������ ĭ�� �� ���� �� ����
            int x = movable.front().first, y = movable.front().second;
            movable.pop();

            for (int i = 0; i < 4; ++i) {
                int x_, y_;
                if (i == 0) { x_ = x - 1; y_ = y; }
                else if (i == 1) { x_ = x + 1; y_ = y; }
                else if (i == 2) { x_ = x; y_ = y - 1; }
                else if (i == 3) { x_ = x; y_ = y + 1; }

                if ((x_ < 0) || (x_ >= N) || (y_ < 0) || (y_ >= N)) continue;
                if (visited[x_][y_] == 0) {
                    if (sharksize >= room[x_][y_]) {    // ũ�Ⱑ ���ų� ���� �����, �� ĭ���� �̵��� �� �ִ�
                        visited[x_][y_] = visited[x][y] + 1;
                        if ((sharksize > room[x_][y_]) && (room[x_][y_] != 0)) {    // ��ĭ �Ÿ���
                            if (dist >= visited[x_][y_]) {
                                dist = visited[x_][y_];
                                edible.push_back(make_tuple(dist, x_, y_));
                            }
                        }
                        movable.push(make_pair(x_, y_));  // �̵� �����ߴ� ��� ������ ��ġ ����
                    }
                }
            }
        }
        if (edible.empty()) break;  // �� ���� ����Ⱑ ���ٸ�

        sort(edible.begin(), edible.end());
        result += get<0>(edible[0]); // �̵��Ÿ� = �ð�
        room[get<1>(edible[0])][get<2>(edible[0])] = 0;   // ���� ����� �� ���� 0
        sharkx = get<1>(edible[0]);    // ���� ����� ������ �̵�
        sharky = get<2>(edible[0]);
        if (++sharktum == sharksize) { sharksize++; sharktum = 0; } // ��� ũ�� ����
    }
    cout << result;

    return 0;
}