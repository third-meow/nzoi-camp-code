#include<bits/stdc++.h>
using namespace std;


int main() {

	int gn, nn;
	cin >> gn >> nn;

	map<string, int> students;
	string temp;
	for(int i = 0; i < gn; ++i) {
		cin >> temp;
		if (students.find(temp) != students.end())
			students[temp]++;
		else
			students[temp] = 1;
	}


	for(int i = 0; i < nn; ++i){
		cin >> temp;
		students[temp] = -1;
	}

	for(auto kv : students)
		if(kv.second != -1)
			cout << kv.first << " " << kv.second << endl;

	return 0;
}

