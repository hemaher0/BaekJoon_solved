#include<iostream>
using namespace std;
struct node
{
	int item;
	node* next;
	node* prev;
};
class queue
{
public:
	queue(int k = 0)
	{
		pivot = new node;
		count = 0;
		pivot->next = pivot;
		pivot->prev = pivot;
		for (int i = 1; i <= k; i++)
		{
			insert(i);
		}
	}
	void insert(int k)
	{
		node* newnode = new node;
		newnode->item = k;
		newnode->next = pivot;
		newnode->prev = pivot->prev;
		pivot->prev->next = newnode;
		pivot->prev = newnode;
		count++;
	}
	bool empty()
	{
		if (count)
			return false;
		else
			return true;
	}
	int next(int k)
	{
		node* cursor = pivot;
		for (int i = 0; i < k; i++)
		{
			cursor = cursor->next;
			if (cursor == pivot)
			{
				cursor = cursor->next;
			}
		}
		int result = cursor->item;
		pivot->prev->next = pivot->next;
		pivot->next->prev = pivot->prev;
		cursor->prev->next = pivot;
		pivot->prev = cursor->prev;
		cursor->next->prev = pivot;
		pivot->next = cursor->next;
		count--;
		return result;
	}
private:
	node* pivot;
	int count;
};
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	int K;
	cin >> N >> K;
	queue q(N);
	cout << "<";
	for (int i = 1; i <= N; i++)
	{
		if (i == N)
		{
			cout << q.next(K);
		}
		else
		{
			cout << q.next(K) << ", ";
		}
		
	}
	cout << ">";
	return 0;
}