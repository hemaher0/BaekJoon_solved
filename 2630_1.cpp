#include<iostream>
using namespace std;
int N = 0;
int black = 0;
int white = 0;
int dq(int* paper[], int s, int e, int size)
{
	int c = paper[s][e];
	if (size == 1)
	{
		if (paper[s][e])
			black++;
		else
			white++;
		return 0;
	}
	else
	{
		for (int i = s; i < s + size; i++)
		{
			for (int j = e; j < e + size; j++)
			{
				if (paper[i][j] != c)
				{
					dq(paper, s, e, size / 2);
					dq(paper, s, e + size / 2, size / 2);
					dq(paper, s + size / 2, e, size / 2);
					dq(paper, s + size / 2, e + size / 2, size / 2);
					return 0;
				}
			}
		}
		if (c)
			black++;
		else
			white++;
		return 0;
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
			cin >> paper[i][j];
		}
	}
	dq(paper, 0, 0, N);
	cout <<  white<<'\n'<<black;
	return 0;
}