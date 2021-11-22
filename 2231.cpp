#include<iostream>
#include<string>
using namespace std;
int check(int);
int main()
{
	int N;
	cin >> N;
	int pivot = N;
	for (int i = N; i > 0; i--)
	{
		if (check(i) == N)
		{
			pivot = i;
		}
	}
	if (pivot != N)
	{
		cout << pivot;
	}
	else
	{
		cout << 0;
	}
	return 0;
}
int check(int S)
{
	string N = to_string(S);
	int B;
	B = stoi(N);
	for (int i = 0; i < N.length(); i++)
	{
		B = B + N[i] - '0';
	}
	return B;
}