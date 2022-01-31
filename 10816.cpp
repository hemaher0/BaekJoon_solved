#include<iostream>
using namespace std;
struct node
{
	int item;
	int count;
	node* leftchild;
	node* rightchild;
	node* parent;
};
class tree
{
public:
	tree()
	{
		root = new node;
		root->count = 0;
		root->leftchild = NULL;
		root->rightchild = NULL;
		depth = 0;
	}
	void insert(int i)
	{
		if (empty())
		{
			root->item = i;
			root->count++;
			depth++;
		}
		else
		{
			node* cur = search(root, i);
			if (cur->item == i)
			{
				cur->count++;
			}
			else
			{
				if (cur->item > i)
				{
					cur->leftchild = new node;
					cur->leftchild->item = i;
					cur->leftchild->count = 1;
					cur->leftchild->leftchild = NULL;
					cur->leftchild->rightchild = NULL;
				}
				else
				{
					cur->rightchild = new node;
					cur->rightchild->item = i;
					cur->rightchild->count = 1;
					cur->rightchild->leftchild = NULL;
					cur->rightchild->rightchild = NULL;
				}
				
			}
		}
	}
	node* search(node* n, int i)
	{
		if (n->item == i)
		{
			return n;
		}
		else
		{
			if (n->leftchild or n->rightchild)
			{
				if (n->item > i)
				{
					if (n->leftchild)
						return search(n->leftchild, i);
					else
						return n;
				}
				if (n->item < i)
				{
					if (n->rightchild)
						return search(n->rightchild, i);
					else
						return n;

				}
			}
			else
			{
				return n;
			}
		}
	}
	int check(int i)
	{
		node *cur = search(root, i);
		if (cur->item == i)
			return cur->count;
		else
			return 0;
	}
	bool empty()
	{
		if (depth == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	node* root;
	int depth;
};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	int M;
	cin >> N;
	tree tr;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		tr.insert(n);
	}
	cin >> M;
	for (int j = 0; j < M; j++)
	{
		int m;
		cin >> m;
		cout << tr.check(m)<<" ";
	}
	return 0;
}