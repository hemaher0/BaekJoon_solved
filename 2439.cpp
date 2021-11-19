#include<iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int pivot = N - i - 1;
		for (int j = 0; j<N; j++)
		{
			if (j < pivot)
			{
				cout << " ";
			}
			else
			{
				cout << "*";
			}
		}
		cout << endl;
	}
	return 0;
}