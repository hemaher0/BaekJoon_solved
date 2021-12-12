#include<iostream>
#include<string>
using namespace std;
class people
{
public:
	people()
	{

	}
	void setpeople(int w, int h)
	{
		weight = w;
		height = h;
	}
	int backweight()
	{
		return weight;
	}
	int backheight()
	{
		return height;
	}
	int rank = 1;
private:
	int weight = 0;
	int height = 0;
};
int main()
{
	int N;
	cin >> N;
	people* plist = new people[N];
	for (int i = 0; i < N; i++)
	{
		int w;
		int h;
		cin >> w >> h;
		plist[i].setpeople(w, h);
	}
	
	for (int pivot = 0; pivot < N; pivot++)
	{
		for (int current = 0; current < N; current++)
		{
			bool s1 = plist[current].backweight() < plist[pivot].backweight();
			bool s2 = plist[current].backheight() < plist[pivot].backheight();
			if (s1 && s2)
			{
				plist[current].rank = plist[current].rank + 1;
			}
		}
	}
	for (int j = 0; j < N; j++)
	{
		cout << plist[j].rank<<" ";
	}
	return 0;
}