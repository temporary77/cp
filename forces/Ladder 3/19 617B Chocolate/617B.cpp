#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	int cnt = INT_MIN;
	int k;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		if (k == 0) {
			++cnt;
		} else if (k == 1) {
			if (cnt > 0)ans *= cnt;
			else ans = 1;
			cnt = 1;
		}
	}
	printf("%lld",ans);
	return 0;
}