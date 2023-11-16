#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, h, k;
	scanf("%d%d%d",&n,&h,&k);
	int x;
	long long ans = 0;
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&x);
		if (x > h-cur) {
			int t = (x-(h-cur)+k-1)/k;
			ans += t;
			cur = max(0,cur-k*t);
		}
		cur += x;
	}
	ans += (cur+k-1)/k;
	printf("%lld",ans);
	return 0;
}