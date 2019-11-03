#include<bits/stdc++.h>
using namespace std;
#define INF 2000000


vector<vector<vector<int>>> adj_list;

int cycle_check(int start, int node_n) {
	int best = 1;
	//cout << adj_list[2].size() << endl;
	vector<int> been(node_n,	INF);
	queue<vector<int>> q;
	for(vector<int> neighbour : adj_list[start]) {
		q.push({neighbour[0], neighbour[1]});
	}
	while(q.empty() == false) {
		cout << "yeet" << endl;
		int node = q.front()[0];
		int time = q.front()[1];
		q.pop();
		if (been[node] < time) continue;
		been[node] = time;
		//cout << node << "\t" << time << "\t" << adj_list[node].size() << endl;
		if (node == start) {
			best = min(time, best);
			if (best < 0) return best;
		}
		for(vector<int> neighbour : adj_list[node]) {
			q.push({neighbour[0], neighbour[1]+time});
		}
		//cout << endl;
	}
	return best;
}

int take_case() {
	int  node_n, edge_n;
	cin >> node_n >> edge_n;
	adj_list = vector<vector<vector<int>>>(node_n, vector<vector<int>>());

	int from, to, time_dif;
	for(int i = 0; i < edge_n; ++i) {
		cin >> from >> to >> time_dif;
		adj_list[from].push_back({to, time_dif});
	}

	vector<bool> been(node_n, false);
	queue<int> q;
	q.push(0);
	while(q.empty() == false) {
		int node = q.front();
		q.pop();
		if (been[node]) continue;
		been[node] = true;
		if (cycle_check(node, node_n) < 0) {
			cout << "possible" << endl;
			return 0;
		}
		for(vector<int> neighbour : adj_list[node]) {
			q.push(neighbour[0]);
		} 
	} 
	cout << "not possible" << endl; 
	return 0;
}

int main(int argc, char *argv[]) {
	int testcase_n;
	cin >> testcase_n;
	for(int j = 0; j < testcase_n; ++j) {
		take_case();
	}
	return 0;
}
