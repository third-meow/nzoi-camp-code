#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> Tracklist;

Tracklist tracks;

vector<vector<int>> past_results;

int solve(int upto_track, int max_len) {
	//base case
	if (upto_track == 0) {
		return 0;

	// if already calculated
	} else if (past_results[upto_track][max_len] != -1) {
		return past_results[upto_track][max_len];
	
	//figure it out
	} else {
		int track_time = tracks[upto_track-1][0];
		int track_value = tracks[upto_track-1][1];


		//best case if we include last track
		int included = track_time > max_len ? 0 : (solve(upto_track-1, (max_len - track_time)) + track_value);
		//best case if we dont include last track
		int not_included = solve(upto_track-1, max_len);

		if (included > not_included) {
			past_results[upto_track][max_len] = solve(upto_track-1, max_len - track_time) + track_value;
		} else {
			past_results[upto_track][max_len] = solve(upto_track-1, max_len);
		}
		return past_results[upto_track][max_len];
	}
}



int main() {
	int track_n, playlist_len;
	
	cin >> track_n >> playlist_len;
	for(int i = 0; i < track_n; ++i) {
		vector<int> track(2, 0);
		//		v	time v    v value v
		cin >> track[0] >> track[1];
		//		^	time ^    ^ value ^
		tracks.push_back(track);
	}

	//build out past result table
	past_results = vector<vector<int>>(tracks.size()+1, vector<int>(playlist_len+1, -1));

	cout << solve(tracks.size(), playlist_len) << endl;
	

	return 0;
}

