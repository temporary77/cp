#include <bits/stdc++.h>
using namespace std;

int arr[100001];

int main() {
	int n, d;
	scanf("%d%d",&n,&d);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
	}
	int r = 0;
	long long ans = 0;
	for (int i = 0; i < n-2; ++i) {
		for (;arr[r]-arr[i] <= d;) {
			if (r == n)break;
			++r;
		}
		ans += (long long)(r-i-1)*(r-i-2)/2;
	}
	printf("%lld",ans);
	return 0;
}