#include<iostream>
using namespace std;
struct node
{
	int item;
	node* next;
	node* prev;
};
class linkedlist
{
public:
	linkedlist()
	{
		head->next = tail;
		head->prev = head;
		tail->next = tail;
		tail->prev = head;
		count = 0;
	}
	void insert(int n)
	{
		node* newnode = new node;
		newnode->item = n;
		head->next->prev = newnode;
		newnode->next = head->next;
		newnode->prev = head;
		head->next = newnode;
		count++;
	}
	int size()
	{
		return count;
	}
	int popback()
	{
		int result;
		node* cur = tail->prev;
		node* tmp = cur->prev;
		result = cur->item;
		tail->prev = tmp;
		tmp->next = tail;
		delete cur;
		count--;
		return result;
	}
private:
	node* head = new node;
	node* tail = new node;
	int count;
};
int main()
{
	int N;
	scanf_s("%d", &N);
	//scanf("%d", &N);
	linkedlist nl;
	for (int i = 1; i <= N; i++)
	{
		nl.insert(i);
	}
	
	while (nl.size() != 1)
	{
		nl.popback();
		if (nl.size() == 1)
		{
			break;
		}
		else
		{
			int tmp = nl.popback();
			nl.insert(tmp);
		}
	}
	printf("%d", nl.popback());
	return 0;
}