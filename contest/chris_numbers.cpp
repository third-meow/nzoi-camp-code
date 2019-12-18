#include<bits/stdc++.h>
using namespace std;
#define INF 2000000000


struct Node {
	int val;
	int idx;
	int range_s, range_e;

	Node(int _val, int _idx, int _range_s, int _range_e) {
		val = _val;
		idx = _idx;
		range_s = _range_s;
		range_e = _range_e;
	}

	Node(int _val) {
		val = _val;
	}

	bool operator<(const Node& other) const {
		return val < other.val;
	}
};

void build_segtree(const vector<int>& arr, vector<Node>& tree, int pos, int start, int end) {
	if (start == end) {
		tree[pos] = Node(arr[start], start, start, end);
	} else {
		int mid = (start + end) / 2;
		build_segtree(arr, tree, (pos*2), start, mid);
		build_segtree(arr, tree, ((pos*2)+1), mid+1, end);
		Node smlr = min(tree[pos*2], tree[(pos*2)+1]);
		tree[pos] = Node(smlr.val, smlr.idx, start, end);
	}
}

Node min_q(vector<Node>& tree, int q_start,	int q_end, int pos = 1) {
	if (q_start < 0 || q_start > q_end || q_start > tree[pos].range_e || q_end < tree[pos].range_s) {
		return Node(INF);
	} else if (q_start <= tree[pos].range_s &&	q_end >= tree[pos].range_e) {
		return tree[pos];
	} else {
		Node left = min_q(tree, q_start, q_end, (pos*2));
		Node right = min_q(tree, q_start, q_end, ((pos*2)+1));
		return min(left, right);
	}
}

void update_segtree(vector<Node>& tree, int pos, int start, int end, int delta) {
	if (tree[pos].range_s > end || tree[pos].range_e < start) {
		return;
	} else if (start == end) {
		tree[pos].val += delta;
	} else {
		update_segtree(tree, (pos*2), start, end, delta);
		update_segtree(tree, (pos*2)+1, start, end, delta);
		Node smlr = min(tree[pos*2], tree[(pos*2)+1]);
		tree[pos] = Node(smlr.val, smlr.idx, start, end);
	}
}
		
void print_segtree(const vector<Node>& tree, int size) {
	cout << "------------------------------------------------------" << endl;
	int npr = 1;
	int npr_c = 0;
	for(int i = 0; i < size; ++i) {
		++npr_c;
		int range = tree[i].range_e - tree[i].range_s;
		for(int x = 0; x < range; ++x) {
			cout << " ";
		}
		cout << (tree[i].val == INF ? -1 : tree[i].val);
		for(int x = 0; x < range; ++x) {
			cout << " ";
		}

		if (npr_c >= npr) {
			cout << endl;
			++npr;
			npr_c = 0;
		}
	}
	cout << "------------------------------------------------------" << endl;
}


int main(int argc, char *argv[]) {
	int n, k;
	cin >> n >> k;

	vector<int> nums(n, 0);
	for(int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	// build segment tree
	vector<Node> st(4*n, Node(INF));
	build_segtree(nums, st,	1, 0, n-1);

	for(int i = 0; i < k; ++i) {
		char cmd;
		int a, b, delta;
		cin >> cmd;

		if (cmd == 'Q') {
			
			// get query bounds
			cin >> a >> b;
			// get position of smallest element
			Node smallest = min_q(st, a, b);
			// get position of second smallest element
			Node s_smallest = min(min_q(st, a, smallest.idx-1), min_q(st, smallest.idx+1, b));
			// output smallest and second smallest elements
			cout << smallest.val << " " << s_smallest.val << endl;

		} else if (cmd == 'U') {

			cin >> a >> b >> delta;
			update_segtree(st, 1, a, b, delta);
			print_segtree(st, n-1);

		}

	}
	return 0;
}
