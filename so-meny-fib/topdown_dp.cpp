#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long u64;
typedef vector<u64> DPTable;

DPTable record;

u64 fib(u64 n) {
	if (record[n] != 0) {
		return record[n];
	} else if (n <= 1) {
		return n;
	} else {
		return record[n] = fib(n-1) + fib(n-2);
	}
}

int main() {

	record = DPTable(50000, 0);

	cout << fib(50000) << endl;


	return 0;
}

