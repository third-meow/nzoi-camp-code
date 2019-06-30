#include<bits/stdc++.h>
using namespace std;

int desk_n, ppl;

// Combo and format functions from user7781254 on stackoverflow
// link: https://stackoverflow.com/questions/12991758/creating-all-possible-k-combinations-of-n-items-in-c
// Atapted by third-meow

vector<int> format(const vector<int> c, int combo) {
	vector<int> out;
	int n = c.size();
	for (int i = 0; i < n; ++i) {
		if ((combo >> i) & 1)
			out.push_back(c[i]);
	}
	return out;
}

vector<vector<int>> combo(const vector<int>& c, int k) {
	vector<vector<int>> out;
	int n = c.size();
	int combo = (1 << k) - 1;       // k bit sets
	while (combo < 1<<n) {

		out.push_back(format(c, combo));

		int x = combo & -combo;
		int y = combo + x;
		int z = (combo & ~y);
		combo = z / x;
		combo >>= 1;
		combo |= y;
	}

	return out;
}

int total(iterator begin, iterator end) {
	int total;
	while (begin < end) {
		total += &begin;
		begin++;
	}
	return total;
}

void pp(vector<int>& v) {
	for (auto a : v) {
		cout << a << " ";
	}
	cout << endl;
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

	vector<vector<int>> options = combo(open, 1);
	for(int i = 2; i < open.size(); ++i) {
		auto cmb = combo(open, i);
		options.insert(options.end(), cmb.begin(), cmb.end());
	}

	for(auto op : options) {
		pp(op);
	}

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

