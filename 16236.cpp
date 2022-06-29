#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#include<queue>
using namespace std;
int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { -1, 0, 0, 1 };
int space[20][20];
int N;
tuple<int,int,int> find(pair<int, int> babysk, int babysize)
{
    queue<pair<pair<int, int>, int >> q;
    vector<tuple<int, int, int>>v;
    int visited[20][20] = { 0, };
    q.push(make_pair(babysk, 0));
    visited[babysk.first][babysk.second] = true;
    while (!q.empty()) {
        pair<int, int> f = q.front().first;
        int count = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int fx = f.second + dx[i];
            int fy = f.first + dy[i];
            if (fx >= 0 && fx < N) {
                if (fy >= 0 && fy < N) {
                    if (!visited[fy][fx]) {
                        visited[fy][fx] = true;
                        int sp = space[fy][fx];
                        if (sp <= babysize) {
                            if (sp) {
                                if (sp < babysize) {
                                    v.push_back(make_tuple(count + 1, fy, fx));
                                }
                                else {
                                    q.push(make_pair(make_pair(fy, fx),count + 1));
                                }
                            }
                            else {
                                q.push(make_pair(make_pair(fy, fx),count + 1));
                            }
                        }
                    }
                }
            }
        }
    }
    if (!v.empty()) {
        sort(v.begin(), v.end());
        return v.front();
    }
    else {
        return make_tuple(0,babysk.first,babysk.second);
    }
    
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int sec = 0;
    cin >> N;
    pair<int, int> babysk;
    int babysize = 2;
    int full = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> space[i][j];
            if (space[i][j] == 9) {
                babysk = make_pair(i, j);
                space[i][j] = 0;
            }
        }
    }
    int size;
    for (size = 1; size < babysize; size++) {
        tuple<int,int,int> p = find(babysk, babysize);
        pair<int, int> pl = make_pair(get<1>(p), get<2>(p));
        if (pl != babysk) {
            full++;
            sec += get<0>(p);
            space[pl.first][pl.second] = 0;
            if (full == babysize) {
                babysize++;
                full = 0;
            }
            babysk = pl;
            size-=1;
        }
        else {
            break;
        }
    }
    cout << sec;
    return 0;
}