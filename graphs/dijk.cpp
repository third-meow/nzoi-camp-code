#include<bits/stdc++.h>
using namespace std;

struct Node {
	int id;
	int dis;

	Node(){
		id = -1;
		dis = -1;
	}

	Node(int i, int d) {
		id = i;
		dis = d;
	}

};

struct compNodes {
	bool operator()(const Node& a, const Node& b) {
		return a.dis > b.dis;
	}
};

vector<vector<vector<int>>> adj_list;
int node_n, edge_n, start;

void dijk(int target) {
	if(node_n == 0 || edge_n == 0) {
		cout << -1 << endl;
		return;
	}

	bool seen[node_n];
	for(int i = 0; i < node_n; ++i)
		seen[i] = false;

	priority_queue<Node, vector<Node>, compNodes> pq;
	pq.push(Node(start, 0));

	while(true) {
		if (pq.empty()) {
			cout << -1 << endl;
			return;
		}
		// pop from pq
		Node n;
		do{
			if(pq.empty()) {
				cout << -1 << endl;
				return;
			}
			n = pq.top();
			pq.pop();
		} while(seen[n.id] == true);
		seen[n.id] = true;

		if(n.id == target) {
			cout << n.dis << endl;
			return;
		}

		// loop through neighbourghbours
		for(auto neighbour : adj_list[n.id]) {
			// push to pq
			if(seen[neighbour[0]] == false)
				pq.push(Node(neighbour[0], (n.dis+neighbour[1])));
		}
	}
}


int main() {
	vector<int> targets;

	cin >> node_n >> edge_n;
	if(node_n != 0 && edge_n != 0) {
		cin >> start;
	}


	for(int i = 0; i < node_n; ++i)
		adj_list.push_back({});

	for(int i = 0; i < edge_n; ++i){
		int f;
		vector<int> tw(2, -1);
		scanf("%d %d %d", &f, &tw[0], &tw[1]);
		adj_list[f].push_back(tw);
	}

	int tempTarget;
	while(scanf("%d", &tempTarget) != EOF)
		targets.push_back(tempTarget);

	for(int j = 0; j < targets.size(); ++j)
		dijk(targets[j]);


	return 0;
}

