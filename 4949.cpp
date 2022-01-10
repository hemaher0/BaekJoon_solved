#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	while (getline(cin,s))
	{
		if (s[0] == '.' and s.size()==1)
		{
			break;
		}
		stack<char> brackets;
		bool result = true;
		for (int i = 0; i < s.size() ; i++)
		{
			if (s[i] == '.')
			{
				if (not brackets.empty())
				{
					result = false;
				}
				break;
			}
			else
			{
				if (s[i] == '(')
				{
					brackets.push('(');
				}
				else if (s[i] == ')')
				{
					if (brackets.empty())
					{
						result = false;
						break;
					}
					else
					{
						if (brackets.top() != '(')
						{
							result = false;
							break;
						}
						else
						{
							brackets.pop();
						}
					}
				}
				else if (s[i] == '[')
				{
					brackets.push('[');
				}
				else if (s[i] == ']')
				{
					if (brackets.empty())
					{
						result = false;
						break;
					}
					else
					{
						if (brackets.top() != '[')
						{
							result = false;
							break;
						}
						else
						{
							brackets.pop();
						}
					}
				}
			}
		}
		if (result)
		{
			cout << "yes" << '\n';
		}
		else
		{
			cout << "no" << '\n';
		}
	}
	return 0;
}