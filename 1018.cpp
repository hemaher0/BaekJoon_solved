#include<iostream>
#include<string>
#include<vector>
using namespace std;
int scoreboard(char [8][8]);
int main()
{
	int N;
	int M;
	cin >> N >> M;
	int ns = N + 1 - 8;
	int ms = M + 1 - 8;
	char **chessboard = new char* [N];
	for (int i = 0; i < N; i++)
	{
		chessboard[i] = new char[M];
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			chessboard[i][j] = s[j];
		}
	}
	int** score = new int* [ns];
	
	for (int j = 0; j < ns; j++)
	{	
		score[j] = new int[ms];
		for (int k = 0; k < ms; k++)
		{
			char currentboard[8][8];
			for (int i = 0; i < 8; i++)
			{
				for (int l = 0; l < 8; l++)
				{
					currentboard[i][l] = chessboard[j + i][k + l];
				}
			}
			score[j][k] = scoreboard(currentboard);
		}
	}
	int tmp = score[0][0];
	for (int k = 0; k < ns; k++)
	{
		for (int j = 0; j < ms; j++)
		{
			if (tmp > score[k][j])
			{
				tmp = score[k][j];
			}
		}
	}
	cout << tmp;
	return 0;
}
int scoreboard(char chessboard[8][8])
{
	char start = chessboard[0][0];
	char start1;
	if (start == 'B')
	{
		start1 = 'W';
	}
	else
	{
		start1 = 'B';
	}
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < 8; i ++ )
	{
		for (int j = 0; j < 8; j++)
		{
			if (i % 2 == 0)
			{
				if (j % 2 == 0)
				{
					if (chessboard[i][j] != start)
					{
						sum1 = sum1 + 1;
					}
					if (chessboard[i][j] != start1)
					{
						sum2 = sum2 + 1;
					}
				}
				else
				{
					if (chessboard[i][j] == start)
					{
						sum1 = sum1 + 1;
					}
					if (chessboard[i][j] == start1)
					{
						sum2 = sum2 + 1;
					}
				}
			}
			else
			{
				if (j % 2 == 0)
				{
					if (chessboard[i][j] == start)
					{
						sum1 = sum1 + 1;
					}
					if (chessboard[i][j] == start1)
					{
						sum2 = sum2 + 1;
					}
				}
				else
				{
					if (chessboard[i][j] != start)
					{
						sum1 = sum1 + 1;
					}
					if (chessboard[i][j] != start1)
					{
						sum2 = sum2 + 1;
					}
				}
			}
		}
	}
	return (sum1>=sum2?sum2:sum1);
}