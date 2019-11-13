#include<bits/stdc++.h>
using namespace std; 
#define INF 2000000 
vector<vector<vector<int>>> adj_list;
vector<vector<vector<int>>> targets_left;

string pp(vector<int>& list) {
	stringstream ss;
	for(auto i : list) {
		ss << i << " ";
	}
	return ss.str();
}


int ts(int pos, vector<int> targets, int goal) {
	// if weve reached the goal and have 0 targets, return 0
	if (pos == goal && targets.size() == 0) {
		cout << 0 << endl;
		return 0;
	}
	
	// if weve been here before, and had less targets
	if (find(targets_left[pos].begin(), targets_left[pos].end(),targets) != targets_left[pos].end()) 
		return INF;

	targets_left[pos].push_back(targets);
	// data dump
	//cout << endl << endl;
	//cout << "pos: " << pos << endl;
	//cout << "targets: " << pp(targets) << endl;
	//cout << "targets left : " << pp(targets_left[pos]) << endl;


	// if weve reached a target, erase it from vector
	auto it = find(targets.begin(), targets.end(), pos);
	if (it != targets.end()) targets.erase(it);

	int c_min = INF;
	for(vector<int> neighbour : adj_list[pos]) {
		c_min = min(ts(neighbour[0], targets, goal) + neighbour[1], c_min);
	}
	cout << c_min << endl;
	return c_min;
}

int main(int argc, char *argv[]) {
	int market_n, edge_n, node_n;
	cin >> node_n >> edge_n >> market_n;

	vector<int> markets(market_n, 0);
	for (int i = 0; i < market_n; ++i){
		cin >> markets[i];
		markets[i]--;
	}

	adj_list.assign(node_n, vector<vector<int>>());
	targets_left.assign(node_n, vector<vector<int>>());
	int a, b, c;
	for(int i = 0; i < edge_n; ++i) {
		cin >> a >> b >> c;
		c--;
		b--;
		a--;
		adj_list[a].push_back({b, c});
		adj_list[b].push_back({a, c});
	}

	cout << ts(4, {0, 1, 2}, 4) << endl;
	

	return 0;
}

