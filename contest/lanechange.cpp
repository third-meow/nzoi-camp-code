#include<bits/stdc++.h>
using namespace std;


vector<vector<long>> tab = {{1}};

int main() {
	ios_base::sync_with_stdio(false);
	long q;
	cin >> q;

	long n, k;
	for(long j = 0; j < q; ++j) {

		cin >> n >> k;
		bool flag = true;
		while(tab.size() <= n) {
			if (flag) cout << "*" << endl;
			flag = false;
			auto working = vector<long>(tab.back().size()+1, 0);

			for(long i = 1; i < tab.back().size(); ++i) {
				working[i-1] += tab.back()[i];
				working[i+1] += tab.back()[i];
			}
			working[1] += tab.back()[0];

			working[0] *= 2;
			tab.push_back(working);
		}

		cout << ((tab[n][k] % 1000000007) * ((long) pow(tab[n][n], -1) % 1000000007)) << endl;
		//cout << (tab[n][k] / tab[n][n]) % 1000000007 << endl;

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
