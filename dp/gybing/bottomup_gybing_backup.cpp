#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define INF 2000000
#define LEFT 0
#define RIGHT 1

/*
 * height by width by 2 (going left / going right)
 */
vector<vector<vi>> dp_tab;
vector<vi> wind;

int width, length;


void print_dp_tab() {
	for(auto row : dp_tab) {
		for (auto pr : row) {
			cout << pr[1] << " / " << pr[0] << "\t";
		}
		cout << endl;
	}
}

int main(int argc, char *argv[]) {

	cin >> width >> length;
	wind = vector<vi>(length, vi(width, 0));

	for(int i = 0; i < length; ++i) {
		for(int j = 0; j < width; ++j) {
			cin >> wind[i][j];
		}
	}

	dp_tab = vector<vector<vi>>(length+1, vector<vi>(width, vi(2, -1)));

	//fill bottom of dptab with wind values (both left and right side)
	for (int i = 0; i < width; ++i) {
		dp_tab[length][i][LEFT] = dp_tab[length][i][RIGHT] = -INF;
		dp_tab[length-1][i][LEFT] = dp_tab[length-1][i][RIGHT] = wind[length-1][i];
	}
	
	for (int i = length-2; i >= 0; --i) {
		dp_tab[i][0][LEFT] = -INF;
		dp_tab[i][0][RIGHT] = dp_tab[i+1][0+1][RIGHT] + wind[i][0];
		for (int j = 1; j < width-1; ++j) {
			dp_tab[i][j][LEFT] = 
				max((int) dp_tab[i+1][j-1][LEFT], (int) (dp_tab[i+2][j][RIGHT] - pow(wind[i+1][j-1], 2))) + wind[i][j];
			dp_tab[i][j][RIGHT] = 
				max((int) dp_tab[i+1][j+1][RIGHT], (int) (dp_tab[i+2][j][LEFT] - pow(wind[i+1][j+1], 2))) + wind[i][j];
		}
		dp_tab[i][width-1][LEFT] = dp_tab[i+1][width-2][LEFT] + wind[i][width-1];
		dp_tab[i][width-1][RIGHT] = -INF;
	}


	int c_max = -INF;
	for (auto pr : dp_tab[0]) {
		for (int x : pr) {
			if (c_max < x) c_max = x;
		}
	}

	dp_tab.pop_back();
	for(auto row : dp_tab) {
		for(auto e : row) {
			cout << e[0] << "/" << e[1] << "\t\t";
		}
		cout << endl;
	}

	cout << c_max << endl;






	

	return 0;
}

