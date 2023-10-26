#include <bits/stdc++.h>
using namespace std;

#define int long long

long long arr[100001], brr[100001];

signed main() {
	int n, m, s, a, b;
	scanf("%lld%lld%lld%lld%lld",&n,&m,&s,&a,&b);
	int w = 0;
	long long p = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%lld",&arr[i]);
		w += a;
		p += arr[i];
	}
	for (int i = 0; i < m; ++i) {
		scanf("%lld",&brr[i]);
	}
	sort(arr,arr+n,greater<long long>());
	sort(brr,brr+m,greater<long long>());
	int ai = n-1, bi = 0;
	for (;w > s;) {
		if (ai == -1)break;
		w -= a;
		p -= arr[ai];
		--ai;
	}
	long long ans = p;
	//printf("%lld ",p);
	for (;ai >= -1 && bi < m;) {
		w += b;
		p += brr[bi];
		++bi;
		for (;w > s;) {
			if (ai == -1) {
				ai = -2;
				break;
			}
			w -= a;
			p -= arr[ai];
			--ai;
		}
		if(ai != -2)ans = max(ans,p);
	}
	printf("%lld",ans);
	return 0;
}