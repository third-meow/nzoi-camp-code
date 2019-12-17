#include<bits/stdc++.h>
using namespace std;
#define INF 2000000000



void build_segtree(const vector<int>& arr, vector<int>& tree, int pos, int start, int end) {
	if (start != end) {
		int mid = (start + end) / 2;
		build_segtree(arr, tree, (pos*2), start, mid);
		build_segtree(arr, tree, (pos*2)+1, mid+1, end);
		tree[pos] = min(tree[pos*2], tree[(pos*2)+1]);
	} else {
		tree[pos] = arr[start];
	}
}

int r_min_q(const vector<int>& tree, int pos, int start, int end, int pos_start, int pos_end) {
	if (start > pos_end || end < pos_start) return 0;
	if (start <= pos_start && end >= pos_end) return pos;
	int mid = (pos_start + pos_end) / 2;

	int leftpos= r_min_q(tree, (pos*2), start, end, pos_start, mid);
	int left = tree[leftpos];

	int rightpos= r_min_q(tree, (pos*2)+1, start, end, mid+1, pos_end);
	int right = tree[rightpos];

	if (left < right) return leftpos;
	return rightpos;
}

void update(vector<int>& tree, int pos, int start, int end, int delta, int pos_start, int pos_end) {
	if (start > pos_end || end < pos_start) return;
	if (pos_start == pos_end) {
		tree[pos] += delta;
		return;
	}

	int mid = (pos_start + pos_end) / 2;
	update(tree, (pos*2), start, end, delta, pos_start, mid);
	update(tree, (pos*2)+1, start, end, delta, mid+1, pos_end);
	tree[pos] = min(tree[(pos*2)], tree[(pos*2)+1]);
}
	

int main(int argc, char *argv[]) {
	int n, k;
	cin >> n >> k;

	vector<int> nums(n, 0);
	for(int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	vector<int> st(n*4, INF);

	for(int i = 0; i < k; ++i) {
		char cmd;
		int a, b, delta;
		cin >> cmd;
		if (cmd == 'Q') {
			// get query bounds
			cin >> a >> b;
			
			// build segment tree
			build_segtree(nums, st, 1, 0, n-1);

			// get position of smallest element
			int small_pos = r_min_q(st, 1, a, b, 0, n-1);
			int small = st[small_pos];

			// get position of second smallest element
			update(st, 1, small_pos, small_pos, INF, 0, n-1);
			int s_small_pos = r_min_q(st, 1, a, b, 0, n-1);
			int s_small = st[s_small_pos];
			update(st, 1, small_pos, small_pos, -INF, 0, n-1);

			// output smallest and second smallest elements
			cout << small << " " << s_small << endl;
		}

		if (cmd == 'U') {
			cin >> a >> b >> delta;
			for(int i = a; i <= b; ++i) {
				nums[i] += delta;
			}
		}
	}
	return 0;
}

