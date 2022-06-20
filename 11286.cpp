#include<iostream>
#include<vector>
using namespace std;
struct num {
	num() {}	num(int N, bool P = true)
	{
		n = N;
		p = P;
	}
	int n;
	bool p;
};
class absheap {
public:
	absheap()
	{
		size = 0;
	}
	void insert(int x)
	{
		size++;
		num n(x);
		if (x < 0) {
			n.n = -n.n;
			n.p = false;
		}
		h[size] = n;
		int i = size;
		while (i != 1) {
			if (h[i].n < h[i / 2].n) {
				int tmpn = h[i].n;
				bool tmpp = h[i].p;
				h[i].n = h[i / 2].n;
				h[i].p = h[i / 2].p;
				h[i / 2].n = h[i].n;
				h[i / 2].n = tmpn;
				h[i / 2].p = tmpp;
			}
			else {
				if (h[i].n == h[i / 2].n) {
					if (h[i].p != h[i / 2].p) {
						h[i / 2].p = false;
						h[i].p = true;
					}
				}
			}
			i /= 2;
		}
	}
	int pop()
	{
		if (!size) {
			return 0;
		}
		else {
			num result = h[1];
			h[1] = h[size];
			size--;
			int i = 1;
			while (size >= 2 * i) {
				i = 2 * i;
				if (size >= i + 1) {
					if (h[i].n > h[i + 1].n) {
						i = i + 1;
					}
					else if (h[i].n == h[i + 1].n) {
						if (h[i + 1].p == false) {
							i = i + 1;
						}
					}
				}
				if (h[i].n < h[i / 2].n) {
					int tmp = h[i].n;
					bool b = h[i].p;
					h[i].n = h[i / 2].n;
					h[i].p = h[i / 2].p;
					h[i / 2].n = tmp;
					h[i / 2].p = b;
				}
				else {
					if (h[i].n == h[i / 2].n) {
						if (h[i].p != h[i / 2].p) {
							h[i / 2].p = false;
							h[i].p = true;
						}
					}
				}

			}
			return sign[result.p] * result.n;
		}

	}

private:
	int size;
	num h[100001];
	int sign[2] = { -1, 1 };
};
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	absheap h;
	vector<int> v;
	while (N--) {
		int x;
		cin >> x;
		if (x) {
			h.insert(x);
		}
		else {
			v.push_back(h.pop());
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
	return 0;
}