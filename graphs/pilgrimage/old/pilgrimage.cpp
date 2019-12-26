#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<vector<int>>> mat3d_t;
typedef vector<vector<int>> mat2d_t;

struct Node {
	int id;
	int population;
	vector<int> parents;

	Node() {}
	Node(int n, int p) {
		id = n;
		population = p;
	}
};

bool contains(vector<int>& vec, int t) {
	for (auto e : vec) {
		if (e == t) return true;
	}
	return false;
}

int max_dijk(mat3d_t& adj_list, vector<int>& popu) {
	queue<Node> pq;
	pq.push(Node(0, popu[0]));

	int max = 0;

	while (!pq.empty()) {
		Node n = pq.front();
		pq.pop();

		bool last = true;
		for (auto neighbour : adj_list[n.id]) {
			if (contains(n.parents, neighbour[1])) continue;
			last = false;
			int pop_plus = popu[neighbour[1]] + neighbour[0] + n.population;
			pq.push(Node(neighbour[1], pop_plus));
			pq.back().parents = n.parents;
			pq.back().parents.push_back(n.id);
		}
		if (last) {
			cout << n.population << endl;
		}
		//max = n.population > max ? n.population : max;
	}
	return max;
}


int main(int argc, char *argv[]) {

	cout << max_dijk(adj_list, popu);

	return 0;
}
