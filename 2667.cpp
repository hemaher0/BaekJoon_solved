#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
using namespace std;
int map[25][25];
int visited[25][25];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++)
        {
            map[i][j] = s[j] - '0';
        }
    }
    stack<pair<int, int>>stk;
    vector<pair<int, int>> ans;
    int count = 0;
    int house = 0;
    for (int j = 0; j < N; j++)
    {
        for (int k = 0; k < N; k++)
        {
            if (!visited[j][k])
            {
                visited[j][k] = 1;
                if (map[j][k])
                {
                    stk.push(make_pair(j, k));
                    house++;
                    count++;
                }
                while (!stk.empty())
                {
                    pair<int, int> f = stk.top();
                    stk.pop();
                    for (int l = 0; l < 4; l++)
                    {
                        int xx = f.first + dx[l];
                        int yy = f.second + dy[l];
                        if (xx >= 0 && xx < N && yy >= 0 && yy < N)
                        {
                            if (!visited[xx][yy])
                            {
                                if (map[xx][yy])
                                {
                                    count++;
                                    stk.push(make_pair(xx, yy));
                                }
                                visited[xx][yy] = 1;
                            }
                        }
                    }
                }
                if (count)
                {
                    ans.push_back(make_pair(count, house));
                    count = 0;
                }
            }            
        }
    }
    cout << ans[ans.size() - 1].second << "\n";
    sort(ans.begin(), ans.end());
    for (int a = 0; a < ans.size(); a++)
    {
        cout << ans[a].first << "\n";
    }
    return 0;
}