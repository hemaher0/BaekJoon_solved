#include<iostream>
using namespace std;
int main()
{
	string num;
	while (cin >> num)
	{
		if (num == "0")
		{
			break;
		}
		else
		{
			int size = num.length();
			int remainder = size % 2;
			int counter;
			for (counter = 0; counter < (size+remainder)/2; counter++)
			{
				if (num[counter] != num[num.length()-counter-1])
				{
					break;
				}
			}
			if (counter == (size + remainder) / 2)
			{
				cout << "yes"<<endl;
			}
			else
			{
				cout << "no" << endl;
			}
		}
	}
	return 0;
}