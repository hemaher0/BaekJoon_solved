#include<iostream>
#include<string>
using namespace std;
int main()
{
	int T;
	cin >> T;
	int *R = new int[T];
	string *S = new string[T];
	for (int f = 0; f < T; f++)
	{
		cin >> R[f];
		cin >> S[f];
	}
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < S[i].length(); j++)
		{
			for (int k = 0; k < R[i]; k++)
			{
				cout << S[i][j];
			}
		}
		cout << endl;
	}
	return 0;
}