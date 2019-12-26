#include<bits/stdc++.h>
using namespace std;
#define INF 20000000

class DSU {
	private:
		vector<int>	parents;
		vector<int> sizes;
	public:
		DSU() {;}
		DSU(int n) {
			parents.resize(n);
			iota(parents.begin(), parents.end(), 0);
			sizes.resize(n);
			fill(sizes.begin(), sizes.end(), 1);
		}

		int find(int i) {
			while (parents[i] != i) i = parents[i];
			return i;
		}
		
		void merge(int a, int b) {
			a = find(a);
			b = find(b);
			if (a == b) return;

			if (sizes[a] < sizes[b])
				swap(a, b);

			parents[b] = a;
			sizes[a] += sizes[b];
		}
};

int node_n, edge_n;
vector<vector<int>> edge_list;
DSU max_span_tree;
int total = 0;


int main(int argc, char *argv[]) {

	// node no., edge no.
	cin >> node_n >> edge_n;

	// initialise disjoint set union
	max_span_tree = DSU(node_n);

	// populations
	int r;
	for(int i = 0; i < node_n; ++i) {
		cin >> r;
		total += r;
	}

	// edge list
	int a, b;
	for(int i = 0; i < edge_n; ++i) {
		cin >> a >> b >> r;
		edge_list.push_back({r, a, b});
	}

	// sort edge list
	sort(edge_list.begin(), edge_list.end(), greater<vector<int>>());

	//int c = 0;
	for(vector<int> edge : edge_list) {
		if (max_span_tree.find(edge[1]) == max_span_tree.find(edge[2])) continue;
		//++c;
		max_span_tree.merge(edge[1], edge[2]);
		total += edge[0];

		//if (c == node_n) break;
	}

	cout << total << endl;
	return 0;
}

