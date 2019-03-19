#include<bits/stdc++.h>
using namespace std;


int main() {
	int len;
	vector<string> s;
	cin >> len;
	for(int i = 0; i < len; ++i) {
		string temp;
		cin >> temp;
		s.push_back(temp);
	}

	sort(s.begin(), s.end());

	for(auto a: s)
		cout << a << endl;

	return 0;
}

