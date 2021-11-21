#include<iostream>
using namespace std;
int main()
{
	int A;
	int B;
	int C;
	int long number;
	int count[10] = { 0 };
	int p;
	cin >> A >> B >> C;
	number = A * B * C;
	do
	{
		p = number % 10;
		number = number / 10;
		count[p] = count[p] + 1;
	} while (number > 0);
	for (int j = 0; j < 10; j++)
	{
		cout << count[j] << endl;
	}
	return 0;
}