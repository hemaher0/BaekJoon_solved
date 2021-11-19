#include<iostream>
using namespace std;
int main()
{
	int N;
	int Max = 0;
	int Min = 0;
	cin >> N;
	int* number = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> number[i];
		if (number[Max] > number[i])
		{
			Max = i;
		}
		if (number[Min] < number[i])
		{
			Min = i;
		}
	}
	cout << number[Max] << " " << number[Min];
	return 0;
}