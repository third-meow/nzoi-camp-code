#include<bits/stdc++.h>
using namespace std;
vector<int> hoops;
vector<vector<int>> dptab;

int solve(int c_height, int pos) {
	// if dptab already contains answer
	if (dptab[c_height][pos] != -1)
		return dptab[c_height][pos]; 

	// if no more hoops
	if (pos == hoops.size()) 
		return 0;

	// calc best option without taking this hoop
	int leave_hoop = solve(c_height, pos + 1);

	// if current height means we cant take hoop at pos
	if (hoops[pos] > c_height) 
		return dptab[c_height][pos] = leave_hoop;

	// calc best option when taking this hoop
	int take_hoop = solve(hoops[pos], pos + 1) + 1;

	// return best option
	return dptab[c_height][pos] = max(take_hoop, leave_hoop);
}

int main(int argc, char *argv[]) {
	// read in hoop heights
	int a = 0;
	while(a != -1) {
		cin >> a;
		hoops.push_back(a);
	}
	hoops.pop_back();

	if (hoops.size() == 0){
		cout << 0 << endl;
		return 0;
	}

	// initialize dp tab 
		/******************************
		 *			length of hoop list
		 *   ----------------------->
		 *  |
		 * b|e
		 * i|l
		 * g|e
		 * g|m
		 * e|e
		 * s|n
		 * t|t (+1)
		 *  |
		 *  v
		 *******************************
		 */


	int max_e = *max_element(hoops.begin(), hoops.end());
	dptab = vector<vector<int>>(max_e + 1, vector<int>(hoops.size() + 1, -1));

	// print best set of hoops to take
	cout << solve(max_e, 0) << endl;


	return 0;
}

