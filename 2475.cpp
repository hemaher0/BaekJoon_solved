#include<iostream>
using namespace std;
int main()
{
	int serial_number[6] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		cin >> serial_number[i];
		serial_number[5] = (serial_number[i] * serial_number[i] + serial_number[5])%10;
	}
	cout << serial_number[5];
}
