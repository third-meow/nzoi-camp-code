#include<bits/stdc++.h>
using namespace std;
#define INF 20000000

int node_n, edge_n;
vector<int> populations;
vector<vector<vector<int>>> adj_list;
vector<bool> connected;
int total = 0;


bool activate(int pos) {
	if (connected[pos]) return false;

	for(int i = 0; i < adj_list[pos].size(); ++i) {
		if (connected[adj_list[pos][i][1]]) {
			total += adj_list[pos][i][0];
			connected[pos] = true;
			return true;
		}
	}
}

int add(int pos) {
	vector<int> new_act;
	for(vector<int> neighbour : adj_list[pos]) {
		if (activate(neighbour[1])) {
			new_act.push_back(neighbour[1]);
		}
	}
	for(int neighbour_id : new_act) {
		add(neighbour_id);
	}
}


int main(int argc, char *argv[]) {

	// node no., edge no.
	cin >> node_n >> edge_n;


	// populations
	populations = vector<int>(node_n, 0);
	for(int i = 0; i < node_n; ++i) {
		cin >> populations[i];
	}

	// adjacency list
	adj_list = vector<vector<vector<int>>>(node_n, vector<vector<int>>());
	int a, b, r;
	for(int i = 0; i < edge_n; ++i) {
		cin >> a >> b >> r;
		adj_list[a].push_back({r, b});
		adj_list[b].push_back({r, a});
	}

	// sort adjacency lists
	for(int i = 0; i < node_n; ++i) {
		sort(adj_list[i].begin(), adj_list[i].end(), greater<vector<int>>());
	}

	connected = vector<bool>(node_n, 0);
	connected[0] = true;
	add(0);
	for(int i = 0; i < node_n; ++i) {
		if (connected[i]) {
			total += populations[i];
		}
	}
	cout << total << endl;

	return 0;
}

