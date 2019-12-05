#include<bits/stdc++.h>
using namespace std;
#define INF 2000000

vector<int> dptab;

int solve(int kgs) {
	if (kgs == 0) return 0;
	if (kgs < 0) return INF;
	
	if (dptab[kgs] != -1) return dptab[kgs];
	
	int op3 = solve(kgs - 3);
	int op5 = solve(kgs - 5);

	return dptab[kgs] = min(op3, op5) + 1;
}

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	dptab = vector<int>(n+1, -1);
	int res = solve(n);
	if (res >= INF) {
		cout << -1 << endl;
	} else {
		cout << res << endl;
	}
	return 0;
}

