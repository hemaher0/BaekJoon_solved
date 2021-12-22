#include<iostream>
#include<vector>
using namespace std;
int arit(int[], int);
int cent(int[], int);
int many(int[], int);
int scope(int[], int);
int main()
{
	int N;
	scanf_s("%d",&N);
	//scanf("%d", &N);
	int* Nlist = new int[N];
	for (int i = 0; i < N; i++)
	{
		int c;
		scanf_s("%d",&c);
		Nlist[i] = c;
	}
	int a = arit(Nlist, N);
	int c = cent(Nlist, N);
	int m = many(Nlist, N);
	int s = scope(Nlist, N);
	printf("%d\n%d\n%d\n%d",a,c,m,s);
	return 0;
}
int arit(int Nlist[], int size)
{
	int result;
	int tmpplus = 0;
	int tmpminus = 0;
	int countp = 0;
	int countm = 0;
	for (int i = 0; i < size; i++)
	{
		if (Nlist[i] < 0)
		{
			tmpminus = tmpminus + Nlist[i];
			if (tmpminus <= -size)
			{
				countm = countm + tmpminus/size;
				tmpminus = tmpminus % size;
			}
		}
		else
		{
			tmpplus = tmpplus + Nlist[i];
			if (tmpplus >= size)
			{
				countp = countp + tmpplus/size;
				tmpplus = tmpplus % size;
			}
		}
	}
	if (tmpplus + tmpminus > size / 2)
	{
		countp++;
	}
	if (tmpplus + tmpminus < -size / 2)
	{
		countm--;
	}
	result = countp + countm;
	return result;
}
int cent(int Nlist[], int size)
{
	int result;
	int count[8001] = { 0 };
	int tmp = 0;
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		count[Nlist[i] + 4000] = count[Nlist[i] + 4000] + 1;
	}
	for (int j = 0; j < 8001; j++)
	{
		tmp = count[j] + tmp;
		if (tmp >= size / 2 + 1)
		{
			index = j - 4000;
			break;
		}
	}
	result = index;
	return result;
}
int many(int Nlist[], int size)
{
	int result;
	int count[8001] = { 0 };
	int tmp = 0;
	int min[2];
	int counter = 0;
	vector<int> pivot;
	for (int i = 0; i < size; i++)
	{
		count[Nlist[i] + 4000]++;
	}
	for (int j = 0; j < size; j++)
	{
		if (count[Nlist[j] + 4000] >= tmp)
		{
			if (count[Nlist[j] + 4000] > tmp)
			{
				tmp = count[Nlist[j] + 4000];
				pivot.clear();
				min[0] = Nlist[j];
			}
			else
			{
				if (min[0] > Nlist[j])
				{
					min[0] = Nlist[j];
				}
			}
			pivot.push_back(Nlist[j]);
		}
	}
	min[1] = 4000;
	while (pivot.size() != 0)
	{
		if (pivot.back() > min[0] && pivot.back() < min[1])
		{
			min[1] = pivot.back();
		}
		pivot.pop_back();
	}
	if (min[1] == 4000)
	{
		min[1] = min[0];
	}
	result = min[1];
	return result;
}
int scope(int Nlist[], int size)
{
	int result;
	int max = -10000;
	int min = 10000;
	for (int i = 0; i < size; i++)
	{
		if (Nlist[i] > max)
		{
			max = Nlist[i];
		}
		if (Nlist[i] < min)
		{
			min = Nlist[i];
		}
	}
	result = max - min;
	return result;
}