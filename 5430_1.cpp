#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T, size;
	string p, arr;
	cin >> T;
	while (T--)
	{
		cin >> p  >> size >> arr;
		vector<int> X;
		for (int x = 1; x < arr.length() - 1; x++)
		{
			int num = 0;
			while (x < arr.length() - 1&& arr[x] != ',')
			{
				num = num * 10 + arr[x++] - '0';
			}	
			X.push_back(num);
		}
		bool mode = true;
		int st = 0;
		int ed = 0;
		for (int i = 0; i < p.length(); i++)
		{
			if (p[i] == 'R')
			{
				mode = !mode;
			}
			else 
			{
				if (mode)
				{
					st++;
				}
				else
				{
					ed++;
				}
				if (st + ed> X.size())
				{
					break;
				}
			}
		}
		if (st + ed <= X.size())
		{
			string result = "[";
			if (mode)
			{
				for (int i = st; i < X.size() - ed; i++)
				{
					result.append(to_string(X[i]));
					result.push_back(',');
				}
			}
			else
			{
				for (int i = X.size() - ed - 1; i >= st; i--)
				{
					result.append(to_string(X[i]));
					result.push_back(',');
				}
			}
			if (result.length() > 1)
				result.pop_back();
			result.append("]");
			cout << result<<"\n";
		}
		else 
		{
			cout << "error" << "\n";
		}
	}
	return 0;
}