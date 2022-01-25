#include<iostream>
#include<string>
using namespace std;
struct node
{
	int itm;
	node* next;
	node* prev;
};
class queue
{
public:
	queue()
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
		int tmp = front();
		if (!empty())
		{
			node* cur = head->next;
			cur->next->prev = head;
			head->next = cur->next;
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
	int front()
	{
		if (empty())
		{
			return -1;
		}
		else
		{
			return head->next->itm;
		}
	}
	int back()
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
	queue q;
	for (int i = 0; i < N; i++)
	{
		string cur;
		getline(cin, cur);
		if (cur == "front")
		{
			cout << q.front() << '\n';
		}
		else if (cur == "back")
		{
			cout << q.back() << '\n';
		}
		else if (cur == "pop")
		{
			cout << q.pop() << '\n';
		}
		else if (cur == "empty")
		{
			cout << q.empty() << '\n';
		}
		else if (cur == "size")
		{
			cout << q.size() << '\n';
		}
		else
		{
			string num = cur.substr(5);
			q.push(stoi(num));
		}
	}
	return 0;
}