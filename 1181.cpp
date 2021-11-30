#include<iostream>
#include<string>
#include<vector>
using namespace std;
void arrange(vector<string>*, vector<string>);
int compare(string, string );
int main()
{
	int N;
	cin >> N;
	vector<string> arrangement;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		arrangement.push_back(s);
	}
	vector<string>result;
	arrange(&result, arrangement);
	vector<string>::iterator j;
	for (j = result.begin(); j!=result.end(); j++)
	{	
		cout<<*j<<endl;
	}
	return 0;
}
int compare(string A, string B)
{
	if (A.length() > B.length())
	{
		return -1;
	}
	else if (A.length() <B.length())
	{
		return 1;
	}
	else
	{
		for (int i = 0; i < A.length(); i++)
		{
			if (A[i] > B[i])
			{
				return -1;
			}
			else if (A[i] < B[i])
			{
				return 1;
			}
			else
			{
				if (i == A.length() - 1)
				{
					return 0;
				}
			}
		}
	}
}
void arrange(vector<string> *result, vector<string> A)
{
	string pivot = A.front();
	vector<string> tempsmall;
	vector<string> tempbig;
	vector<string>::iterator i;
	for (i = A.begin(); i != A.end(); i++)
	{	
		{
			if (compare(pivot, *i) == -1)
			{
				tempsmall.push_back(*i);
			}
			else if (compare(pivot, *i) == 1)
			{
				tempbig.push_back(*i);
			}
		}
	}
	if (tempsmall.size() > 0)
	{
		vector<string> resultL;
		arrange(&resultL, tempsmall);
		vector<string>::iterator is;
		for (is = resultL.begin(); is != resultL.end(); is++)
		{
			result->push_back(*is);
		}
	}
	result->push_back(pivot);
	if (tempbig.size() > 0)
	{
		vector<string> resultR;
		arrange(&resultR, tempbig);
		vector<string>::iterator ib;
		for (ib = resultR.begin(); ib != resultR.end(); ib++)
		{
			result->push_back(*ib);
		}
	}
}