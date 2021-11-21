#include<iostream>
using namespace std;
int main()
{
	while (true)
	{
		int A;
		int B;
		cin >> A >> B;
		if (A == 0)
		{
			if (B == 0) break;
		}
		cout << A + B << endl;
	}
	return 0;
}