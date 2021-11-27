#include<iostream>
using namespace std;
int coefficient(int, int);
int main()
{
	int N;
	int K;
	int count = 0;
	int start = 0;
	cin >> N >> K;
	count = coefficient(N, K);
	cout << count;
	return 0;
}
int coefficient(int N, int K)
{
	int count = 0;
	if (K > N / 2)
	{
		K = N - K;
	}
	if (K == 0)
	{
		count = 1;
	}
	else
	{
		count = coefficient(N-1,K-1) + coefficient(N-1,K);
	}
	return count;
}