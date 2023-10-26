#include <bits/stdc++.h>
using namespace std;

int arr[50001];
int tree[50001];
unordered_map<int,int> mp;
int n;
vector<pair<int,int>> querys[50001];

void update(int x, int val) {
	for (int i = x; i <= n; i += i&-i) {
		tree[i] += val;
	}
	return;
}

int query(int x) {
	int sum = 0;
	for (int i = x; i > 0; i -= i&-i) {
		sum += tree[i];
	}
	return sum;
}

int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&arr[i]);
	}
	int q;
	scanf("%d",&q);
	int ans[q];
	int l, r;
	for (int i = 0; i < q; ++i) {
		scanf("%d%d",&l,&r);
		querys[l+1].push_back({r+1,i});
	}
	for (int i = n; i >= 1; --i) {
		if (mp.find(arr[i]) != mp.end()) {
			update(mp[arr[i]],-1);
		}
		mp[arr[i]] = i;
		update(i,1);
		for (auto it : querys[i]) {
			//printf("%d %d %d\n",i,it.first,query(it.first));
			ans[it.second] = it.first-i+1-query(it.first);
		}
	}
	for (int i = 0; i < q; ++i) {
		printf("%d\n",ans[i]);
	}
	return 0;
}