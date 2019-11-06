#include<bits/stdc++.h>
using namespace std;
#define INF 2000000

bool cycle_check(const vector<vector<vector<int>>>& adj_list, int pos, int root, vector<bool> visited) {
	visited[pos] = true;
	for(vector<int> neighbour : adj_list[pos]) {
		if (neighbour[0] == root) continue;
		if (visited[neighbour[0]]) {
			return true;
		}
		if (cycle_check(adj_list, neighbour[0], pos, visited)) {
			return true;
		}
	}
	return false;
}

int main(int argc, char *argv[]) {
	int node_n, edge_n, market_n;
	cin >> node_n >> edge_n >> market_n;

	vector<vector<int>> edge_list(edge_n, vector<int>());
	vector<vector<vector<int>>> adj_list(node_n, vector<vector<int>>());
	vector<int> markets(market_n, 0);
	vector<bool> is_town(node_n, true);

	for (int i = 0; i < market_n; ++i) {
		cin >> markets[i];
		--markets[i];
		is_town[markets[i]] = false;
	}

	int a, b, c;
	for (int i = 0; i < edge_n; ++i) {
		cin >> a >> b >> c;
		--a;--b;
		adj_list[a].push_back({b, c});
		adj_list[b].push_back({a, c});
		edge_list[i] = {c, a, b};
	}

	int closest_town = INF;
	for (int market : markets) {
		for (vector<int> neighbour : adj_list[market]) {
			if (is_town[neighbour[0]]) {
				closest_town = min(closest_town, neighbour[1]);
			}
		}
	}

	
	//cycle_check(adj_list, 0, 0, vector<bool>(node_n, false))
	/* 
	 * sort edge list by weight
	 * for edge in edge list, add to second adj list, check second adj list for cycles
	 *  true - somehow remove??
	 *  false - continue
	 */
	cout << edge_n << endl;
	cout << edge_list.size() << endl;
	for (auto edge = edge_list.begin(); edge != edge_list.end(); ++edge) {
		if (is_town[(*edge)[1]] || is_town[(*edge)[2]]) {
			edge_list.erase(); /////////////////////YEEEEEEETTTTTT
		}
	}
	cout << edge_list.size() << endl;

	sort(edge_list.begin(), edge_list.end(), [](vector<int> a, vector<int> b) {
			return a[0] < b[0];
	});
	cout << endl << endl;
	for(auto r : edge_list) {
		for(auto a : r) {
			cout << a << " ";
		}
		cout << endl;
	}

	return 0;
}

