#include<bits/stdc++.h>
using namespace std;

#define N testcase[0]
#define K testcase[1]

int main(int argc, char *argv[]) {
	// dont sync with standard io
	ios_base::sync_with_stdio(false);
	
	// test case count
	uint64_t testcase_n;
	cin >> testcase_n;

	// read requests
	vector<vector<uint64_t>> requests(testcase_n, vector<uint64_t>(3, 0));
	for(int i = 0; i < testcase_n; ++i) {
		cin >> requests[i][0] >> requests[i][1];
		requests[i][2] = i;
	}
	
	// sort requests by size of table needed
	sort(requests.begin(), requests.end());

	vector<uint64_t> tab = {1};
	for(vector<uint64_t>& testcase : requests) {
		while(tab.size() <= N) {
			auto working = vector<uint64_t>(tab.size()+1, 0);

			for(uint64_t i = 1; i < tab.size(); ++i) {
				working[i-1] += tab[i];
				working[i+1] += tab[i];
			}
			working[1] += tab[0];
			working[0] *= 2;
			tab = working;
		}
		//uint64_t res = (tab[K] / tab[N]) % 1000000007;
		uint64_t res = ((tab[K] % 1000000007) * ((uint64_t) pow(tab[N], -1) % 1000000007));
		testcase[1] = res;
		testcase[0] = testcase[2];
	}

	sort(requests.begin(), requests.end());
	for(vector<uint64_t> testcase : requests) {
		cout << testcase[1] << endl;
	}




	

	return 0;
}

