#include<bits/stdc++.h>
using namespace std; 
#define INF 2000000 
int market_n, edge_n, node_n;
vector<vector<vector<int>>> adj_list;
vector<vector<vector<int>>> targets_left;

string pp(vector<int>& list) {
	stringstream ss;
	for(auto i : list) {
		ss << i << " ";
	}
	return ss.str();
}

// check for direct path
int check_direct(int from, int to) {
	for(int i = 0; i < adj_list[from].size(); ++i) {
		if (adj_list[from][i][0] == to) {
			return adj_list[from][i][1];
		}
	}
	return -1;
}

// dijkstra algorithim
int dika(int from, int to) {
	// priority queue
	priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
	vector<int> been(node_n, INF);

	// push starting node
	pq.push(make_pair(0, from));
	while(pq.empty() == false) {
		// get next node
		pair<int, int> n = pq.top(); 
		pq.pop();

		// if node already processed, continue, unless it's distance now is < last time 
		if (been[n.second] <= n.first) continue;
		been[n.second] = n.first;

		// if reached goal node, return distance
		if (n.second == to) 
			return n.first;

		// for each neighbouring node, push them to queue
		for(auto neighbour : adj_list[n.second]) {
			// push the neighbour, and current distance + distance to neighbour
			pq.push(make_pair(neighbour[1]+n.first, neighbour[0]));
		}
	} return INF;
}


// try all routes, begining with pos, passing all targets, and ending at goal
int ts(int pos, vector<int> targets, int goal) {
	// sort targets
	sort(targets.begin(), targets.end());

	// track min distance
	int min_score = INF;
	// for every permutation of targets
	do {
		// score starts as just distance from pos to first target
		int score = dika(pos, targets[0]);
		for(int i = 1; i < targets.size(); ++i) {
			int direct = check_direct(targets[i-1], targets[i]);
			if (direct != -1) {
				score += direct;
				continue;
			}
			// calc distance from last target to this target
			adj_list[targets[i-1]].push_back({targets[i], dika(targets[i-1], targets[i])});
			// add that distance to score
			score += adj_list[targets[i-1]].back()[1];
		}
		// finally calc distance from last target to goal node
		score += dika(targets[targets.size()-1], goal);
		// if score is smaller than min, it becomes min 
		min_score = min(score, min_score);
	} while(next_permutation(targets.begin(), targets.end()));
	
	// return shorted route score
	return min_score;
}

int main(int argc, char *argv[]) {
	/*
	 *  input
	 */
	cin >> node_n >> edge_n >> market_n;
	vector<int> istown(node_n, true);

	// markets
	vector<int> markets(market_n, 0);
	for (int i = 0; i < market_n; ++i){
		cin >> markets[i];
		markets[i]--;
		istown[markets[i]] = false;
	}

	// edges
	adj_list.assign(node_n, vector<vector<int>>());
	targets_left.assign(node_n, vector<vector<int>>());
	int a, b, c;
	for(int i = 0; i < edge_n; ++i) {
		cin >> a >> b >> c;
		b--;
		a--;
		adj_list[a].push_back({b, c});
		adj_list[b].push_back({a, c});
	}

	/*
	 * algorithm
	 */
	// track minimum
	int c_min = INF;
	// count number of start/end nodes
	int count = 0;

	// for each market town
	for(auto m : markets) {
		// take it's neighbours
		for(int i = 0; i < adj_list[m].size(); ++i) {
			// as long as they're not markets themselves
			if (istown[adj_list[m][i][0]]) {
				cout << "*" << endl;
				++count;
				// use brute-force-traveling-salesman
				c_min = min(c_min, ts(adj_list[m][i][0], markets, adj_list[m][i][0]));
			}
		}
	}

	cout << count << endl;
	cout << endl << c_min << endl;
	

	return 0;
}

