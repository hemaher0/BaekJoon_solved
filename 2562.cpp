#include<iostream>
using namespace std;
int main()
{
	int number[9];
	int pivot = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> number[i];
		if (number[i] > number[pivot])
		{
			pivot = i;
		}
	}
	cout << number[pivot] << endl << pivot+1;
	return 0;
}