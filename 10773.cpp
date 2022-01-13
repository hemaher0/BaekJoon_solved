#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int K;
	cin >> K;
	stack<int> stk;
	int sum = 0;
	for (int i = 0; i < K; i++)
	{
		int a;
		cin >> a;
		if (a == 0)
		{
			stk.pop();
		}
		else
		{
			stk.push(a);
		}
	}
	while(!stk.empty())
	{
		sum = sum + stk.top();
		stk.pop();
	}
	cout << sum;
	return 0;
}