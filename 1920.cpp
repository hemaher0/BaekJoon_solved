#include<iostream>
#include<string>
using namespace std;
struct node
{
	int item;
	node* child;
	node* sibling;
};
class tree
{
public:
	tree()
	{
		root = new node;
		root->child = NULL;
		root->sibling = root;
		root->item = 0;
		height = 1;
	}
	void insert(string n)
	{
		int size = n.size();
		string tmp = "0";
		if (size < height)
		{
			while (tmp.size() + size != height)
			{
				tmp = tmp + "0";
			}
			n = tmp + n;
			size = size + tmp.size();
		}
		else if (size > height)
		{
			while (height != n.size())
			{
				node* newnode = new node;
				newnode->item = 0;
				newnode->child = root->child;
				newnode->sibling = NULL;
				root->child = newnode;
				height++;
			}
		}
		node* cursor = root;
		for (int i = 0; i < size; i++)
		{
			if (cursor->child)
			{
				cursor = cursor->child;
				while (cursor->item != n[i]-'0')
				{
					if(cursor->sibling)
					{
						cursor = cursor->sibling;
					}
					else
					{
						node* newnode = new node;
						newnode->item = n[i] - '0';
						newnode->child = NULL;
						newnode->sibling = NULL;
						cursor->sibling = newnode;
					}
				}
			}
			else
			{
				node* newnode = new node;
				newnode->item = n[i] - '0';
				cursor->child = newnode;
				newnode->sibling = NULL;
				newnode->child = NULL;
				cursor = cursor->child;
			}
		}
	}
	bool search(string n)
	{
		int size = n.size();
		string tmp = "0";
		if (size < height)
		{
			while (tmp.size() + size != height)
			{
				tmp = tmp + "0";
			}
			n = tmp + n;
			size = size + tmp.size();
		}
		if (height < size)
		{
			return false;
		}
		else
		{
			node* cursor = root;
			for (int i = 0; i < size; i++)
			{
				if (cursor->child)
				{
					cursor = cursor->child;
					while (cursor->item != n[i]-'0')
					{
						if (cursor->sibling)
						{
							cursor = cursor->sibling;
						}
						else
						{
							return false;
						}
					}
				}
				else
				{
					if (cursor->item != n[i] - '0')
					{
						return false;
					}
					else
					{
						return true;
					}
				}
			}
			return true;
		}
	}
private:
	int height = 0;
	node* root = new node;
};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	int M;
	tree trp;
	tree trm;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		if (s[0]=='-')
		{
			trm.insert(s.substr(1));
		}
		else
		{
			trp.insert(s);
		}
	}
	cin >> M;
	for (int j = 0; j < M; j++)
	{
		string s;
		cin >> s;
		if (s[0]=='-')
		{
			cout << trm.search(s.substr(1)) << '\n';
		}
		else
		{
			cout << trp.search(s) << '\n';
		}
	}

	return 0;
}