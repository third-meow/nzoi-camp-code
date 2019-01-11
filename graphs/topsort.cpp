#include<bits/stdc++.h>
using namespace std;

vector<string> items;
vector<vector<int>> adj_list;
vector<bool> visited;

bool allTrue(vector<bool>& vec) {
	for(auto b : vec)
		if (!b) return false;
	return true;
}

void topSort(stack<int>& msk, int node) {
	visited[node] = true;
	for(auto neighbour : adj_list[node]) {
		if (!visited[neighbour]) {
			topSort(msk, neighbour);
		}
	}
	msk.push(node);
}

int main() {
	int item_n;
	cin >> item_n;
	
	//resize some vectors
	items.resize(item_n);
	visited.resize(item_n);
	adj_list.resize(item_n);

	{
		string trashstring;
		getline(cin, trashstring);
	}
	for(int i = 0; i < item_n; ++i){
		getline(cin, items[i]);
	}

	int before, after;
	while(cin >> before >> after) {
		adj_list[after].push_back(before);
	}


	stack<int> order;

	for(int i = 0; i < item_n; ++i) {
		if(!visited[i]) {
			topSort(order, i);
		}
	}

	vector<int> inorder;
	while(!order.empty()) {
		inorder.push_back(order.top());
		order.pop();
	}

	reverse(inorder.begin(), inorder.end());
	for(auto i : inorder) {
		cout << items[i] << endl;
	}

	return 0;
}

