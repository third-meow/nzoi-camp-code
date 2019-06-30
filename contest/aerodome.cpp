#include<bits/stdc++.h>
using namespace std;

struct Timer {
	int full;
	int current = -1;

	Timer(int f) {
		full = f;
		set();
	}

	void set() {
		current = full;
	}

	bool tick() {
		current--;
		return current == 0;
	}
};

struct {
	bool operator()(Timer* a, Timer* b) const {
		return a->full < b->full;
	}
} shorterTimer;

int main(int argc, char *argv[]) {
	int desk_n, ppl;
	cin >> desk_n >> ppl;

	vector<Timer> desks;
	{
		int t;
		for (int i = 0; i < desk_n; ++i) {
			cin >> t;
			desks.push_back(Timer(t));
			//desks.back().set();
		}
	}

	int remaining = ppl;
	int count = 0;
	while (true) {
		++count;
		vector<Timer*> avail;
		for (auto &&d : desks) {
			if (d.tick()) {
				//cout << "Done at " << count << endl;
				avail.push_back(&d);
			}
		}

		sort(avail.begin(), avail.end(), shorterTimer);

		for (auto a : avail) {
			if (remaining < 2) {
				cout << count;
				return 0;
			}
			--remaining;
			a->set();
		}
	}






	return 0;
}

