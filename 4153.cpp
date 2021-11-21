#include<iostream>
using namespace std;
string pita(int long, int long, int long);
int main()
{
	int long A, B, C;
	while (true)
	{
		cin >> A >> B >> C;
		if (A == B && B == C && C == 0)
		{
			break;
		}
		int big;
		int small[2];
		if (A > B)
		{
			if (A > C)
			{
				big = A;
				small[0] = C;
			}
			else
			{
				big = C;
				small[0] = A;
			}
			small[1] = B;
		}
		else
		{
			if (B > C)
			{
				big = B;
				small[0] = C;
			}
			else
			{
				big = C;
				small[0] = B;
			}
			small[1] = A;
		}
		cout << pita(big, small[0], small[1])<<endl;
	}
}
string pita(int long big, int long x, int long y)
{
	string s;
	if (big * big == x * x + y * y)
	{
		s = "right";
	}
	else
	{
		s = "wrong";
	}
	return s;
}