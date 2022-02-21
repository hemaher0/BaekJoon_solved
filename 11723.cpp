#include<iostream>
#include<string>
using namespace std;
class set
{
public:
	set()
	{
		for (int i = 1; i <= 20; i++)
		{
			arr[i] = 0;
		}
	}
	void add(int x)
	{
		if (!arr[x])
			arr[x] = 1;
	}
	void remove(int x)
	{
		if (arr[x])
			arr[x] = 0;
	}
	int check(int x)
	{
		return arr[x];
	}
	void toggle(int x)
	{
		if (arr[x])
			arr[x] = 0;
		else
			arr[x] = 1;
	}
	void all()
	{
		for (int i = 1; i <= 20; i++)
		{
			arr[i] = 1;
		}
	}
	void empty()
	{
		for (int i = 1; i <= 20; i++)
		{
			arr[i] = 0;
		}
	}
private:
	int arr[21];
};
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int M;
	cin >> M;
	set s;
	cin.ignore();
	for (int i = 0; i < M; i++)
	{
		string str;
		getline(cin, str);
		if (str == "all")
		{
			s.all();
		}
		else if(str == "empty")
		{
			s.empty();
		}
		else
		{
			string strc;
			string num;
			strc = str.substr(0,3);
			num = str.substr(4);
			if (strc == "add")
				s.add(stoi(num));
			else
			{
				strc = str.substr(0, 5);
				num = str.substr(6);
				if (strc == "check")
				{
					int result = s.check(stoi(num));
					cout << result<<'\n';
				}
				else
				{
					strc = str.substr(0, 6);
					num = str.substr(7);
					if (strc == "remove")
						s.remove(stoi(num));
					else
						s.toggle(stoi(num));
				}
			}
		}
	}
	return 0;
}