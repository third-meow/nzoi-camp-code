#include<bits/stdc++.h>
using namespace std;

vector<int> dp_tab(5000, -1);

int solve(int kgs) {
	if (dp_tab[kgs] != -1) return dp_tab[kgs];
	if (kgs < 0) return 4999;

	int op3 = solve(kgs - 3);
	int op5 = solve(kgs - 5);

	dp_tab[kgs] = min(op3, op5) + 1;
	return dp_tab[kgs];
}

int main(int argc, char *argv[]) {
	dp_tab[0] = 0;
	dp_tab[1] = 4999;
	dp_tab[2] = 4999;
	dp_tab[3] = 1;

	int n;
	cin >> n;

	int aws = solve(n);

	cout << (aws >= 4999 ? -1 : aws) << endl;
	return 0;
}
