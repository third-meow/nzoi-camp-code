#include<bits/stdc++.h>
using namespace std;

long cut_at(vector<long>& trees, long height) {
	long total = 0;
	for (auto t : trees) {
		total += (t - height) > 0 ? (t - height) : 0;
	}
	return total;
}

int main(int argc, char *argv[]) {
	long tree_n, wood;
	cin >> tree_n >> wood;
	vector<long> trees(tree_n, 0);
	long highest = 0;

	for(long i = 0; i < tree_n; ++i) {
		cin >> trees[i];
		if (trees[i] > highest) highest = trees[i];
	}

	long low, high, mid;
	low = 0;
	high = highest;
	while (true) {
		mid = (int) (high + low) / 2;
		//cout << mid << endl;

		long upone = cut_at(trees, mid+1);
		long res = cut_at(trees, mid);

		if ((upone > wood && res <= wood) || res == wood) {
			cout << mid << endl;
			return 0;
		}

		if (res > wood) {
			low = mid;
		}
		if (res < wood) {
			high = mid;
		}
	}

	

	return 0;
}

