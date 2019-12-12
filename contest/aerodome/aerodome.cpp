#include<bits/stdc++.h>
using namespace std;
#define INF 2e10
#define ulong unsigned long


int main(int argc, char *argv[]) {
	ulong desk_n, ppl;
	vector<ulong> desk_times;

	ios_base::sync_with_stdio(false);

	

	cin >> desk_n >> ppl;

	vector<array<ulong, 2>> desks(desk_n, {0, 0});

	for (ulong i = 0; i < desk_n; ++i) {
		cin >> desks[i][0];
		desks[i][1] = desks[i][0];
	}


	while(ppl > 0) {
		--ppl;
		sort(desks.begin(), desks.end());
		desks[0][0] += desks[0][1];
	}

	for(int i = 0; i < desk_n; ++i) {
		desks[i][0] -= desks[i][1];
		desks[i][1] = 0;
	}


	cout << (*max_element(desks.begin(), desks.end()))[0] << endl;

	/*
	cout << endl << endl;
	for(auto e : desks) {
		cout << e[0] << "-" << e[1] << "  ";
	} cout << endl;
	*/


	return 0;
}

