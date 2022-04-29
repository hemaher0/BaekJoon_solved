#include<iostream>
using namespace std;
class heap
{
public:
	void insert(int x)
	{
		index += 1;
		h[index] = x;
		int i = index;
		while(i != 1)
		{
			if (h[i / 2] < h[i])
			{
				int tmp = h[i / 2];
				h[i / 2] = h[i];
				h[i] = tmp;
			}
			i = i / 2;
		}
	}
	int max()
	{
		if (index)
		{
			int tmp = h[1];
			del();
			return tmp;
		}
		else
		{
			return 0;
		}
	}
	void del()
	{
		h[1] = h[index];
		index -= 1;
		for (int i = 1; i < index;)
		{
			int s = i * 2;
			if (s + 1<=index)
			{
				if (h[s] < h[s + 1])
				{
					s = s + 1;
				}
			}
			if (s <= index)
			{
				if (h[s] > h[i])
				{
					int tmp = h[s];
					h[s] = h[i];
					h[i] = tmp;
				}
			}
			i = s;
		}
	}
private:
	int index = 0;
	int h[100000];
};
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	heap v;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		if (x)
		{
			v.insert(x);
		}
		else
		{
			cout<< v.max()<<'\n';
		}
	}
	return 0;
}