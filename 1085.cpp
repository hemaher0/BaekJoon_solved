#include<iostream>
using namespace std;
int main()
{
	int x, y, w, h;
	int lr;
	int ud;
	cin >> x >> y >> w >> h;
	if (x > w / 2)
	{
		lr = w - x;
	}
	else
	{
		lr = x;
	}
	if (y > h / 2)
	{
		ud = h - y;
	}
	else
	{
		ud = y;
	}
	cout << (lr > ud ? ud : lr);
	return 0;
}