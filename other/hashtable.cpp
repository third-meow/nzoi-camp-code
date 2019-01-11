#include<bits/stdc++.h>
using namespace std;

hash<string> hashit;

int main() {
	int table[64];
	for(int i = 0; i < 64; ++i)
		table[i] = 0;
	string command;
	while(true) {
		cin >> command;

		//process command
		//? = query
		if(command.back() == '?'){
			command.pop_back();
			int pos = hashit(command) % 64;
			cout << table[pos] << " found" << endl;
		}
		//! = remove
		else if (command.back() == '!') {
			command.pop_back();
			int pos = hashit(command) % 64;
			--table[pos];
			cout << "one " << command << " has been removed" << endl;
		} 
		//just a word = insert
		else {
			int pos = hashit(command) % 64;
			++table[pos];
			cout << "one " << command << " been added" << endl;
		}
	}


	return 0;
}

