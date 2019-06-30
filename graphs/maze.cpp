#include<bits/stdc++.h>
using namespace std;

int node_n;
vector<vector<int>> edges;

void vec_print(vector<int>& vec) {
	for (int v : vec) {
		cout << v << " ";
	}
}

void bsf() {
	int count = 0;
	vector<bool> been(node_n, false);
	vector<vector<int>> path_to(node_n);
	queue<int> q;

	q.push(0);
	path_to[0] = {0};

	while (!q.empty()) {
		++count;

		int n = q.front(); q.pop();
		if (been[n]) continue;
		else been[n] = true;

		if (n == node_n-1) {
			vec_print(path_to[n]);
			return;
		}

		for (auto edge : edges) {
			// check edge for current node, if so, set neighbour to the other side of edge
			int neighbour = -1;
			if (edge[0] == n) neighbour = edge[1];
			if (edge[1] == n) neighbour = edge[0];

			// if neighbour has been set
			if (neighbour != -1) {
				// if path to here (+1) is shorter than neighbour's current path
				// or path length is 0 (hasnt been set)
				if ((path_to[neighbour].size() > (path_to[n].size() + 1)) 
						|| (path_to[neighbour].size() == 0) ) {
					// update neighbour's path
					path_to[neighbour] = path_to[n];
					path_to[neighbour].push_back(neighbour);
				}

				q.push(neighbour);
			}
		}
	}

	cout << "not found" << endl;
}





int main(int argc, char *argv[]) {

	cin >> node_n;
	int a, b;
	while (cin >> a >> b) {
		edges.push_back({a, b});
	}


	bsf();


	return 0;
}

