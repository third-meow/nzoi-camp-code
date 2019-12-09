#include<bits/stdc++.h>
using namespace std;

//globals
vector<vector<vector<int>>> adj_list;
vector<vector<int>> edge_ids;
vector<vector<int>> closed;
int n, m, d;

int dijk() {
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	vector<bool> seen(n, false);

	pq.push({0,0});

	while(pq.empty() == false) {
		vector<int> node = pq.top();
		pq.pop();

		if(seen[node[1]]) continue;
		else seen[node[1]] = true;

		if(node[1] == (n-1)){
			return node[0];
		}

		for(auto neighbour : adj_list[node[1]]) {
			if(neighbour[0] != -1)
				pq.push({node[0]+neighbour[0], neighbour[1]});
		}
	}
	return -1;
}
		


int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> d;

	adj_list.resize(n);
	edge_ids.resize(m);
	closed.resize(d);

	int a, b, w;
	for(int i = 0; i < m; ++i){
		cin >> a >> b >> w;
		//zero index a and b
		--a;
		--b;
		adj_list[a].push_back({w,b});
		adj_list[b].push_back({w,a});
		edge_ids[i] = {
			a,
			(int) adj_list[a].size() - 1,
			b,
			(int) adj_list[b].size() - 1
		};
	}
	
	int temp;
	int todays_closed_n;
	for(int i = 0; i < d; ++i) {
		cin >> todays_closed_n;
		for(int j = 0; j < todays_closed_n; ++j) {
			cin >> temp;
			--temp;
			closed[i].push_back(temp);
		}
	}

	vector<int> store;
	//find optimal
	int perfect = dijk();
	for(int v = 0; v < d; ++v) {


		//save backup of adj_list
		auto bkup_adjlist = adj_list;

		//'remove' closed paths
		for(auto i : closed[v]) {
			auto id = edge_ids[i];

			adj_list[id[0]][id[1]][0] = -1;
			adj_list[id[2]][id[3]][0] = -1;
		}

		//run dijk again for real time
		int real = dijk();

		if(real == -1)
			cout << "VERY LATE" << endl;
		else

		//compare and return
		cout << (real - perfect) << endl;

		//just restore backup
		adj_list = bkup_adjlist;
	}
		

	return 0;
}
