#include<bits/stdc++.h>
using namespace std;
#define INF 2000000

int desk_n, ppl;
vector<int> desk_times;

int main(int argc, char *argv[]) {
	cin >> desk_n >> ppl;

	{
		int t;
		for (int i = 0; i < desk_n; ++i) {
			cin >> t;
			desk_times.push_back(t);
		}
	}

	vector<int> desks(desk_n, 0);
	int c_max = 0;
	while (ppl < 0) {
		int c_min = INF;
		int c_min_idx;
		for(int i = 0; i < desk_n; ++i) {
			desks[i] += desk_times[i];
			if (desks[i] < c_min) {
				c_min = desks[i];
				c_min_idx = i;
			}
			desks[i] -= desk_times[i];
		}
	}

	cout << *max_element(desks.begin(), desks.end()) << endl;


	return 0;
}

