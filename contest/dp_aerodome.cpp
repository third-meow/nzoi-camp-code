#include<bits/stdc++.h>
using namespace std;

int desk_n, ppl;

int total(iterator begin, iterator end) {
	int total;
	while (begin < end) {
		total += &begin;
		begin++;
	}
	return total;
}


int solve(int remain, vector<int> desk_status) {
	// Decrement all desk statuses
	for(auto &&ds : desk_status) --ds;
	
	// If no one left in queue
	if (remain == 0)
		return total(desk_status.begin(), desk_status.end()); //0;

	vector<int> open(desk_n);
	for(int i = 0; i < desk_n; ++i) {
		if (desk_status[i] == 0) {
			open.push_back(i);
		}
	}
	vector<vector<int>> options = combo(open);

	//options.push_back(solve(r
	










	return min(opA, opB);
}

int main(int argc, char *argv[]) {
	cin >> desk_n >> ppl;

	vector<int> desks;
	{
		int t;
		for (int i = 0; i < desk_n; ++i) {
			cin >> t;
			desks.push_back(t);
		}
	}


	return 0;
}

