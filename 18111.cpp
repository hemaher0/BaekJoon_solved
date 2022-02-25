#include<iostream>
#include<queue>
using namespace std;
int possible(int**, int, int , int , int );
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, M, B;
	cin >> N >> M >> B;
	int** field = new int *[N];
	int topfloor = 0;
	int bottomfloor = 0;
	for (int i = 0; i < N; i++)
	{
		field[i] = new int[M];
		for (int j = 0; j < M; j++)
		{
			cin >> field[i][j];
			if (i == j && j == 0)
			{
				topfloor = field[i][j];
				bottomfloor = field[i][j];
			}
			else
			{
				if (topfloor < field[i][j])
					topfloor = field[i][j];
				if (bottomfloor > field[i][j])
					bottomfloor = field[i][j];
			}
		}
	}
	queue<int>resulttime;
	queue<int>resultheight;
	int floor;
	for (floor = topfloor; floor >= bottomfloor; floor--)
	{
		int time = possible(field, N, M, B, floor);
		if (time != -1)
		{
			if (resulttime.empty())
			{
				resulttime.push(time);
				resultheight.push(floor);
			}
			else
			{
				if (time < resulttime.front())
				{
					resulttime.pop();
					resultheight.pop();
					resulttime.push(time);
					resultheight.push(floor);
				}
			}
		}
	}
	cout << resulttime.front() <<' '<< resultheight.front();
	return 0;
}
int possible(int** field, int N, int M, int B, int floor)
{
	int Block = B;
	int time = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (field[i][j] < floor)
			{
				B = B - floor + field[i][j];
				time = time + (floor - field[i][j]);
			}
			else if (field[i][j] > floor)
			{
				B = B + field[i][j] - floor;
				time = time + (field[i][j] - floor) * 2;
			}
		}
	}
	if (B < 0 || time < 0)
		return -1;
	return time;
}
