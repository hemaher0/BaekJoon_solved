#include<iostream>
using namespace std;
int N = 0;
int dq(int * paper[], int s, int e, int size, int c)
{
	int total = 0;
	if (size == 1)
	{
		if (paper[s][e] != c)
			return 0;
		else
			return 1;
	}
	else
	{
		for (int i = s; i < s + size; i++)
		{
			for (int j = e; j < e + size; j++)
			{
				if (paper[i][j] != c)
				{
					total = total + dq(paper, s, e, size / 2, c);
					total = total + dq(paper, s, e + size / 2, size / 2, c);
					total = total + dq(paper, s + size/2, e, size / 2, c);
					total = total + dq(paper, s + size/2, e + size /2, size / 2, c);
					return total;
				}
			}
		}
		if (total == 0)
			return 1;
	}
}
int main()
{	
	cin >> N;
	int** paper = new int* [N];
	for (int i = 0; i < N; i++)
	{
		paper[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			cin>> paper[i][j];
		}
	}
	cout << dq(paper, 0, 0, N, 0) << '\n' << dq(paper, 0, 0, N, 1);
	return 0;
}