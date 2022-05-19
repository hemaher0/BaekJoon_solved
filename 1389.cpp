#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int N;
vector<int> v[101];
int bfs(int x)
{
    queue<int> q;
    vector<int>visited(N + 1, 0);
    vector<int>distance(N + 1, 100000);
    distance[x] = 0;
    int count = 1;
    visited[x] = 1;
    q.push(x);
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        
        for (int j = 0; j < v[k].size(); j++)
        {
            if (!visited[v[k][j]])
            {
                q.push(v[k][j]);
                visited[v[k][j]] = 1;
                if (distance[k] + 1 < distance[v[k][j]])
                {
                    distance[v[k][j]] = distance[k] + 1;
                }
            }
        }
    }
    int sum = 0;
    for (int k = 1; k <= N; k++)
    {
        sum = sum + distance[k];
    }
    return sum;
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int M, result, min;
    result = 100000;
    cin >> N >> M;
    while (M--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    min = 1;
    result = bfs(1);
    for (int j = 2; j <= N; j++)
    {
        if (bfs(j) < result)
        {
            result = bfs(j);
            min = j;
        }
    }
    cout << min;
    return 0;
}