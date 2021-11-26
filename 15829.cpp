#include<iostream>
#include<string>
using namespace std;
string sum(string, string);
string mult(string, string);
string remains(string, string);
string substract(string, string);
int compare(string, string);
void removezero(string&);
int main()
{
	int L;
	string H;
	string M = "1234567891";
	string r = "31";
	string s;
	cin >> L>>s;
	for (int i = 0; i < L; i++)
	{
		string multi;
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
			{
				 multi = "1";
			}
			else
			{
				multi = mult(multi,r);
			}
		}

		multi = mult(multi, to_string(s[i] - 'a' + 1));
		H = sum(H, multi);
	}
	H = remains(H, M);
	cout << H;
	return 0;
}
string sum(string A, string B)
{
	string result = "0";
	int alpha = 0;
	int subsum = 0;
	if (A.length() >= B.length())
	{
		for (int i = 0; i < B.length(); i++)
		{
			while (result.length() <= i)
			{
				result.insert(0, "0");
			}
			subsum = result[result.length() - i - 1] - '0' + A[A.length() - i - 1] - '0' + B[B.length() - i - 1] - '0' + alpha;
			if (subsum >= 10)
			{
				alpha = 1;
				subsum -= 10;
			}
			else
			{
				alpha = 0;
			}
			result[result.length() - i - 1] = subsum + '0';
		}
		result.insert(0, to_string(alpha));
		alpha = 0;
		removezero(result);
		for (int j = B.length(); j <= A.length(); j++)
		{
			if (j == A.length())
			{
				result.insert(0, to_string(alpha));
			}
			else
			{
				while (result.length() <= j)
				{
					result.insert(0, "0");
				}
				subsum = result[result.length() - j - 1] - '0' + A[A.length() - j - 1] - '0' + alpha;
				if (subsum >= 10)
				{
					alpha = 1;
					subsum -= 10;
				}
				else
				{
					alpha = 0;
				}
				result[result.length() - j - 1] = subsum + '0';
			}
		}
		removezero(result);
	}
	else
	{
		result = sum(B, A);
	}
	return result;
}
string mult(string A, string B)
{
	string result = "";
	int alpha = 0;
	int submult = 0;
	for (int i = 0; i <= B.length(); i++)
	{
		if (i == B.length())
		{
			result.insert(0, to_string(alpha));
		}
		else
		{
			for (int j = 0; j <= A.length(); j++)
			{
				if (j == A.length())
				{
					result.insert(0, to_string(alpha));
					alpha = 0;
					removezero(result);
				}
				else 
				{
					while (result.length() <= i + j)
					{
						result.insert(0, "0");
					}
					submult = result[result.length() - i - j - 1] + (A[A.length() - j - 1] - '0') * (B[B.length() - i - 1] - '0') + alpha - '0';
					if (submult >= 10)
					{
						alpha = submult / 10;
						submult = submult % 10;
					}
					else
					{
						alpha = 0;
					}
					result[result.length() - i - j - 1] = submult + '0';
				}
			}
		}

	}
	removezero(result);
	return result;
}
void removezero(string& num)
{
	string result = "";
	int pivot = 0;
	for (int i = 0; i < num.length(); i++)
	{
		if (num[i] != '0')
		{
			pivot = i;
			break;
		}
	}
	if (pivot != 0)
	{
		for (int j = pivot; j < num.length(); j++)
		{
			result.append(to_string(num[j] - '0'));
		}
	}
	else
	{
		result = num;
	}
	num = result;
}
string remains(string A, string B)
{
	string result;
	string tmp = A;
	string B1 = B.substr(0, 5);
	string B2 = B.substr(5);
	while (compare(tmp, B) == -1)
	{
		int size = tmp.length() / 10;
		string* strlist = new string[size +1];
		strlist[0] = tmp.substr(0, 10);
		strlist[1] = tmp.substr(10);
		int quotient_B1 = stoi(strlist[0].substr(0,5)) / stoi(B1);
		if (compare(strlist[0], B) == 1)
		{
			if (quotient_B1 == 0)
			{
				strlist[0] = tmp.substr(0, 11);
				strlist[1] = tmp.substr(11);
				strlist[0] = substract(strlist[0], B1 + B2);
				tmp = strlist[0] + strlist[1];
				delete[]strlist;
				continue;
			}
		}
		string s1 = mult(B1, to_string(quotient_B1));
		while (s1.length() < 10)
		{
			s1.append("0");
		}
		string s2 = mult(B2, to_string(quotient_B1));
		strlist[0] = substract(strlist[0],sum(s1,s2));
		tmp = strlist[0] + strlist[1];
		delete[]strlist;
	}
	result = tmp;
	return result;
}
int compare(string A, string B)
{
	int result;
	if (A.length() == B.length())
	{
		for (int i = 0; i < A.length(); i++)
		{
			if (A[i] > B[i])
			{
				result = -1;
				break;
			}
			else if (A[i] < B[i])
			{
				result = 1;
				break;
			}
			else
			{
				if (i == A.length() - 1)
				{
					result = 0;
				}
			}
		}
	}
	else
	{
		if (A.length() > B.length())
		{
			result = -1;
		}
		else
		{
			result = 1;
		}
	}
	return result;
}
string substract(string A, string B)
{
	int cp = compare(A, B);
	if (cp == 0)
	{
		return "0";
	}
	else
	{
		if (cp == -1)
		{
			string result = "0";
			int alpha = 0;
			int substract = 0;
			for (int i = 0; i < B.length(); i++)
			{
				while (result.length() <= i)
				{
					result.insert(0, "0");
				}
				substract = A[A.length() - i - 1] - '0' - B[B.length() - i - 1] + '0' + alpha;
				if (substract < 0)
				{
					alpha = -1;
					substract = 10 + substract;
				}
				else
				{
					alpha = 0;
				}
				result[result.length() - i - 1] = substract + '0';
			}
			if (A.length() != B.length())
			{
				for (int j = B.length(); j < A.length(); j++)
				{
					while (result.length() <= j)
					{
						result.insert(0, "0");
					}
					substract = A[A.length() - j - 1] - '0' + alpha;
					if (substract < 0)
					{
						alpha = -1;
						substract = 10 + substract;
					}
					else
					{
						alpha = 0;
					}
					result[result.length() - j - 1] = substract + '0';
				}
			}
			removezero(result);
			return result;
		}
	}
}