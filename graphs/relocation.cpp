#include<bits/stdc++.h>
using namespace std;
#define INF 2000000

int main(int argc, char *argv[]) {
	int node_n, edge_n, market_n;
	cin >> node_n >> edge_n >> market_n;

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
	}

	int closest_town = INF;
	for (int market : markets) {
		for (vector<int> neighbour : adj_list[market]) {
			if (is_town[neighbour[0]]) {
				closest_town = min(closest_town, neighbour[1]);
			}
		}
	}

	cout << closest_town << endl;





	

	return 0;
}

