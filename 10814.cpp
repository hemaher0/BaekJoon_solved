#include<iostream>
#include<string>
using namespace std;
class people
{
public:
	int age = 0;
	string name = "";
};
void sub(people[], people[], int);
int main()
{
	int N;
	scanf("%d", &N);
	people* plist = new people[N];
	people* resultlist = new people[N];
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &(plist[i].age));
		cin >> plist[i].name;
	}
	sub(resultlist, plist, N);
	for (int j = 0; j < N; j++)
	{
		printf("%d ", resultlist[j].age);
		cout << resultlist[j].name << '\n';
	}
	return 0;
}
void sub(people resultlist[], people prelist[], int size)
{
	int Lsize = size / 2;
	int Rsize = size - Lsize;
	if (size == 1)
	{
		resultlist[0] = prelist[0];
	}
	else
	{
		people* listL = new people[Lsize];
		people* listR = new people[Rsize];
		people* resultlistL = new people[Lsize];
		people* resultlistR = new people[Rsize];
		int tmpL = 0;
		int tmpR = 0;
		int tmpC = 0;
		for (int i = 0; i < size; i++)
		{
			if (i < Lsize)
			{
				listL[i] = prelist[i];
			}
			else
			{
				listR[i - Lsize] = prelist[i];
			}
		}
		if (Lsize != 0)
		{
			sub(resultlistL, listL, Lsize);
		}
		if (Rsize != 0)
		{
			sub(resultlistR, listR, Rsize);
		}
		while (tmpL != Lsize || tmpR != Rsize)
		{
			if (tmpL == Lsize)
			{
				while (tmpR != Rsize)
				{
					resultlist[tmpC] = resultlistR[tmpR];
					tmpC++;
					tmpR++;
				}
				break;
			}
			if (tmpR == Rsize)
			{
				while (tmpL != Lsize)
				{
					resultlist[tmpC] = resultlistL[tmpL];
					tmpC++;
					tmpL++;
				}
				break;
			}
			if (resultlistL[tmpL].age <= resultlistR[tmpR].age)
			{
				resultlist[tmpC] = resultlistL[tmpL];
				tmpL++;
				tmpC++;
			}
			else
			{
				resultlist[tmpC] = resultlistR[tmpR];
				tmpR++;
				tmpC++;
			}
		}
	}
}