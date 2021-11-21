#include<iostream>
using namespace std;
int main()
{
	int A;
	int B;
	cin >> A >> B;
	for (int i = 0; i < 3; i++)
	{
		int A1 = A/100;
		int A2 = (A/10)%10;
		int A3 = A%10;
		int B1 = B / 100;
		int B2 = (B / 10) % 10;
		int B3 = B % 10;
		A = A3 * 100 + A2 * 10 + A1;
		B = B3 * 100 + B2 * 10 + B1;
	}
	cout << (A > B ? A : B);
	return 0;
}