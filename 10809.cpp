#include<iostream>
#include<string>
using namespace std;
int main()
{
	string S;
	cin >> S;
	int count[26];
	for (int e = 0; e < 26; e++)
	{
		count[e] = -1;
	}
	for (int i = 0; i < S.length(); i++)
	{
		if (count[S[i] - 'a'] == -1)
		{
			count[S[i] - 'a'] = i;
		}
	}
	for (int j = 0; j < 26; j++)
	{
			cout << count[j] << " ";
	}
	return 0;
}