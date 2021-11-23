#include<iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int level = 1;
	int max = 1;
	int min = 1;
	int count = 1;
	while (N > max)
	{
		if (N != 1)
		{
			min = max;
			max = max + 6 * level;
			level += 1;
		}
		else
		{
			break;
		}
	}
	if (N <= max)
	{
		count = level;
	}
	cout << count;
	return 0;
}