#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool VPS(string);
int main()
{
	int T;
	scanf_s("%d", &T);
	//scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		string s;
		cin >> s;
		bool bs = VPS(s);
		if (bs)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
bool VPS(string s)
{
	int ssize = s.length();
	vector<char>stack;
	stack.reserve(ssize);
	for (int i = 0; i < ssize; i++)
	{
		if (s[i] == '(')
		{
			stack.push_back('(');
		}
		else
		{
			if (stack.size() == 0)
			{
				return false;
			}
			else
			{
				stack.pop_back();
			}
		}
	}
	if (stack.size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}