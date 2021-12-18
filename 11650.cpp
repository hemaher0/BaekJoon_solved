#include<iostream>
#include<utility>
using namespace std;
int compare(pair<int, int> , pair<int, int>);
void sub(pair<int, int>[], pair<int, int>[], int);
int main()
{
	int N;
	scanf("%d", &N);
	//scanf_s("%d", &N);
	pair<int, int>* dimen2 = new pair<int, int>[N];
	pair<int, int>* result = new pair<int, int>[N];
	for (int i = 0; i < N; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		//scanf_s("%d%d", &x, &y);
		dimen2[i].first = x;
		dimen2[i].second = y;
	}
	sub(result, dimen2, N);
	for (int j = 0; j < N; j++)
	{
		printf("%d %d\n",result[j].first,result[j].second);
	}
	return 0;
}
int compare(pair<int, int> A, pair<int,int>B)
{
	int direct;
	if (A.first > B.first)
	{
		direct = -1;
	}
	else if (A.first < B.first)
	{
		direct = 1;
	}
	else
	{
		if (A.second > B.second)
		{
			direct = -1;
		}
		else
		{
			direct = 1;
		}
	}
	return direct;
}
void sub(pair<int, int> result[], pair<int, int> dimen2[], int size)
{
	if (size == 1)
	{
		result[0] = dimen2[0];
	}
	else
	{
		int size1 = size / 2;
		int size2 = size - size1;
		pair<int, int>* result1 = new pair<int, int>[size1];
		pair<int, int>* result2 = new pair<int, int>[size2];
		pair<int, int>* L = new pair<int, int>[size1];
		pair<int, int>* R = new pair<int, int>[size2];
		for (int i = 0; i < size; i++)
		{
			if (i < size1)
			{
				L[i] = dimen2[i];
			}
			else
			{
				R[i - size1] = dimen2[i];
			}
		}
		sub(result1, L, size1);
		sub(result2, R, size2);
		int tmp1 = 0;
		int tmp2 = 0;
		int tmp = 0;
		while (tmp1 != size1 || tmp2 != size2)
		{
			if (tmp1 == size1)
			{
				while (tmp2 != size2)
				{
					result[tmp] = result2[tmp2];
					tmp++;
					tmp2++;
				}
				break;
			}
			if (tmp2 == size2)
			{
				while (tmp1 != size1)
				{
					result[tmp] = result1[tmp1];
					tmp++;
					tmp1++;
				}
				break;
			}
			if (compare(result1[tmp1], result2[tmp2]) == -1)
			{
				result[tmp] = result2[tmp2];
				tmp2++;
				tmp++;
			}
			else
			{
				result[tmp] = result1[tmp1];
				tmp1++;
				tmp++;
			}
		}
	}
}