#include<iostream>
#include<queue>
using namespace std;
struct node {
		char a;
		node* left;
		node* right;
		node(char alpha = '.', node* l = NULL, node* r = NULL) {
			a = alpha;
			left = l;
			right = r;
		}
	};
class tree {
public:
	tree() {
		root = NULL;
		n = 0;
	}
	bool check(node* tar) {
		if (tar == NULL) {
			return false;
		}
		else {
			if (tar->a == '.') {
				return false;
			}
			else {
				return true;
			}
		}
	}
	void insert(node * tar) {
		if (!n) {
			root = tar;
		}
		else {
			queue<node*>q;
			q.push(root);
			node* cur;
			while (!q.empty()) {
				cur = q.front();
				q.pop();
				if (check(cur->left)) {
					if (cur->left->a == tar->a) {
						cur->left = tar;
						break;
					}
					else {
						q.push(cur->left);
					}
				}
				if(check(cur->right)) {
					if (cur->right->a == tar->a) {
						cur->right = tar;
						break;
					}
					else {
						q.push(cur->right);
					}
				}
			}
		}
		n++;
	}
	void pretraversal(node * root) {
		cout << root->a;
		if (check(root->left)) {
			pretraversal(root->left);
		}
		if (check(root->right)) {
			pretraversal(root->right);
		}
	}
	void intraversal(node * root) {
		if (check(root->left)) {
			intraversal(root->left);
		}
		cout << root->a;
		if (check(root->right)) {
			intraversal(root->right);
		}
	}
	void potraversal(node * root) {
		if (check(root->left)) {
			potraversal(root->left);
		}
		if (check(root->right)) {
			potraversal(root->right);
		}
		cout << root->a;
	}
	node* r() {
		return root;
	}
private:
	int n;
	node* root;
};
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	char a, b, c;
	tree t;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		node* left = new node(b, NULL, NULL);
		node* right = new node(c, NULL, NULL);
		node* parent = new node(a, left, right);
		t.insert(parent);
	}
	t.pretraversal(t.r());
	cout << "\n";
	t.intraversal(t.r());
	cout << "\n";
	t.potraversal(t.r());
	return 0;
}