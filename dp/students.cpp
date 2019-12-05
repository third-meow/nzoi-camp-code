#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dptab;

int solve(int n, int r) {
	if (n == r) return 1;
	if (r == 1) return n;
	if (dptab[n][r] != -1) return dptab[n][r];

	return dptab[n][r] = (solve(n-1, r-1) + solve(n-1, r)) % (int) 1e5;
}

int main(int argc, char *argv[]) {

	int n, r;
	cin >> n >> r;
	dptab = vector<vector<int>>(n+1, vector<int>(r+1, -1));
	cout << solve(n, r) << endl;
	

	return 0;
}

