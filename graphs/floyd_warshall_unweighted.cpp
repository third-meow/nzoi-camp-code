#include<bits/stdc++.h>
using namespace std;

void floyd_warshall_unweighted(vector<vector<bool>>& mat) {
	if (mat.size() != mat[0].size()) {
		cout << "mat must have regular dimesions, ie: mat.size() must equal mat[0].size()" << endl;
	}

	int len = mat.size();
	for (int k = 0; k < len; ++k) {
		for (int i = 0; i < len; ++i) {
			for (int j = 0; j < len; ++j) {
				mat[i][j] = (mat[i][j] || (mat[i][k] && mat[k][j]));
			}
		}
	}
}

int main(int argc, char *argv[]) {
	
	int n;
	cin >> n;

	vector<vector<bool>> adj_mat(n, vector<bool>(n, false));
	int a, b;
	while(cin >> a >> b) {
		adj_mat[a][b] = true;
		adj_mat[b][a] = true;
	}


	for(auto row : adj_mat) {
		for (auto e : row) {
			cout << e << " ";
		}
		cout << endl;
	}

	floyd_warshall_unweighted(adj_mat);
	cout << endl << endl;

	for(auto row : adj_mat) {
		for (auto e : row) {
			cout << e << " ";
		}
		cout << endl;
	}


	


	return 0;
}

