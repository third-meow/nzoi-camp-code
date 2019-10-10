#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
	if (n == 1 || n == 0) return n;
	return solve(n-1) + solve(n-2);
}

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}

