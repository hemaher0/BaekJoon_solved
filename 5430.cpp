#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--){
		string p, arr;
		int size;
		cin >> p;
		cin >> size;
		cin >> arr;
		vector<int> X;
		int num = 0;
		for (int x = 0; x < arr.length(); x++)
		{
			int k = arr[x] - '0';
			if (k >= 0 && k < 10){
				num = num * 10 + k;
			}
			else{
				if(num)X.push_back(num);
				num = 0;
			}
		}
		bool mode = true;
		int st = 0;
		int ed = X.size();
		for (int i = 0; i < p.length(); i++)
		{
			if (p[i] == 'R')
			{
				if (X.size()) 
				{
					mode = !mode;
				}
			}
			else{
				if (mode)
				{
					st++;
				}
				else
				{
					ed--;
				}
				if (st > ed)
				{
					break;
				}
			}
		}
		if (st <= ed) 
		{
			cout << "[";
			int sign[2] = { -1, 1 };
			int i;
			if (mode)
			{
				i = st;
			}
			else
			{
				i = ed - 1;
			}
			for(int count = 0; count< ed - st; count++)
			{
				if (count == ed - st - 1)
				{
					cout << X[i];
				}
				else
				{
					cout << X[i] << ",";
				}
				i = i + sign[mode] * 1;
			}
			cout << "]"<<"\n";
		}
		else {
			cout << "error" << "\n";
		}
	}
	return 0;
}