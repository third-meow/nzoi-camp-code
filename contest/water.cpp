#include<bits/stdc++.h>
using namespace std;

void topsort_util(vector<vector<int>>& adj_list, int node, stack<int>& sk, vector<bool>& been) {
	if (been[node]) return;

	if (adj_list.size() <= node) {
		sk.push(node);
		return;
	}

	been[node] = true;

	for (int neighbour : adj_list[node]) {
		topsort_util(adj_list, neighbour, sk, been);
	}

	sk.push(node);
}

stack<int> topsort(vector<vector<int>>& adj_list) {
	stack<int> sorted;
	vector<bool> been(adj_list.size(), false);
	for(int i = 0; i < adj_list.size(); ++i) {
		topsort_util(adj_list, i, sorted, been);
	}

	return sorted;
}



int main(int argc, char *argv[]) {

	int fork_n, end_n;
	cin >> fork_n >> end_n;

	vector<vector<int>> adj_list(fork_n, vector<int>());

	int to, from;
	for (int i = 0; i < fork_n; ++i) {
		cin >> from >> to;
		// zero base
		--from;
		--to;

		adj_list[i].push_back(to);
		adj_list[i].push_back(from);
	}

	stack<int> orderToProcess = topsort(adj_list);

	vector<double> flows(fork_n + end_n, 0);
	flows[0] = 1.;

	while(!orderToProcess.empty()) {
		int node = orderToProcess.top();
		orderToProcess.pop();
		if (node >= fork_n) continue;
		flows[adj_list[node][0]] += flows[node] / 2;
		flows[adj_list[node][1]] += flows[node] / 2;
	}
	
	for(int i = fork_n; i < fork_n + end_n; ++i) {
		cout << flows[i] << endl;
	}


	return 0;
}

