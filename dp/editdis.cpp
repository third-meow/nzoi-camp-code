#include<bits/stdc++.h>
using namespace std;

string a, b;
vector<vector<int>> dptab;

int solve(int apos, int bpos) {
	// base case, one or both strings	are empty. return 0
	if (apos == -1 || bpos == -1) {
		//cout << endl;
		//cout << apos << " " << bpos << endl;
		//cout << (max(apos, bpos) >= 0 ? max(apos, bpos) + 1 : 0) << endl;
		return max(apos, bpos) >= 0 ? max(apos, bpos) + 1 : 0;

	}

	// if dptab alread has answer
	if (dptab[apos][bpos] != -1)
		return dptab[apos][bpos];


	// if last chars are the same
	if (a[apos] == b[bpos])
		return dptab[apos][bpos] = solve(apos-1, bpos-1);

	// remove from a
	int remove_from_a = solve(apos-1, bpos) + 1;
	// remove from b
	int remove_from_b = solve(apos, bpos-1) + 1;
	// x out
	int x_out = solve(apos-1, bpos-1) + 1;

	// pick best option
	return dptab[apos][bpos] = min(x_out, min(remove_from_a, remove_from_b));
}

int main(int argc, char *argv[]) {
	getline(cin, a);
	getline(cin, b);

	dptab = vector<vector<int>>(a.size(), vector<int>(b.size(), -1));

	cout << solve(a.size() - 1, b.size() - 1) << endl;

	return 0;
}

