#include <bits/stdc++.h>
using namespace std;

long long arr[1000001];

int main() {
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	long long l = 0, r = (long long)1e9;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
		r = min(r,arr[i]);
	}
	r *= m;
	for (;;) {
		//printf("%lld %lld\n",l,r);
		if (l >= r)break;
		long long mid = (l+r)/2;
		//printf("%lld\n",mid);
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			ans += mid/arr[i];
		}
		//printf("%lld\n",ans);
		if (ans >= m) {
			r = mid;
		} else {
			l = mid+1;
		}
	}
	printf("%lld",l);
	return 0;
}