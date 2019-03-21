#include<bits/stdc++.h>
using namespace std;

string a, b;
vector<vector<int>> dptab;

int solve(int apos, int bpos) {
	// base case, one or both strings	are empty. return 0
	if (apos == -1 || bpos == -1) 
		return 0;

	// check dptab
	if (dptab[apos][bpos] != -1) 
		return dptab[apos][bpos];

	// if last chars are the same
	if (a[apos] == b[bpos])
		return dptab[apos][bpos] = solve(apos-1, bpos-1) + 1;

	// pick best option
	int remove_from_a = solve(apos-1, bpos);
	int remove_from_b = solve(apos, bpos-1);
	return dptab[apos][bpos] = max(remove_from_a, remove_from_b);
}

int main(int argc, char *argv[]) {
	getline(cin, a);
	getline(cin, b);

	dptab = vector<vector<int>>(a.size(), vector<int>(b.size(), -1));

	cout << solve(a.size() - 1, b.size() - 1) << endl;

	return 0;
}

