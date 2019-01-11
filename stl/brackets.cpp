#include<bits/stdc++.h>
using namespace std;

char opp_bracket(char in) {
	switch (in){
	case '}': 
		return '{';
	case ']': 
		return '[';
	case '>': 
		return '<';
	case ')': 
		return '(';
	}
}


int main() {
	string exp;
	stack<char> record;

	int num;
	cin >> num;
	cin >> exp;

	int i = 0;
	for(auto c : exp) {
		switch (c) {
			case '{':
			case '[':
			case '<':
			case '(':
				record.push(c);
				break;
			case '}':
			case ']':
			case '>':
			case ')':
				if(record.empty()) {
					cout << "NO";
					return 0;
				} else if(record.top() != opp_bracket(c)) {
					cout << "NO";
					return 0;
				} else
					record.pop();
				break;

		}
		++i;
	}

	if (!record.empty()){
		int remaining = 0;
		while(!record.empty()){
				remaining++;
				record.pop();
		}
		cout << "NO";
		return 0;
	}
			
	cout << "YES";

	return 0;
}

