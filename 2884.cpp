#include<iostream>
using namespace std;
int main()
{
	int H;
	int M;
	cin >> H >> M;
	if (M >= 45)
	{
		M = M - 45;
	}
	else
	{
		H = H - 1;
		if (H < 0)
		{
			H = 24 - 1;
		}
		M = (60 + M - 45)%60;
	}
	cout << H << " " << M;
	return 0;
}