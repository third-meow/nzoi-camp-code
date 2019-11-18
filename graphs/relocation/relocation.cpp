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

int check_direct(int from, int to) {
	for(int i = 0; i < adj_list[from].size(); ++i) {
		if (adj_list[from][i][0] == to) {
			return adj_list[from][i][1];
		}
	}

	return -1;
}

int dika(int from, int to) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
	vector<int> been(node_n, INF);

	pq.push(make_pair(from, 0));
	while(pq.empty() == false) {
		pair<int, int> n = pq.top(); pq.pop();

		if (been[n.first] <= n.second) continue;
		been[n.first] = n.second;

		if (n.first == to) return n.second;

		for(auto neighbour : adj_list[n.first]) {
			pq.push(make_pair(neighbour[0], neighbour[1]+n.second));
		}
	} return INF;
}


int ts(int pos, vector<int> targets, int goal) {
	sort(targets.begin(), targets.end());
	int score;
	int min_score = INF;
	do {
		score = dika(pos, targets[0]);
		for(int i = 1; i < targets.size(); ++i) {
			int direct = check_direct(targets[i-1], targets[i]);
			if (direct != -1) {
				score += direct;
				continue;
			}
			adj_list[targets[i-1]].push_back({targets[i], dika(targets[i-1], targets[i])});
			score += adj_list[targets[i-1]].back()[1];
		}
		score += dika(targets[targets.size()-1], goal);
		min_score = min(score, min_score);
	} while(next_permutation(targets.begin(), targets.end()));
	return min_score;
}

int main(int argc, char *argv[]) {
	cin >> node_n >> edge_n >> market_n;
	vector<int> istown(node_n, true);

	vector<int> markets(market_n, 0);
	for (int i = 0; i < market_n; ++i){
		cin >> markets[i];
		markets[i]--;
		istown[markets[i]] = false;
	}

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

	int c_min = INF;
	int count = 0;
	for(auto m : markets) {
		for(int i = 0; i < adj_list[m].size(); ++i) {
			if (istown[adj_list[m][i][0]]) {
				cout << "*" << endl;
				c_min = min(c_min, ts(adj_list[m][i][0], markets, adj_list[m][i][0]));
				//cout << ts(i, markets, i) << endl;
			}
		}
	}
	//cout << count << endl;
	cout << endl << c_min << endl;
	//cout << dika(markets[0], markets.back()) << endl;
	//cout << ts(5, markets, 5) << endl;
	

	return 0;
}

