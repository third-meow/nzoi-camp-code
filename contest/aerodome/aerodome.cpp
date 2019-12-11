#include<bits/stdc++.h>
using namespace std;
#define INF 2e10


int main(int argc, char *argv[]) {
	unsigned long desk_n, ppl;
	vector<unsigned long> desk_times;

	ios_base::sync_with_stdio(false);

	

	cin >> desk_n >> ppl;
	vector<unsigned long> desks(desk_n, 0);

	for (unsigned long i = 0; i < desk_n; ++i) {
		unsigned long t;
		cin >> t;
		desk_times.push_back(t);
	}

	while (ppl > 0) {
		unsigned long c_min = INF;
		unsigned long c_min_idx = 99;
		for(unsigned long i = 0; i < desk_n; ++i) {
			desks[i] += desk_times[i];
			if (desks[i] < c_min) {
				c_min = desks[i];
				c_min_idx = i;
			}
			desks[i] -= desk_times[i];
		}
		desks[c_min_idx] += desk_times[c_min_idx];
		ppl--;
	}

	cout << *max_element(desks.begin(), desks.end()) << endl;
	/*
	cout << endl << endl;
	for(auto e : desks) {
		cout << e << " ";
	} cout << endl;
	*/


	return 0;
}

