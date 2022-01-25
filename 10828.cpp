#include<iostream>
#include<string>
using namespace std;
struct node
{
	int itm;
	node* next;
	node* prev;
};
class stack
{
public:
	stack()
	{
		head = new node;
		tail = new node;
		head->next = tail;
		head->prev = head;
		tail->next = tail;
		tail->prev = head;
	}
	void push(int X)
	{
		node* cur = tail->prev;
		node* tmp = new node;
		cur->next = tmp;
		tail->prev = tmp;
		tmp->prev = cur;
		tmp->next = tail;
		tmp->itm = X;
		count++;
	}
	int pop()
	{
		int tmp = top();
		if (!empty())
		{
			node* cur = tail->prev;
			cur->prev->next = tail;
			tail->prev = cur->prev;
			delete cur;
			count--;
		}
		
		return tmp;
	}
	int size()
	{
		return count;
	}
	int empty()
	{
		if (count != 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	int top()
	{
		if (empty())
		{
			return -1;
		}
		else
		{
			return tail->prev->itm;
		}
		
	}
private:
	node* head;
	node* tail;
	int count = 0;
};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	cin.clear();
	cin.ignore();
	stack stk;
	for (int i = 0; i < N; i++)
	{
		string cur;
		getline(cin, cur);
		if (cur=="top")
		{
			cout<<stk.top()<<'\n';
		}
		else if(cur == "pop")
		{
			cout << stk.pop()<<'\n';
		}
		else if(cur == "empty")
		{
			cout << stk.empty()<<'\n';
		}
		else if(cur =="size")
		{
			cout << stk.size() << '\n';
		}
		else
		{
			string num = cur.substr(5);
			stk.push(stoi(num));
		}
	}
	return 0;
}