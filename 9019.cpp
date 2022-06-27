#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<tuple>
using namespace std;
string A, B;
queue<tuple<int, string>> q;
string make4(string A)
{
	while (A.length() < 4) {

		A.insert(A.begin(), '0');
	}
	return A;
}
bool check(int visited[10000], string svisited[10000], int x, string y)
{
	if (!visited[x]) {
		visited[x] = true;
		svisited[x] = y;
		if (x == stoi(B)) {
			return true;
		}
		else {
			q.push(make_pair(x, y));
		}
	}
	return false;
}
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		q = queue<tuple<int, string>>();
		string svisited[10000] = {};
		int visited[10000] = {0,};
		int cur;
		string scur;
		cin >> A >> B;
		int nA = stoi(A);
		int nB = stoi(B);
		q.push(make_tuple(nA, ""));
		svisited[nA] = "";
		visited[nA] = 0;
		while (!q.empty()) {
			cur = get<0>(q.front());
			scur = get<1>(q.front());
			q.pop();
			int D = cur * 2 % 10000;
			int S = cur - 1;
			if (S < 0) S = 9999;
			int L = cur * 10 % 10000 + cur / 1000;
			int R = (cur / 10 + cur * 1000) % 10000;
			if (check(visited, svisited, D, scur + 'D')) break;
			if (check(visited, svisited, S, scur + 'S')) break;
			if (check(visited, svisited, L, scur + 'L')) break;
			if (check(visited, svisited, R, scur + 'R')) break;
		}
		cout << svisited[nB] << "\n";
	}
	return 0;
}
