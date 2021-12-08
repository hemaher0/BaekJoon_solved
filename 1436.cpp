#include<iostream>
#include<vector>
using namespace std;
int check(vector<int>);
void add(vector<int>&);
int main()
{
	int N;
	cin >> N;
	int sum = 0;
	vector<int>v(1);
	while (1)
	{
		if (sum == N)
		{
			for (int i = v.size() -1; i >= 0; i--)
			{
				cout << v[i];
			}
			break;
		}
		else
		{
			add(v);
			sum = sum + check(v);
		}
	}
	return 0;
}
int check(vector<int>v)
{
	int level = 0;
	int n = 0;
	vector<int>::iterator i;
	for(i = v.begin();i!=v.end();i++)
	{
		if (*i == 6)
		{
			level += 1;
			if (level == 3)
			{
				n = 1;
				break;
			}
		}
		else
		{
			level = 0;
			n = 0;
		}
	}
	return n;
}
void add(vector<int> &v)
{
	int alpha = 1;
	int beta = 0;
	vector <int> tmp = v;
	vector <int> result;
	while(tmp.size()!=0)
	{	
		beta = tmp.front() + alpha;
		if (beta >= 10)
		{
			alpha = 1;
			beta = beta - 10;
		}
		else
		{
			alpha = 0;
		}
		tmp.erase(tmp.begin());
		result.insert(result.end(), beta);
	}
	if (alpha == 1)
	{
		result.insert(result.end(), alpha);
	}
	vector<int>::iterator i;
	v = result;
}