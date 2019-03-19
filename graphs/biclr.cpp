#include<bits/stdc++.h>
using namespace std;

int op(int i) {
	if (i == 0) return 1;
	else if (i == 1) return 0;
	else {
		cout << "OP FUNC BEING USED ON -1 !!" << endl;
		return -1;
	}
}

int solve() {
	int n, edge_n;
	cin >> n;
	if (n == 0) return 1;
	cin >> edge_n;
	vector<vector<int>> adj_list(n, vector<int>());
	vector<int> clrs(n, -1);

	int a, b;
	for(int i = 0; i < edge_n; ++i) {
		cin >> a >> b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}

	clrs[0] = 0;
	for(int i = 0; i < adj_list.size(); ++i) {
		for(int j = 0; j < adj_list[i].size(); ++j) {
			if (clrs[adj_list[i][j]] == clrs[i]) {
				cout << "NOT BICOLORABLE." << endl;
				return 0;
			}
			else clrs[adj_list[i][j]] = op(clrs[i]);
		}
	}

	cout << "BICOLORABLE." << endl;

	return 0;
}

int main(int argc, char *argv[]) {
	while(solve() != 1) {
		;
	}
	return 0;
}

