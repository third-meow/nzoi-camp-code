#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<vector<int>>> mat3d;
typedef vector<vector<int>> mat2d;

mat3d adj_list;
vector<int> popu;
int node_n, edge_n;

int bestPath(int node, vector<bool>& taken) {
	//update taken list for passing to children
	vector<bool> new_taken = taken;
	new_taken[node] = true;

	//loop through neighbours
	int activeNeighbours = 0;
	vector<int> options;
	for (auto neighbour : ajd_list[node]) {
		//if not already taken
		if (!taken[neighbour[0]]) {
			//count active neighbours
			++activeNeighbours;

			//recursivly call bestPath, with neighbour node, and new_taken data
			options.push_back(neighbour[1] + bestPath(neighbour[0], new_taken));
		}
	}

	//if no active neighbours (end node), return node population
	if (activeNeighbours == 0) {
		return popu[node];
	}

	//combine options
		/*
		 * ======================================================================
		 * optionScores format:
		 *                            score (ie max ppl)
		 *	Index(crsps to option)  /
		 *	|                      /
		 *	|    _-----------------
		 *  |   /       _------------------- list of other option combos
		 *	v  /       /
		 *	1 sc <..........>
		 *	2 sc
		 *	3 sc
		 *	4 sc
		 *	5 sc
		 *	6 sc
		 *  7 sc
		 * ======================================================================
		 */
	mat2d optionScores;

	for (int option : options) {










	}














}

int main(int argc, char *argv[]) {
	cin >> node_n >> edge_n;
	adj_list = mat3d(node_n, mat2d());
	popu = mat2d(node_n, 0);


	for(int i = 0; i < node_n; ++i) {
		cin >> popu[i];
	}

	int a, b, c;
	for(int i = 0; i < edge_n; ++i) {
		cin >> a >> b >> c;
		adj_list[a].push_back({b, c});
		adj_list[b].push_back({a, c});
	}

	cout << bestPath(0, vector<bool>(node_n, 0)) << endl;

	return 0;
}

