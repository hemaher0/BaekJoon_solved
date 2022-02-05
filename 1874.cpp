#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	vector<int> s;
	stack<int>test;
	vector<char>print;
	int N;
	cin >> N;
	for (int j = 0; j < N; j++)
	{
		int k;
		cin >> k;
		s.push_back(k);
	}
	vector<int>::iterator i;
	int pivot = 1;
	bool result = true;
	for(i = s.begin(); i!=s.end(); i++)
	{
		if (pivot <= *i)
		{
			for (int j = pivot; j <= *i; j++)
			{
				test.push(j);
				print.push_back('+');
				pivot++;
				
			}
		}
		if (pivot >= *i)
		{
			if (test.top()>=*i)
			{
				test.pop();
				print.push_back('-');
			}
			else
			{
				result = false;
			}
		}
	}
	if (result)
	{
		vector<char>::iterator j;

		for (j = print.begin(); j != print.end(); j++)
		{
			cout << *j << '\n';
		}
	}
	else
	{
		cout << "NO";
	}
	return 0;
}
