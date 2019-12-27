#include<bits/stdc++.h>
using namespace std;


vector<vector<uint64_t>> tab = {{1}};

int main() {
	// dont sync with standard io
	ios_base::sync_with_stdio(false);
	
	// test case count
	uint64_t testcase_n;
	cin >> testcase_n;

	uint64_t n, k;
	for(uint64_t j = 0; j < testcase_n; ++j) {
		cin >> n >> k;
		vector<uint64_t> working(1, 0);

		while(tab.size() <= n) {
			fill(working.begin(), working.end(), 0);
			while (working.size() < tab.back().size()+1) {
				working.push_back(0);
			}

			for(uint64_t i = 1; i < tab.back().size(); ++i) {
				working[i-1] += tab.back()[i];
				working[i+1] += tab.back()[i];
			}
			working[1] += tab.back()[0];

			working[0] *= 2;
			tab.push_back(working);
		}

		//cout << ((tab[n][k] % 1000000007) * ((uint64_t) pow(tab[n][n], -1) % 1000000007)) << endl;
		cout << (tab[n][k] / tab[n][n]) % 1000000007 << endl;

		/*
		cout << endl << endl;
		for(auto row : tab) {
			for(auto e : row) {
				cout << e << " ";
			} cout << endl;
		}
		*/
	}


	return 0;
}

