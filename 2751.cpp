#include<iostream>
#include<vector>
using namespace std;
void sub(int[],int [], int size);
int main()
{
	int N;
	cin >> N;
	int* al = new int [N];
	int* result = new int[N];
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		al[i] = a;
	}
	sub(result, al, N);
	for(int j = 0; j<N;j++)
	{
		cout << result[j]<<'\n';
	}
	return 0;
}
void sub(int result[], int al[], int size)
{
	if (size == 1)
	{
		result[0] = al[0];
	}
	else
	{
		int size1 = size/2 ;
		int size2 = size - size1;

		int * list1 = new int[size1];
		int * list2 = new int[size2];
		int* result1 = new int[size1];
		int* result2 = new int[size2];
		
		int sizer = 0;
		
		for (int i = 0; i <size ; i++)
		{
			if (i < size1)
			{
				list1[i] = al[i];
			}
			else
			{
				list2[i - size1] = al[i];
			}
		}
		sub(result1, list1, size1);
		sub(result2, list2, size2);
		int count1 = 0;
		int count2 = 0;
		while (size1 != 0 || size2 != 0)
		{
			if (size1 == 0)
			{
				while (size2 != 0)
				{
					result[sizer] = result2[count2];
					sizer += 1;
					count2 += 1;
					size2 -= 1;
				}
				break;
			}
			if (size2 == 0)
			{
				while (size1 != 0)
				{
					result[sizer] = result1[count1];
					sizer += 1;
					count1 += 1;
					size1 -= 1;
				}
				break;
			}
			if (result1[count1] > result2[count2])
			{
				result[sizer] = result2[count2];
				sizer += 1;
				count2 += 1;
				size2 -= 1;
			}
			else
			{
				result[sizer] = result1[count1];
				sizer += 1;
				count1 += 1;
				size1 -= 1;
			}
		}
		delete[] list1;
		delete[] list2;
		delete[] result1;
		delete[] result2;
	}
}