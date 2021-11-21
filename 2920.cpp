#include<iostream>
using namespace std;
int main()
{
	int scale[8];
	int count = 0;
	int end = 0;
	for (int i = 0; i < 8; i++)
	{
		cin >> scale[i];
	}
	if (scale[0] == 1)
	{
		count = 1;
		end = 8;
	}
	else if(scale[0]==8)
	{
		count = 8;
		end = 1;
	}
	else
	{
		count = 0;
	}
	if (count != 0)
	{
		for (int j = 0; j < 7; j++)
		{
			if (scale[j] == scale[j + 1] - 1)
			{
				count += 1;
			}
			else if (scale[j] == scale[j + 1] + 1)
			{
				count -= 1;
			}
			else
			{
				break;
			}
		}
		if (end == count && count == 1)
		{
			cout << "descending";
		}
		else if (end == count && count == 8)
		{
			cout << "ascending";
		}
		else
		{
			cout << "mixed";
		}
	}
	else
	{
		cout << "mixed";
	}
	return 0;
}