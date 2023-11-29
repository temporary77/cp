#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		long long cur[2] = {0,0};
		int min1[2] = {INT_MAX,INT_MAX};
		long long cost[2] = {(long long)1e16,(long long)1e16};
		long long ans = LLONG_MAX;
		for (int i = 0; i < n; ++i) {
			int c;
			scanf("%d",&c);
			int idx = i&1;
			min1[idx] = min(min1[idx],c);
			cur[idx] += c;
			cost[idx] = cur[idx]-min1[idx]+(n-i/2)*(long long)min1[idx];
			ans = min(ans,cost[0]+cost[1]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}