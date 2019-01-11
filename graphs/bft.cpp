#include<bits/stdc++.h>
using namespace std;

bool within(vector<int>& vec, int ele) {
	for(auto e : vec)
		if (e == ele)
			return true;
	return false;
}



int main(int argc, char *argv[]) {
	vector<vector<int>> adj_list;
	vector<vector<int>> edges;
	int node_n;
	cin >> node_n;

	string line;
	int a,b;
	getline(cin, line); //TRASH FIRST LINE
	while(getline(cin, line)) {
		sscanf(line.data(), "%d %d\n", &a, &b);
		vector<int> edge = {a,b};
		edges.push_back(edge);
	}

	for(int i = 0; i < node_n; ++i) {
		vector<int> connected;
		for(int j = 0; j < edges.size(); ++j) {
			if (edges[j][0] == i)
				connected.push_back(edges[j][1]);
			else if(edges[j][1] == i)
				connected.push_back(edges[j][0]);

		}

		sort(connected.begin(), connected.end());
		for(int o = 1; o < connected.size(); ++o) {
			if (connected[o] == connected[o-1])
				connected.erase(connected.begin() + o);
		}
		
		adj_list.push_back(connected);
	}

	vector<int> been;
	queue<int> togo;
	togo.push(0);
	int here;
	while(!togo.empty()) {
		//find next unseen node from stack
		while(true) {
			if(togo.empty())
				return 0;
			if(within(been, togo.front()))
				togo.pop();
			else {
				here = togo.front();
				break;
			}
		}

		if(togo.empty())
			break;

		been.push_back(here);

		for(auto c : adj_list[here])
			togo.push(c);
		cout << here << endl;
	}

	return 0;
}
