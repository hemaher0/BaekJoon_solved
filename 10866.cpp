#include<iostream>
#include<string>
using namespace std;
struct node
{
	int itm;
	node* next;
	node* prev;
};
class deque
{
public:
	deque()
	{
		head = new node;
		tail = new node;
		head->next = tail;
		head->prev = head;
		tail->next = tail;
		tail->prev = head;
	}
	void push_back(int X)
	{
		node* cur = tail->prev;
		node* tmp = new node;
		cur->next = tmp;
		tail->prev = tmp;
		tmp->prev = cur;
		tmp->next = tail;
		tmp->itm = X;
		count++;
	}void push_front(int X)
	{
		node* cur = head->next;
		node* tmp = new node;
		cur->prev = tmp;
		head->next = tmp;
		tmp->next = cur;
		tmp->prev = head;
		tmp->itm = X;
		count++;
	}
	int pop_back()
	{
		int tmp = back();
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
	int pop_front()
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
	deque q;
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
		else if (cur == "pop_front")
		{
			cout << q.pop_front() << '\n';
		}
		else if (cur == "pop_back")
		{
			cout << q.pop_back() << '\n';
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
			string tmp = cur.substr(0,9);
			if (tmp == "push_back")
			{
				tmp = cur.substr(10);
				q.push_back(stoi(tmp));

			}
			else
			{
				tmp = cur.substr(11);
				q.push_front(stoi(tmp));

			}
		}
	}
	return 0;
}