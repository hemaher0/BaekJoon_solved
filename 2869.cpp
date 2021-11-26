#include<iostream>
using namespace std;
int main()
{
	int A, B, V;
	cin >> A >> B >> V;
	int tmp1 = (V- A)/ (A - B);
	int tmp2 = V%(A-B)/A+1;
	if ((V - A) % (A - B) != 0)
	{
		tmp1 += 1;
	}
	cout << tmp1 + tmp2;
	return 0;
}