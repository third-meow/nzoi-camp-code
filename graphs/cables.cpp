#include<bits/stdc++.h>
using namespace std;

int node_n; 
vector<vector<pair<int,int>>> adj_list;
vector<bool> seen;

int main() {

	scanf("%d", &node_n);

	for(int i = 0; i < node_n; ++i) {
		adj_list.push_back({});
	}

	int f,t,w;
	while(scanf("%d %d %d", &f, &t, &w) != EOF){
		adj_list[(f-1)].push_back(make_pair(w, (t-1)));
		adj_list[(t-1)].push_back(make_pair(w, (f-1)));
	}

	for(int i = 0; i < node_n; ++i)
		seen.push_back(false);


	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	q.push(make_pair(0,0));


	int result = 0;
	while(!q.empty()){
		//cout << "\t" << q.size() << endl;
		//pop
		pair<int,int> edge = q.top();
		q.pop();
		//check for visted
		if(seen[edge.second] == false){
			//add weigh to result
			result += edge.first;
			seen[edge.second] = true;
			//push all other edges branching from end
			for(auto branchoff : adj_list[edge.second])
				q.push(branchoff);
		}
	}

	cout << result;

	return 0;
}

