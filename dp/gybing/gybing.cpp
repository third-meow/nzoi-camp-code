#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define INF 2000000

int width, length;
vector<vi> wind;

vector<vector<vi>> dp_tab;

int solve(int posx, int posy, bool going_left) {


	// if x axis position is outside bounds, return score of negitive INF
	if (posx < 0 || posx >= width) return -INF;

	if (dp_tab[posx][posy][going_left] != -1) {
		return dp_tab[posx][posy][going_left];
	}

	// if y axis position is at end, return the final wind score 
	if (posy == length-1) {
		return dp_tab[posx][posy][going_left] = wind[posy][posx];
	}



	// wind at position
	int here = wind[posy][posx];
	// x axis movment, depends on going left / right
	int xmove = (going_left ? -1 : 1);
	// turn option
	int turn = solve((posx - xmove), posy+1, !going_left) - (here * here);
	// dont turn option
	int dont_turn = solve((posx + xmove), posy+1, going_left) + here;

	/*
	if (turn > 0 && dont_turn > 0) {
		cout << "two pos\t";
		cout << turn;
		cout << " ";
		cout << dont_turn << endl;
		while(true) {}
	}
	*/


	return dp_tab[posx][posy][going_left] = max(turn, dont_turn);
}

int main(int argc, char *argv[]) {

	cin >> width >> length;
	wind = vector<vi>(length, vi(width, 0));

	for(int i = 0; i < length; ++i) {
		for(int j = 0; j < width; ++j) {
			cin >> wind[i][j];
		}
	}

	dp_tab = vector<vector<vi>>(width, vector<vi>(length, vi(2, -1)));

	int c_max = -INF;
	for(int i = 0; i < width; i++) {
		c_max = max(c_max, max(solve(i, 0, true), solve(i, 0, false)));
	}


	for(auto row : dp_tab) {
		for(auto e : row) {
			// LEFT FIRST
			cout << e[1] << "/" << e[0] << "\t\t";
		}
		cout << endl;
	}
	

	cout << c_max << endl;

	return 0;
}

