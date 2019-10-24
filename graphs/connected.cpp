#include<bits/stdc++.h>
using namespace std;

class DSU {
	public:
		vector<int> parent;
		vector<int> size;

		DSU(int len) {
			parent.resize(len);
			size.resize(len);
			iota(parent.begin(), parent.end(), 0);
			fill(size.begin(), size.end(), 1);
		}

		int find(int x) {
			if(parent[x] == x) return x;
			else return parent[x] = find(parent[x]);
		}

		void merge(int x, int y) {
			x = find(x);
			y = find(y);

			if (x == y) 
				return;

			if (size[x] < size[y]) 
				swap(x, y);

			parent[y] = x;
			size[x] += size[y];
		}
};

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	DSU dsu(n);

	int a, b;
	cin >> a >> b;
	while (a != -1) {
		dsu.merge(a, b);
		cin >> a >> b;
	}

	int count = 1;
	vector<bool> seen(n, false);
	for(int i = 0; i < n; ++i) {
		if (!seen[i]) {
			cout << count << ": ";
			++count;
			for(int j = 0; j < n; ++j) {
				if (dsu.find(i) == dsu.find(j)) {
					cout << j << " ";
					seen[j] = true;
				}
			}
			cout << endl;
		}
	}
	return 0;
}

