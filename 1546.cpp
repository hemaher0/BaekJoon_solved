#include<iostream>
using namespace std;
int main()
{
	int N = 0;
	int pivot = 0;
	cin >> N;
	float *score = new float[N];
	float M = 0;
	float total = 0;
	for (int i = 0; i < N; i++) 
	{
		cin >> score[i];
		if (score[i] > score[pivot])
		{
			pivot = i;
		}
	}
	M = score[pivot];
	for (int j = 0; j < N; j++)
	{
		score[j] = score[j] / M * 100;
		total = score[j] + total;
	}
	float average = total / N;
	cout << average;
	return 0;
}