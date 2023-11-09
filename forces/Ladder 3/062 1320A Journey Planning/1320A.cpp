#include <bits/stdc++.h>
using namespace std;

long long cnt[600001];

int main() {
	int n;
	scanf("%d",&n);
	int b;
	long long ans = LLONG_MIN;
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&b);
		int idx = 2e5+b-i;
		cnt[idx] += b;
		ans = max(ans,cnt[idx]);
	}
	printf("%lld",ans);
	return 0;
}