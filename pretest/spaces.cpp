#include<bits/stdc++.h>
using namespace std;


int main() {
	vector<string> p;
	int n;
	cin >> n;

	string temp;
	getline(cin, temp);
	for(int i = 0; i < n; ++i) {
		string temp;
		getline(cin, temp);
		p.push_back(temp);
	}

	char a;
	cin >> a;

	//for(auto j: p)
		//cout << j << endl;

	//cout << a << endl;

	for(auto s : p) {
		int count = 0;
		for(int i = 0; i < s.size(); ++i)
			if (s[i] == a)
				++count;
		cout << count << endl;
	}




	return 0;
}

