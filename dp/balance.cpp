#include<bits/stdc++.h>
using namespace std;

vector<int> luggage;

vector<vector<array<int, 2>>> dp_tab;
int n;

int abs(int x) {
	if (x < 0) return -x;
	else return x;
}

//*******************************
//			DATA STUCT EXPLANINED
//		|						|						|
//		| plane a   | plane b   |
//		|	weight	  | weight		|
//*******************************

array<int, 2> solve(int pos, int plane_a, int plane_b) {
	// if dp table already has result
	if (dp_tab[pos][plane_a][0] != -1) {
		return dp_tab[pos][plane_a];
	}

	if (dp_tab[pos][plane_b][0] != -1) {
		return dp_tab[pos][plane_b];			// MIGHT NEED TO SWAP PLACES
	}

	// if no more luggage
	if (pos == n) {
		//return what we've got
		dp_tab[pos][plane_a] = {plane_a, plane_b};
		dp_tab[pos][plane_b] = {plane_b, plane_a};
		return dp_tab[pos][plane_a];
	}

	
	// base case
	// compare loading luggage on plane a vs on plane b.
	//		which gives best balence ?
	array<int, 2> op_a = solve(pos+1, plane_a + luggage[pos], plane_b);
	array<int, 2> op_b = solve(pos+1, plane_a, plane_b + luggage[pos]);

	if (abs(op_a[0] - op_a[1]) < abs(op_b[0] - op_b[1])) {
		dp_tab[pos][plane_a] = op_a;
		dp_tab[pos][plane_b] = op_a;
	} else {
		dp_tab[pos][plane_a] = op_b;
		dp_tab[pos][plane_b] = op_b;
	}

	return dp_tab[pos][plane_a];
}

int main(int argc, char *argv[]) {
	cin >> n;
	luggage.reserve(n);
	
	int lug_sum = 0;
	for(int i = 0; i < n; ++i){
		cin >> luggage[i];
		lug_sum += luggage[i];
	}

	lug_sum++;

	dp_tab = vector<vector<array<int, 2>>>(n+1, vector<array<int, 2>>(lug_sum, array<int, 2>{ {-1, -1} }));

	array<int, 2> res = solve(0, 0, 0);

	
	cout << min(res[0], res[1]) << " " << max(res[0], res[1]) << endl;

	return 0;
}

