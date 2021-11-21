#include<iostream>
using namespace std;
int main()
{
	int A[10] = {0};
	int count[42] = {0};
	int cnt = 0;
	for (int i = 0; i < 10; i++)
	{
		cin >> (A[i]);
		A[i] = A[i] % 42;
		count[A[i]] = count[A[i]] + 1;
	}
	for (int j = 0; j < 42; j++)
	{
		if (count[j] > 0)
		{
			cnt += 1;
		}
	}
	cout << cnt;
	return 0;
}