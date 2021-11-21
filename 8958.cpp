#include<iostream>
using namespace std;
int main()
{
	int T;
	cin >> T;
	string* OX = new string[T];
	int* count = new int[T];
	for (int i = 0; i < T; i++)
	{
		cin >> OX[i];
		int tmp = 0;
		int total = 0;
		for (int j = 0; j < OX[i].length(); j++)
		{	
			if (OX[i][j] == 'O')
			{
				tmp += 1;
				total = total + tmp;
			}
			else
			{
				tmp = 0;
			}
		}
		count[i] = total;
	}
	for (int j = 0; j < T; j++)
	{
		cout << count[j]<<endl;
	}
	return 0;
}