#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long u64;
typedef vector<u64> DPTable;

DPTable record;

u64 fib(u64 n) {
	iota(record.begin(), record.begin()+2, 0);

	for(int i = 2; i < (n+1); ++i) {
		record[i] = record[i-1] + record[i-2];
	}
	return record[n];
}

int main() {

	record = DPTable(50000, 0);

	cout << fib(50000) << endl;


	return 0;
}

