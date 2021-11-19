#include<iostream>
using namespace std;
int main()
{
	int T;
	cin >> T;
	int* addend = new int[T];
	int* augend = new int[T];
	for (int i = 0; i < T; i++)
	{
		cin >> addend[i] >> augend[i];
	}
	for (int i = 0; i < T; i++)
	{
		cout<< addend[i] + augend[i]<<endl;
	}
	return 0;
}