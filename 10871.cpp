#include<iostream>
using namespace std;
int main()
{
	int N, X;
	cin >> N>>X;
	int* A = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int j = 0; j < N; j++)
	{
		if (A[j] < X)
		{
			cout << A[j] << " ";
		}
	}
	return 0;
}