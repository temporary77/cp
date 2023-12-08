#include <bits/stdc++.h>
using namespace std;

long long arr[100001];

int main() {
	int n;
	scanf("%d",&n);
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%lld",&arr[i]);
		ans += arr[i]-1;
	}
	sort(arr,arr+n);
	long long bound = ans+arr[n-1];
	for (int r = 2;; ++r) {
		long long sum = 0;
		long long cur = 1;
		for (int i = 0; i < n; ++i) {
			if (cur > bound)goto g;
			sum += abs(arr[i]-cur);
			cur *= r;
		}
		ans = min(ans,sum);
	}
	g:;
	printf("%lld\n",ans);
	return 0;
}