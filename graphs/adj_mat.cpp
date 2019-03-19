#include<bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<vector<int>> adj_mat(n, vector<int>(n, 0));

	int a, b;
	while(true) {
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		adj_mat[a][b] = 1;
	}

	for(auto row : adj_mat) {
		for (auto e : row) {
			cout << e;
		}
		cout << endl;
	}

	return 0;
}

