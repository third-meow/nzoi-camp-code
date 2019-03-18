#include<bits/stdc++.h>
using namespace std;

vector<int> dp_tab;

vector<int> coins = {100, 25, 10, 1};

int solve(int prc) {
	if (dp_tab[prc] != -1) {
		return dp_tab[prc];
	}

	if (prc == 0) {
		return dp_tab[prc] = 0;
	}

	int c_min = INT_MAX;
	for (auto coin : coins) {
		if ((prc - coin) >= 0) {
			c_min = min(c_min, (solve(prc - coin) + 1));
		}
	}
	return dp_tab[prc] = c_min;
} 


int main(int argc, char *argv[]) {
	int price;
	cin >> price;

	for(int i = 0; i < price+1; ++i) dp_tab.push_back(-1);

	cout << solve(price) << endl;

	return 0;
}

