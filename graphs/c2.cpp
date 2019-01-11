#include<bits/stdc++.h>
using namespace std;


int main() {
	int node_n; vector<vector<vector<int>>> adj_list;

	scanf("%d", &node_n);

	for(int i = 0; i < node_n; ++i) {
		adj_list.push_back({});
	}

	int f,t,w;
	while(scanf("%d %d %d", &f, &t, &w) != EOF){
		adj_list[(f-1)].push_back({w, (t-1)});
		adj_list[(t-1)].push_back({w, (f-1)});
	}

	for(auto &neighbourlist : adj_list) {
		sort(neighbourlist.begin(), neighbourlist.end());
		reverse(neighbourlist.begin(), neighbourlist.end());
	}

	vector<int> nodes;
	nodes.push_back(0);

	for(int i = 0; i < adj_list.size(); ++i) {
		for(int j = 0; j < adj_list[i].size(); ++j) {
			if(adj_list[i][j][1] == 0) {
				adj_list[i].erase(adj_list[i].begin()+j);
			}
		}
	}

	int mst_len = 0;

	while(nodes.size() < node_n) {
		int nextmin = 99999;
		int nextnode = -1;

		for(int n : nodes) {
			if(!adj_list[n].empty()) {
				if (adj_list[n].back()[0] < nextmin){
					nextnode = adj_list[n].back()[1];
					nextmin = adj_list[n].back()[0];
				}
			}
		}

		nodes.push_back(nextnode);
		mst_len += nextmin;

		for(int i = 0; i < adj_list.size(); ++i) {
			for(int j = 0; j < adj_list[i].size(); ++j) {
				if(adj_list[i][j][1] == nextnode) {
					adj_list[i].erase(adj_list[i].begin()+j);
				}
			}
		}
	}

	cout << mst_len;

	return 0;
}
