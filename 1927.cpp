#include<iostream>
using namespace std;
class heap
{
public:
	void insert(int x)
	{
		index++;
		h[index] = x;
		int i = index;
		while (i != 1)
		{
			if (h[i] < h[i / 2])
			{
				int tmp = h[i];
				h[i] = h[i / 2];
				h[i / 2] = tmp;
			}
			i = i / 2;
		}
	}
	int min()
	{
		if (index)
		{
			int m = h[1];
			del();
			return m;
		}
		else
		{
			return 0;
		}
	}
	void del()
	{
		int tmp = h[1];
		h[1] = h[index];
		h[index] = 0;
		index -= 1;
		int i = 1;
		for (int i = 1; i < index; )
		{
			int s = i * 2;
			if (s + 1 <= index)
			{
				if (h[i] > h[s] or h[i] > h[s + 1])
				{
					if (h[s + 1] < h[s])
					{
						s = s + 1;
					}
					
				}
			}
			if (s <= index)
			{
				if (h[i] > h[s])
				{
					int tmp = h[i];
					h[i] = h[s];
					h[s] = tmp;
				}
			}
			i = s;
		}
	}
private:
	int h[100000];
	int index = 0;
};
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	heap m;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		if (x)
		{
			m.insert(x);
		}
		else
		{
			cout << m.min() << '\n';
		}
	}

	return 0;
}