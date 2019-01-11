#include<bits/stdc++.h>
using namespace std;


int main() {
	priority_queue<int> q;

	int len, topn;
	cin >> len >> topn;

	for(int i = 0; i < len; ++i) {
		int temp;
		cin >> temp;
		q.push(temp);
	}


	for(int i = 0; i < topn; ++i){
		cout << q.top() << endl;
		q.pop();
	}



	return 0;
}

