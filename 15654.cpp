#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<int> v;
int index[9];
void func(int level)
{
    if (level > M) {
        for (int i = 1; i < level; i++) {
            cout << v[index[i]] << " ";
        }
        cout << "\n";
    }
    else {
        for (int j = 1; j <= N; j++) {
            bool mode = true;
            for (int k = 1; k < level; k++) {
                if (index[k] == j) {
                    mode = false;
                    break;
                }    
            }
            if (mode) {
                index[level] = j;
                func(level + 1);
            }
        }
    }
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    v.push_back(0);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin() + 1, v.end());
    fill(index, index + 9, -1);
    func(1);
    return 0;
}