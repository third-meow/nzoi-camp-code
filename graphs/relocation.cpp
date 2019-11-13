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

	
	/* 
	 * sort edge list by weight
	 * for edge in edge list, add to second adj list, check second adj list for cycles
	 *  true - somehow remove??
	 *  false - continue
	 */

	// remove non market-market edges
	bool done_flag;
	do {
		done_flag = true;
		for (int i = 0; i < edge_list.size(); ++i) {
			if (is_town[edge_list[i][1]] || is_town[edge_list[i][2]]) {
				edge_list.erase(edge_list.begin()+i);
				done_flag = false;
			}
		}
	} while (done_flag == false);


	// sort edge list in aceding order of weight
	sort(edge_list.begin(), edge_list.end(), [](vector<int> a, vector<int> b) {
			return a[0] < b[0];
	});

	int min_span_tree = 0;
	vector<vector<vector<int>>> min_span_adj_list(node_n, vector<vector<int>>());
	for(auto edge : edge_list) {
		min_span_adj_list[edge[1]].push_back({edge[2], edge[0]});
		min_span_adj_list[edge[2]].push_back({edge[1], edge[0]});
		if (cycle_check(min_span_adj_list, edge[1], edge[1], vector<bool>(node_n, false))) {
			min_span_adj_list[edge[1]].pop_back();
			min_span_adj_list[edge[2]].pop_back();
		} else {
			min_span_tree += edge[0];
		}
	}



	cout << (closest_town + min_span_tree) * 2 << endl;


	return 0;
}






































































