#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N;
    M = 0;
    vector<pair<int, int>> meeting;
    for (int i = 0; i < N; i++)
    {
        int start, end;
        cin >> start >> end;
        meeting.push_back(make_pair(end, start));
    }
    sort(meeting.begin(), meeting.end());
    pair<int, int> f = meeting.front();
    int count = 1;
    for(int k = 1; k< N; k++)
    {
        if (f.first <= meeting[k].second)
        {
            f = meeting[k];
            count++;
        }
    }
    cout << count;
    return 0;
}