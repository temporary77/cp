#include <bits/stdc++.h>
using namespace std;

int cnt[200001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, l, r;
		scanf("%d%d%d",&n,&l,&r);
		fill(cnt+1,cnt+n+1,0);
		for (int i = 0; i < l; ++i) {
			int c;
			scanf("%d",&c);
			++cnt[c];
		}
		for (int i = 0; i < r; ++i) {
			int c;
			scanf("%d",&c);
			--cnt[c];
		}
		int pairs = 0;
		int li = 0, ri = 0;
		for (int i = 1; i <= n; ++i) {
			if (cnt[i] > 0) {
				li += cnt[i];
			} else {
				ri -= cnt[i];
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (li >= ri) {
				if (cnt[i] > 0)pairs += cnt[i]/2;
			} else {
				if (cnt[i] < 0)pairs -= cnt[i]/2;
			}
		}
		pairs = min(pairs,abs(li-ri)/2);
		// printf("%d <\n",pairs);
		printf("%d\n",min(li,ri)+pairs+(abs(li-ri)-2*pairs));
	}
	return 0;
}