#include<bits/stdc++.h>
using namespace std;
#define INF 20000000

class DSU {
	private:
		vector<uint32_t>	parents;
		vector<uint32_t> sizes;
	public:
		DSU() {;}
		DSU(uint32_t n) {
			parents.resize(n);
			iota(parents.begin(), parents.end(), 0);
			sizes.resize(n);
			fill(sizes.begin(), sizes.end(), 1);
		}

		uint32_t find(uint32_t i) {
			while (parents[i] != i) i = parents[i];
			return i;
		}
		
		void merge(uint32_t a, uint32_t b) {
			a = find(a);
			b = find(b);
			if (a == b) return;

			if (sizes[a] < sizes[b])
				swap(a, b);

			parents[b] = a;
			sizes[a] += sizes[b];
		}
};

uint32_t node_n, edge_n;
vector<vector<uint32_t>> edge_list;
DSU graph;
DSU max_span_tree;
uint32_t total = 0;


int main(int argc, char *argv[]) {

	// node no., edge no.
	cin >> node_n >> edge_n;

	// initialise disjoint set union
	max_span_tree = DSU(node_n);
	graph = DSU(node_n);

	// populations
	vector<uint32_t> populations(node_n, 0);
	for(uint32_t i = 0; i < node_n; ++i) {
		cin >> populations[i];
	}

	// edge list
	int a, b, r;
	for(uint32_t i = 0; i < edge_n; ++i) {
		cin >> a >> b >> r;
		graph.merge(a, b);
		edge_list.push_back({r, a, b});
	}

	// sort edge list
	sort(edge_list.begin(), edge_list.end(), greater<vector<uint32_t>>());

	for(vector<uint32_t> edge : edge_list) {
		if (max_span_tree.find(edge[1]) == max_span_tree.find(edge[2])) continue;
		if (graph.find(edge[1]) != graph.find(0)) continue;
		max_span_tree.merge(edge[1], edge[2]);
		total += edge[0];
	}
	
	for(uint32_t i = 0; i < node_n; ++i) {
		if (graph.find(i) == graph.find(0)) total += populations[i];
	}

	cout << total << endl;
	return 0;
}

