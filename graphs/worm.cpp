#include<bits/stdc++.h>
using namespace std;
#define INF 2000000

int main(int argc, char *argv[]) {
	int  node_n, edge_n;
	cin >> node_n >> edge_n;
	vector<vector<vector<int>>> adj_list(node_n, vector<vector<int>>());

	{
		int from, to, time_dif;
		for(int i = 0; i < edge_n; ++i) {
			cin >> from >> to >> time_dif;
			adj_list[from].push_back({to, time_dif});
		}
	}

	vector<bool> been(node_n, false);
	vector<int> beentimes(node_n, 0);
	int n = 0;
	int time = 0;
	while (true) {

		if (been[n]) {
			if (time - beentimes[n] < 0) {
				cout << "posssible" << endl;
				return 0;
			} else {
				cout << "not possible" << endl;
				return 0;
			}
		}
		been[n] = true;
		beentimes[n] = time;

		vector<vector<int>> neighbours = adj_list[n];

		if (neighbours.size() == 0) {
			cout << "not possible" << endl;
			return 0;
		}

		/*
		 * select best neighbour (TODO: should probably try all of them tho)
		 */
		vector<int> best_neighbour = {0, INF};
		for(auto neighbour : neighbours) {
			if (neighbour[1] < best_neighbour[1]) {
				best_neighbour = neighbour;
			}
		}

		n = best_neighbour[0];
		time += best_neighbour[1];
	}
		
	

	return 0;
}

