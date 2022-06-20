#include <iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    unordered_map<string, string> pass;
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string site, password;
        cin >> site >> password;
        pass.insert(make_pair(site, password));
    }
    for (int j = 0; j < M; j++) {
        string site;
        cin >> site;
        auto i = pass.find(site);
        cout << i->second << '\n';
    }
    return 0;

}