#include <iostream>
#include<queue>
using namespace std;
int** graph;
int* visited;
queue<int> v;
void dfs(int N)
{
    int x = v.front();
    v.pop();
    cout << x << ' ';
    for (int i = 1; i <= N; i++)
    {
        if (graph[x][i])
        {
            if (!visited[i])
            {
                visited[i] = 1;
                v.push(i);
                dfs(N);
            }
        }
    }
}
void bfs(int N)
{
    int x = v.front();
    cout << x << ' ';
    v.pop();
    for (int i = 1; i <= N; i++)
    {
        if (graph[x][i])
        {
            if (!visited[i])
            {
                visited[i] = 1;
                v.push(i);
            }
        }
    }
    if (!v.empty())
        bfs(N);
}
int main()
{
    int N, M, V;
    cin >> N >> M >> V;
    graph = new int * [N + 1];
    visited = new int [N + 1];
    for (int i = 1; i <= N; i++)
    {
        graph[i] = new int[N + 1];
        fill(graph[i], graph[i] + N + 1, 0);
    }
    
    while (M--)
    {
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    v.push(V);
    fill(visited, visited + N + 1, 0);
    visited[V] = 1;
    dfs(N);
    cout << '\n';
    v.push(V);
    fill(visited, visited + N + 1, 0);
    visited[V] = 1;
    bfs(N);
    return 0;
}