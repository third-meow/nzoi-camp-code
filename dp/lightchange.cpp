#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

long long dp_count = 0;
long long the_count = 0;
vi coins = {100, 25, 10, 1};
vi dp_tab;

int solve(int prc) {
	++the_count;
	if (dp_tab[prc] != -1) {
		++dp_count;
		return dp_tab[prc];
	}
	if (prc == 0) {
		return dp_tab[0] = 0;
	}

	int best = INT_MAX;
	for (int i = 0; i < 4; ++i) {
		int coin = coins[i];
		int remain = prc - coin;
		if (remain >= 0) {
			best = min(best, solve(remain));
		}
	}

	return dp_tab[prc] = best + 1;
} 


int main(int argc, char *argv[]) {
	int price;
	cin >> price;

	dp_tab = vi(price+1, -1);

	cout << solve(price) << endl;
	cout << dp_count << " " << the_count << endl;
	cout << (float) dp_count / the_count << "%" << endl;

	return 0;
}

