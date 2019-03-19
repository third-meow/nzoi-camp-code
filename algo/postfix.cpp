#include<bits/stdc++.h>
using namespace std;


int main() {
	stack<int> nums;
	string line;
	while(getline(cin, line)) {
		if(line == "+") {
				int a,b;
				a = nums.top();
				nums.pop();
				b = nums.top();
				nums.pop();

				nums.push(a+b);
		}else if(line == "-") {
				int a,b;
				a = nums.top();
				nums.pop();
				b = nums.top();
				nums.pop();

				nums.push(a-b);
		} else if(line == "*") {
				int a,b;
				a = nums.top();
				nums.pop();
				b = nums.top();
				nums.pop();

				nums.push(a*b);
		}else{
				nums.push(atoi(line.c_str()));
		}
	}

		if (nums.empty())
			cout << "stack empty lol" << endl;
		else if(nums.size() > 1)
			cout << "stack has " << nums.size() << " elements lol" << endl;
		else
			cout << nums.top() << endl;
	

	return 0;
}

