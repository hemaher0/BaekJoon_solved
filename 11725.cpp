#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>v;
bool visited[100001] = { 0, };
int ans[100001];
int map[100001];
vector<int> stk;
void dfs(int i ) {
    stk.push_back(i);
    visited[i] = true;
    int l = stk.back();
    int ml = map[l];
    for (int j = 0; j < v[ml].size(); j++) {
        if (!visited[v[ml][j]]) {
            visited[v[ml][j]] = true;
            ans[v[ml][j]] = l;
            stk.push_back(v[ml][j]);
            dfs(v[ml][j]);
        }
    }
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    v.push_back(vector<int>(1, 0));
    for (int i = 2; i <= N; i++) {
        int x, y;
        cin >> x >> y;
        if (map[x]) {
            v[map[x]].push_back(y);
        }
        else {
            map[x] = v.size();
            v.push_back(vector<int>(1,y));
        }
        if (map[y]) {
            v[map[y]].push_back(x);
        }
        else {
            map[y] = v.size();
            v.push_back(vector<int>(1,x));
        }
    }
    dfs(1);
    for (int i = 2; i <= N; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}