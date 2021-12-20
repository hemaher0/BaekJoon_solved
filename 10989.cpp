#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string tmp;
	cin>> tmp;
	vector<int> N(2,0);
	if (tmp.size() > 5)
	{
		N[0] = stoi(tmp.substr(0, tmp.size() - 5));
		N[1] = stoi(tmp.substr(tmp.size() - 5));
	}
	else
	{
		N[1] = stoi(tmp);
	}
	int vlist[10000] = { 0 };
	int number;
	for (int i = N[0]; i >=0; i--)
	{
		if (i == 0)
		{
			for (int j = 0; j < N[1]; j++)
			{
				scanf_s("%d", &number);
				//scanf("%d", &number);
				vlist[number - 1] = vlist[number - 1] + 1;
			}
		}
		else
		{
			for (int j = 0; j < 100000; j++)
			{
				scanf_s("%d", &number);
				//scanf("%d", &number);
				vlist[number - 1] = vlist[number - 1] + 1;
			}
		}
	}
	for (int j = 0; j < 10000; j++)
	{
		for (int k = 0; k < vlist[j]; k++)
		{
			printf("%d\n", j + 1);
		}
	}
	return 0;
}