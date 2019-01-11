#include<bits/stdc++.h>
using namespace std;

vector<int> cowlist;
int cow_n;

int accowscore(int n) {
	if (n == 0) {
		//	ASENDING
		if (accowlist[n+1] < cowlist[n])
			return 1;
		else
			return 0;
	} else {
		if (cowlist[n-1] > cowlist[n]) {
			//must change
			return 1;
		} else {
			int change = accowscore(n-1) + 1;
			int leave = accowscore(n-1);
			if (leave < change) {
				return leave;
			} else {
				return change;
			}
		}
	}
}

int decowscore(int n) {
	if (n == 0) {
		//	DECENDING
		if (cowlist[n+1] > cowlist[n])
			return 1;
		else
			return 0;
	} else {
		if (cowlist[n-1] < cowlist[n]) {
			//must change
			return 1;
		} else {
			int change = decowscore(n-1) + 1;
			int leave = decowscore(n-1);
			if (leave < change) {
				return leave;
			} else {
				return change;
			}
		}
	}
}

int main() {
	cin >> cow_n;
	cowlist.resize(cow_n);

	for(int i = 0; i < cow_n; ++i){
		cin >> cowlist[i];
	}

	cout << min(decowscore(cow_n), accowscore(cow_n)) << endl;

	return 0;
}
