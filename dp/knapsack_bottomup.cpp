#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

vector<vi> dptab;

int main(int argc, char *argv[]) {
	int length, track_n;
	cin >> track_n >> length;
	dptab = vector<vi>(track_n+1, vi(length+1, -1));
	vi times(track_n, 0);
	vi values(track_n, 0);

	for(int i = 0; i < track_n+1; ++i) {
		cin >> times[i] >> values[i];
	}

	fill(dptab[0].begin(), dptab[0].end(), 0);

	for(int track = 1; track <= track_n; ++track) {
		for(int size = 0; size <= length; ++size) {
			int prev = dptab[track-1][size];
			if (size >= times[track-1]) {
				// DEBUG PRINTOUT
				/*
				if (track == 2 && size == 10) {
					cout << prev << " vs " << dptab[track-1][size - times[track-1]] << " + " << values[track-1] << endl;
				}
				*/
				dptab[track][size] = max(prev, dptab[track-1][size - times[track-1]] + values[track-1]);
			} else {
				dptab[track][size] = prev;
			}
		}
	}


	//// DEBUGING PRINTOUTS
	/*
	
	cout << "Length:    " << length << endl;
	cout << "Track no.: " << track_n << endl;
	cout << "Times:     ";
	for(auto e : times)
		cout << e << " ";
	cout << endl;

	cout << "Values:    ";
	for(auto e : values)
		cout << e << " ";
	cout << endl;

	for(int i = 0; i <= track_n; ++i) {
		for(int j = 0; j <= length; ++j) {
			cout << dptab[i][j] << "\t";
		}
		cout << endl;
	}
	*/
	


	cout << dptab[track_n][length] << endl;



	return 0;
}

