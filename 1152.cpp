#include<iostream>
#include<string>
using namespace std;
int main()
{
	int countspace = 0;
	int emptyspace = 0;
	int whitespace = 0;
	int character = 0;
	int temp = 0;
	string cur;
	getline(cin, cur, '\n');
	string tmp;
	tmp = cur;
	while (cur.length() != 0)
	{
		if (cur.back() == ' ')
		{
			whitespace = 1;
			if (character == 1)
			{
				emptyspace += 1;
			}
			character = 0;
			
		}
		else 
		{
			character = 1;
			if (whitespace == 1)
			{
				countspace += 1;
			}
			whitespace = 0;
		}
		cur.pop_back();
	}
	if (emptyspace != 0 && countspace != 0 || character == 1 || whitespace == 1)
	{
		if (not(whitespace == 1 && tmp.length() == 1))
		{
			if (not(tmp.front()==tmp.back()&&tmp.back()==' '))
			{
				temp = 1;
			}
		}
	}
	if (countspace==emptyspace)
	{
		cout << countspace+temp;
	}
	else
	{
		cout << (countspace > emptyspace ? emptyspace:countspace)+temp;
	}
	return 0;
}