#include <iostream>
#include <vector>
using namespace std;

vector<string> arr[201];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int age;
		cin >> age;
		string name;
		cin >> name;
		arr[age].push_back(name);
	}

	for (int i = 1; i <= 200; i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << i << " " << arr[i][j] << "\n";
		}
	}
}