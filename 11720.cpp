#include<iostream>
#include<string>
using namespace std;
int main()
{
	int N;
	string number;
	int total = 0;
	cin >> N;
	cin >> number;
	for (int i = 0; i < N; i++)
	{
		total = total + number.back() - '0';
		number.pop_back();
	}
	cout << total;
	return 0;
}