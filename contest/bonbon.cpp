#include<bits/stdc++.h>
using namespace std;

struct Node {
	int dis;
	string val;

	Node() {
		val = "";
		dis = -1;
	}

	Node(string v) {
		val = v;
		dis = -1;
	}
	
	Node(string v, int d) {
		val = v;
		val.shrink_to_fit();
		dis = d;
	}
};

int node_n = 0;
map<string, int> names;
vector<vector<int>> adj_list;
int edge_n;

int get_id(string name) {
	if (names.count(name) == 0) {
		names[name] = node_n;
		node_n++;
		return node_n - 1;
	} else {
		return names[name];
	}
}


int main() {
	cin >> edge_n;

	for(int i = 0; i < edge_n; ++i){
		string to, from;
		int to_id, from_id;
		cin >> from >> to;
		to_id = get_id(to); from_id = get_id(from);

		adj_list.resize(node_n);
		adj_list[from_id].push_back(to_id);
	}

	vector<bool> seen(node_n, false);
	int start = get_id("bonbon");
	int target = get_id("princess");

	queue<vector<int>> q;

	q.push({0, start});

	while(q.empty() == false) {
		//pop first
		vector<int> n = q.front();
		q.pop();
		if (seen[n[1]]) continue;
		seen[n[1]] = true;

		//check neighbours for being target
		if (n[1] == target) {
			cout << n[0] << endl;
			return 0;
		}

		//find neighbours
		for(int neighbour: adj_list[n[1]]) {
			//enqueue neighbours
			q.push({n[0]+1, neighbour});
		}
	}

		cout << "IMPOSSIBLE";
		return 0;

}

