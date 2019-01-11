#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long u64;

u64 fib(u64 n) {
	if (n <= 1) {
		return n;
	} else {
		return fib(n-1) + fib(n-2);
	}
}

int main() {

	cout << fib(50000) << endl;


	return 0;
}

