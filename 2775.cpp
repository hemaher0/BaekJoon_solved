#include<iostream>
using namespace std;
int main()
{
	int T;
	cin >> T;
	for (int e = 0; e < T; e++)
	{
		int k;
		int n;
		cin >> k >> n;
		int** building = new int* [k];
		for (int i = 0; i <= k; i++)
		{
			building[i] = new int[n];
			for (int J = 0; J < n; J++)
			{
				if (i == 0)
				{
					building[0][J] = J+1;
				}
				else
				{
					int sum = 0;
					for (int K = 0; K <= J; K++)
					{
						sum = sum + building[i - 1][K];
					}
					building[i][J] = sum;
				}
			}
		}
		cout << building[k][n-1]<<endl;
	}
	return 0;
}
