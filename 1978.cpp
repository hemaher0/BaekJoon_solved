#include<iostream>
using namespace std;
bool prime_number(int);
int main()
{
	int N;
	scanf_s("%d", &N);
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		int num;
		scanf_s("%d",&num);
		if (prime_number(num))
		{
			count++;
		}
	}
	printf("%d", count);
	return 0;
}
bool prime_number(int a)
{
	bool result;
	int count = 0;
	for (int i = 1; i <= a; i++)
	{
		if (a % i ==0)
		{
			count++;
		}
	}
	if (count == 2)
	{
		result = true;
	}
	else
	{
		result = false;
	}
	return result;
}