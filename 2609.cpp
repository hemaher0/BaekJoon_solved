#include<iostream>
#include<vector>
using namespace std;
void disassamble(vector<int>*, int);
void G(vector<int>&, vector<int>, vector<int>);
void L(vector<int>&, vector<int>, vector<int>);
int main()
{
	int x, y;
	cin >> x >> y;
	vector<int> xd;
	vector<int> yd;
	disassamble(&xd, x);
	disassamble(&yd, y);
	int GCD = 1;
	vector<int> GCDtmp;
	int LCM = 1;
	vector<int> LCMtmp;
	G(GCDtmp, xd, yd);
	L(LCMtmp, xd, yd);
	while (GCDtmp.size() != 0)
	{
		GCD = GCDtmp.back() * GCD;
		GCDtmp.pop_back();
	}
	while (LCMtmp.size() != 0)
	{
		LCM = LCMtmp.back() * LCM;
		LCMtmp.pop_back();
	}
	cout << GCD << endl << LCM;
	return 0;
}
void disassamble(vector<int>* Ad, int A)
{
	int tmp = A;
	Ad->push_back(1);
	while (tmp <= A)
	{
		if (tmp >= 2)
		{
			for (int i = 2; i <= tmp; i++)
			{
				if (tmp % i == 0)
				{
					Ad->push_back(i);
					tmp = tmp / i;
					break;
				}
			}
		}
		else
		{
			break;
		}
	}
}
void G(vector<int>& result, vector<int> xd, vector<int>yd)
{
	int tmp = 0;
	for (int i = 0; i < xd.size(); i++)
	{
		vector<int> ::iterator j = yd.begin() + tmp;
		while (tmp < yd.size())
		{
			if (xd[i] < *j)
			{
				break;
			}
			else if (xd[i] > *j)
			{
				tmp = tmp + 1;
				j++;
			}
			else//same
			{
				result.push_back(xd[i]);
				tmp = tmp + 1;
				break;
			}
		}
	}
}
void L(vector<int>& result, vector<int>xd, vector<int>yd)
{
	int tmp = xd.back() >= yd.back() ? xd.back() : yd.back();
	vector<int>resulttmp;
	while (xd.size() != 0 || yd.size() != 0)
	{
		if (tmp >= xd.back())
		{
			tmp = xd.back();
			if (tmp <= yd.back())
			{
				tmp = yd.back();
				if (xd.back() == yd.back())
				{
					xd.pop_back();
				}
				resulttmp.push_back(tmp);
				yd.pop_back();
			}
			else
			{
				resulttmp.push_back(tmp);
				xd.pop_back();
			}
		}
		else
		{
			tmp = yd.back();
			resulttmp.push_back(tmp);
			yd.pop_back();
		}
	} 
	while (resulttmp.size() != 0)
	{
		result.push_back(resulttmp.back());
		resulttmp.pop_back();
	}
}