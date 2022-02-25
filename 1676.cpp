#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int get2(int);
int get5(int);
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	int sum2 = 0;
	int sum5 = 0;
	for (int i = 1; i <= N; i++)
	{
		sum2 = sum2 + get2(i);
		sum5 = sum5 + get5(i);
	}
	cout << min(sum2, sum5);
	return 0;
}
int get5(int num)
{
	int sum = 0;
	int div = num;
	while (div % 5 == 0)
	{
		sum++;
		div /= 5;
	}
	return sum;
}
int get2(int num)
{
	int sum = 0;
	int div = num;
	while (div % 2 == 0)
	{
		sum++;
		div /= 2;
	}
	return sum;
}