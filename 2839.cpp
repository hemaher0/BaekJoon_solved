#include<iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int tmp = N;
	int count = 0;
	while (1)
	{
		if (tmp >= 3)
		{
			if (tmp % 5 == 0)
			{
				count += tmp / 5;
				tmp = 0;
			}
			else
			{
				tmp -= 3;
				count += 1;
			}
		}
		else
		{
			if (tmp == 0)
			{
				break;
			}
			else
			{
				count = -1;
				break;
			}
		}
	}
	cout << count;
	return 0;
}

