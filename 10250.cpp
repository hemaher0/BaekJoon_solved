#include<iostream>
#include<string>
using namespace std;
int main()
{
	int T;
	int H;
	int W;
	int N;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		string roomnumber = "000";
		cin >> H >> W >> N;
		for (int j = 1; j <= W; j++)
		{
			for (int k = 1; k <= H; k++)
			{
				if (N == 1)
				{
					H = k;
					W = j;
					break;
				}
				N = N - 1;
			}
		}
		roomnumber[0] = H%10 + '0';
		roomnumber[2] = W%10 + '0';
		if(W>=10)
		{
			roomnumber[1] = W / 10 + '0';
		}
		if (H >= 10)
		{
			roomnumber.insert(0, to_string(H / 10));
		}
		cout << roomnumber << endl;
	}
	return 0;
}