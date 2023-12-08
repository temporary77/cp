#include <bits/stdc++.h>
using namespace std;

long long arr[100001];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld",&arr[i]);
	}
	sort(arr,arr+n);
	long long ans = 0;
	double limit = pow(arr[n-1],1/(double)(n-1));
	int r = floor(limit);
	long long cur = 1;
	for (int i = 0; i < n; ++i) {
		ans += abs(arr[i]-cur);
		cur *= r;
	}
	if (floor(limit) != ceil(limit)) {
		r = ceil(limit);
		long long sum = 0;
		cur = 1;
		for (int i = 0; i < n; ++i) {
			sum += abs(arr[i]-cur);
			if (sum >= ans)goto g;
			cur *= r;
		}
		ans = min(ans,sum);
	}
	g:;
	printf("%lld\n",ans);
	return 0;
}