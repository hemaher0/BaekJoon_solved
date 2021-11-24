#include<iostream>
using namespace std;
int main()
{
	int N;
	int M;
	int count = 0;
	int pick1;
	int pick2 = 2;
	int pick3 = 3;
	int pivot = 0;
	cin >> N >> M;
	int* carddeck = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> carddeck[i];
	}
	for (pick1 = 1; pick1 <= N - 2; pick1++)
	{
		for (pick2 = pick1+1; pick2 <= N - 1; pick2++)
		{
			for (pick3 = pick2 + 1; pick3 <= N; pick3++)
			{
				if (carddeck[pick1] + carddeck[pick2] + carddeck[pick3] >= pivot)
				{
					if (carddeck[pick1] + carddeck[pick2] + carddeck[pick3] <= M)
					{
						pivot = carddeck[pick1] + carddeck[pick2] + carddeck[pick3];
					}
				}
			}
		}
	}
	cout << pivot;
	return 0;
}