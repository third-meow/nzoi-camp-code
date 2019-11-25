#include<bits/stdc++.h>
#include "Instrumentor.h"
using namespace std; 
#define INF 2000000 

#define PROFILING 1
#if PROFILING
#define PROFILE_THIS() InstrumentationTimer timer##__LINE__(__FUNCTION__)
#else
#define PROFILE_THIS() 
#endif

int market_n, edge_n, node_n;
vector<vector<vector<int>>> adj_list;
vector<vector<vector<int>>> targets_left;
map<vector<int>, int> target_routes;

string pp(vector<int>& list) {
	stringstream ss;
	for(auto i : list) {
		ss << i << " ";
	}
	return ss.str();
}

// check for direct path
int check_direct(int from, int to) {
	PROFILE_THIS();
	for(int i = 0; i < adj_list[from].size(); ++i) {
		if (adj_list[from][i][0] == to) {
			return adj_list[from][i][1];
		}
	}
	return -1;
}

// dijkstra algorithim
int dika(int from, int to) {
	PROFILE_THIS();


	if (check_direct(from, to) != -1) {
		return check_direct(from, to);
	}
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
		if (n.second == to) {
			return n.first;
		}

		// for each neighbouring node, push them to queue
		for(auto neighbour : adj_list[n.second]) {
			// push the neighbour, and current distance + distance to neighbour
			pq.push(make_pair(neighbour[1]+n.first, neighbour[0]));
		}
	} 
	return INF;
}


int ts(vector<int> targets) {
	PROFILE_THIS();
	if (target_routes.count(targets) == 0) {
		int route_len = 0;
		int direct;
		for(int i = 1; i < targets.size(); ++i) {
			int direct = check_direct(targets[i-1], targets[i]);
			if (direct != -1) {
				route_len += direct;
				continue;
			}
			// calc distance from last target to this target
			adj_list[targets[i-1]].push_back({targets[i], dika(targets[i-1], targets[i])});
			// add that distance to route_len
			route_len += adj_list[targets[i-1]].back()[1];
			//route_len += dika(targets[i-1], targets[i]);
		}
		target_routes[targets] = route_len;
	}
	return target_routes[targets];
}

// try all routes, begining with pos, passing all targets, and ending at goal
int score_posgoal(int pos, vector<int> targets, int goal) {
	PROFILE_THIS();
	// track min distance
	int min_score = INF;
	// sort targets
	sort(targets.begin(), targets.end());
	// for every permutation of targets
	do {
		// use ts to calc route length through targets
		int score = ts(targets);
		// add distance from pos to first target
		score += dika(pos, targets[0]);
		// finally calc distance from last target to goal node
		score += dika(targets[targets.size()-1], goal);

		// if score is smaller than min, it becomes min 
		min_score = min(score, min_score);
	} while(next_permutation(targets.begin(), targets.end()));

	// return shorted route score
	return min_score;
}

int main(int argc, char *argv[]) {
	Instrumentor::Get().BeginSession("results");
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

	vector<bool> tried(node_n, false);

	// for each market town
	for(auto m : markets) {
		// take it's neighbours
		for(int i = 0; i < adj_list[m].size(); ++i) {
			// as long as they're not markets themselves
			if (istown[adj_list[m][i][0]] && !tried[adj_list[m][i][0]]) {
				//cout << "*" << endl;
				// use brute-force-traveling-salesman
				++count;
				c_min = min(c_min, score_posgoal(adj_list[m][i][0], markets, adj_list[m][i][0]));
				tried[adj_list[m][i][0]] = true;
			}
		}
	}

	//cout << count << endl;
	cout << c_min << endl;
	

	Instrumentor::Get().EndSession();
	return 0;
}

