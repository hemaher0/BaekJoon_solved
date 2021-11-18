#include<iostream>
using namespace std;
int main()
{
	int count[26] = { 0 };
	string word;
	cin >> word;
	string cur;
	cur = word;
	int selector = 0;
	int pivot = 0;
	int same = 0;
	while (cur.length() != 0)
	{
		if (cur.back() >= 'A' && cur.back() <= 'Z')
		{
			selector = 'A';
		}
		else if (cur.back() >= 'a' && cur.back() <= 'z')
		{
			selector = 'a';
		}
		if (selector != 0)
		{
			count[cur.back() - selector] = count[cur.back() - selector] + 1;
		}
		cur.pop_back();
	}
	for (int i = 0; i < 26; i++)
	{
		if (count[i] > count[pivot])
		{
			pivot = i;
			same = 0;
		}
		else if (count[i] == count[pivot])
		{
			if (i != pivot)
			{
				same = 1;
			}
		}
	}
	if (same == 1)
	{
		cout << '?';
	}
	else
	{
		cout << (char)(pivot + 'A');
	}
}