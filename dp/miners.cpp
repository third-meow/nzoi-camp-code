#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

string food;

map<string, map<int, int>> dp_tab;

int eval_coal(string mine) {
	bool groups[3] = {false, false, false};

	if (mine.size() > 3) {
		for(auto it = mine.end()-3; it < mine.end(); ++it) {
			switch (*it) {
				case 'M':
					groups[0] = true;
					break;
				case 'F':
					groups[1] = true;
					break;
				case 'B':
					groups[2] = true;
					break;
			}
		}
	} else {
		for (auto c : mine) {
			switch (c) {
				case 'M':
					groups[0] = true;
					break;
				case 'F':
					groups[1] = true;
					break;
				case 'B':
					groups[2] = true;
					break;
			}
		}
	}

	int total = 0;
	for (int i = 0; i < 3; ++i) {
		if (groups[i]) total++;
	}
	return total;
}

string comb_ends(string a, string b) {
	string base = "";
	for(auto it = max(a.begin(), a.end()-3); it < a.end(); ++it) {
		base += *it;
	}
	while(base.size() < 3) {
		base += " ";
	}
	for(auto it = max(b.begin(), b.end()-3); it < b.end(); ++it) {
		base += *it;
	}
	while(base.size() < 6) {
		base += " ";
	}
	return base;
}

void last_three(string& in) {
	in[0] = in[in.size()-3];
	in[1] = in[in.size()-2];
	in[2] = in[in.size()-1];
	if (in.size() > 3) {
		in.erase(3, (in.size() - 3));
	}
}

int solve(int pos, string mineA, string mineB) {
	last_three(mineA);
	last_three(mineB);

	if (pos == food.size()) {
		return 0;
	}
	if (dp_tab.count(comb_ends(mineA, mineB)) > 0) {
		if (dp_tab[comb_ends(mineA, mineB)].count(pos) > 0) {
			return dp_tab[comb_ends(mineA, mineB)][pos];
		}
	}

	int opA = solve(pos+1, mineA+food[pos], mineB) + eval_coal(mineA+food[pos]);
	int opB = solve(pos+1, mineA, mineB+food[pos]) + eval_coal(mineB+food[pos]);
	return dp_tab[comb_ends(mineA, mineB)][pos] = max(opA, opB);
}

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	cin >> food;
	cout << solve(0, "", "") << endl;


	

	return 0;
}

