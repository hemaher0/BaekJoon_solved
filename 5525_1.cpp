#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	int cnt = 0;
	int sum = 0;
	char *c = new char[M+1];
	cin >> c;
	for (int i = 0; i < M; i++){
		if (c[i] == 'I'){
			cnt = 0;
			while (i + 2 <= M - 1){
				if (c[i+1] == 'O' && c[i+2] =='I'){
					i = i + 2;
					cnt++;
				}
				else break;
			}
			if (cnt >= N) sum += cnt - N + 1;
		}
	}
	cout << sum;
	return 0;
}