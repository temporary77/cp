#include <bits/stdc++.h>
using namespace std;

long long arr[100002];
tuple<int,int,int> brr[100002];
int drr[100002];

int main() {
	int n, m, k;
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld",&arr[i]);
	}
	for (int i = n; i >= 1; --i) {
		arr[i] -= arr[i-1];
	}
	int l, r, d;
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d",&l,&r,&d);
		brr[i] = {l,r,d};
	}
	int x, y;
	for (int i = 0; i < k; ++i) {
		scanf("%d%d",&x,&y);
		++drr[x];
		--drr[y+1];
	}
	for (int i = 1; i <= m; ++i) {
		drr[i] += drr[i-1];
		tie(l,r,d) = brr[i];
		arr[l] += drr[i]*(long long)d;
		arr[r+1] -= drr[i]*(long long)d;
	}
	for (int i = 1; i <= n; ++i) {
		arr[i] += arr[i-1];
		printf("%lld ",arr[i]);
	}
	return 0;
}