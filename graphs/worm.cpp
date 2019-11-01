#include<bits/stdc++.h>
using namespace std;
#define INF 2000000

vector<vector<vector<int>>> adj_list;

bool solve(int pos, vector<pair<bool, int>> been, int time) {
	been[pos] = make_pair(true, time);
	for (vector<int> neighbour : adj_list[pos]) {
		if (been[neighbour[0]].first) {
			if ((time + neighbour[1] - been[neighbour[0]].second) < 0) {
				/*
				cout << "time - been(neighbour) is smaller than 0" << endl;
				cout << "pos: " << pos << endl;
				cout << "neighbour: " << neighbour[0] << endl;
				cout << "been[neighbour]: " << been[neighbour[0]].second << endl;
				cout << "time: " << time << endl;
				*/
				return true;
			}
		} else if (solve(neighbour[0], been, time+neighbour[1])) {
			return true;
		}
	}
	return false;
}

int main(int argc, char *argv[]) {
	int testcase_n;
	cin >> testcase_n;
	for(int j = 0; j < testcase_n; ++j) {
		int  node_n, edge_n;
		cin >> node_n >> edge_n;
		adj_list = vector<vector<vector<int>>>(node_n, vector<vector<int>>());

		{
			int from, to, time_dif;
			for(int i = 0; i < edge_n; ++i) {
				cin >> from >> to >> time_dif;
				adj_list[from].push_back({to, time_dif});
			}
		}

		vector<pair<bool, int>> been(node_n, make_pair(false, 0));
		int n = 0;
		int time = 0;

		if (solve(0, been, 0)) {
			cout << "posssible" << endl;
		} else {
			cout << "not possible" << endl;
		}
	}

	return 0;
}
