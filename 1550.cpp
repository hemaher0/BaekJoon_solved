#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int func(char);
int main()
{
	string num = {0,};
	int result = 0;
	cin >> num;
	for (int i = 0; i < num.length(); i++)
	{
		result = result + (func(num[num.length() - i - 1]))*pow(16,i);
	}
	cout << result<<"\n";
	return 0;
}
int func(char m)
{
	int n = 0;
	if(m>=48&&m<=57)
	{
		n = m - 48;
	}
	else if(m=='A')
	{
		n = 10;
	}
	else if (m == 'B')
	{
		n = 11;
	}
	else if (m == 'C')
	{
		n = 12;
	}
	else if (m == 'D')
	{
		n = 13;
	}
	else if (m == 'E')
	{
		n = 14;
	}
	else if (m == 'F')
	{
		n = 15;
	}
	return n;
}