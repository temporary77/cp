#include <bits/stdc++.h>
using namespace std;

// int tree[200001];
// pair<int,int> arr[200001];
// int n;

// bool comp(pair<int,int> a, pair<int,int> b) {
// 	if (a.first != b.first) {
// 		return a.first < b.first;
// 	} else {
// 		return a.second > b.second;
// 	}
// }

// void update(int x, int val) {
// 	for (int a = x; a <= n; a += a&-a) {
// 		tree[a] = max(tree[a],val);
// 	}
// 	return;
// }

// int query(int x) {
// 	int res = INT_MIN;
// 	for (int a = x; a > 0; a -= a&-a) {
// 		res = max(res,tree[a]);
// 	}
// 	return res;
// }

int dp[200001];

int main() {
	int n;
	scanf("%d",&n);
	int k;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		int idx = lower_bound(dp,dp+ans+1,k)-dp;
		dp[idx] = k;
		if (idx > ans)++ans;
		// arr[i] = {k,i+1};
	}
	// sort(arr,arr+n,comp);
	// int ans = INT_MIN;
	// for (int i = 0; i < n; ++i) {
	// 	// printf("%d\n",arr[i].second);
	// 	int qry = query(arr[i].second);
	// 	ans = max(ans,qry+1);
	// 	update(arr[i].second,qry+1);
	// }
	printf("%d",ans);
	return 0;
}