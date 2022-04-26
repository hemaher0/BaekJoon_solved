#include <iostream>
using namespace std;
int m1, one, zero;
void counter(int **paper, int st, int ed, int size) {
    int check = paper[ed][st];
    bool mode = false;
    for (int i = ed; i < ed + size; i++) {
        for (int j = st; j < st + size; j++) {
            if (paper[i][j] != check) {
                mode = true;
            }
        }
    }
    if (!mode) {
        if (check == 1) {
            one++;
        }
        else if (check == -1) {
            m1++;
        }
        else {
            zero++;
        }
    }
    else
    {
        counter(paper, st, ed, size / 3);
        counter(paper, st + size / 3, ed, size / 3);
        counter(paper, st + 2 * size / 3, ed, size / 3);
        counter(paper, st, ed + size / 3, size / 3);
        counter(paper, st + size / 3, ed + size / 3, size / 3);
        counter(paper, st + 2 * size / 3, ed + size / 3, size / 3);
        counter(paper, st, ed + 2 * size / 3, size / 3);
        counter(paper, st + size / 3, ed + 2 * size / 3, size / 3);
        counter(paper, st + 2 * size / 3, ed + 2 * size / 3, size / 3);
    }
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int** paper = new int* [N];
    for (int i = 0; i < N; i++) {
        paper[i] = new int[N];
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }
    counter(paper, 0, 0, N);
    cout << m1 << '\n' << zero << '\n' << one;
    return 0;
}