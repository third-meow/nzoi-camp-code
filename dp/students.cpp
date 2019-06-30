#include<bits/stdc++.h>
using namespace std;

vector<uint32_t> dp_tab = {1};

uint32_t fact(int n, uint32_t mod) {
	uint32_t run = 1;
	for(int i = dp_tab.size(); i <= n; ++i) {
		run = (run * i) % mod;
	}
	return run;
}

int main() {
	int student_n, required;
	cin >> student_n >> required;

	unsigned long long 
	cout << ( fact(student_n) / ( fact(student_n - required) * fact(required) ) ) % 100000 << endl;

	/*
	for (int i = 0; i < 20; ++i) {
		cout << fact_ro(i) << endl;
		cout << fact_no(i) % 100000 << endl;
		cout << fact(i) << endl;
		cout << endl << endl;
	}
	*/




	return 0;
}

