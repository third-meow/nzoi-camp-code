#include<bits/stdc++.h>
using namespace std;


vector<vector<double>> tab = {{1.0}};

int main() {
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;

	int n, k;
	for(int j = 0; j < q; ++j) {

		cin >> n >> k;
		while(tab.size() <= n) {
			vector<double> working(tab.back().size()+1, 0.0);

			for(int i = 1; i < tab.back().size()-1; ++i) {
				double a = tab.back()[i-1] * 2;
				double b = tab.back()[i+1] * 2;
				working[i] = (a * b) / (a + b);
			}

			if (tab.back().size() > 1) {
				working[0] = tab.back()[1];
			} else {
				working[0] = 0;
			}

			working.back() = tab.back().back() * 2;

			tab.push_back(working);
		}

		double div = tab[n][n] / tab[n][k];
		long ldiv = (long) div;

		if ((((long)(div * 1000)) % 1000) > 500) {
			ldiv += 1;
		}
		cout << ldiv % 1000000007 << endl;

		/*
		for(auto row : tab) {
			for(auto e : row) {
				cout << e << " ";
			} cout << endl;
		}
		*/
		
	}


	return 0;
}
