#include <bits/stdc++.h>
using namespace std;

int cnt[200002];
int idx[200002];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= n; ++i) {
			cnt[i] = 0;
			idx[i] = 0;
		}
		int k;
		int max1 = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d",&k);
			if (cnt[k] != 0) {
				--idx[cnt[k]];
			}
			++cnt[k];
			++idx[cnt[k]];
			max1 = max(max1,cnt[k]);
		}
		int ans = 0;
		// for (int i = 1; i <= max1; ++i)printf("%d ",idx[i]);
		// printf("\n");
		for (int i = max1; i >= 1; --i) {
			// printf("%d << %d\n",idx[i],i);
			if (idx[i] == 0)continue;
			ans += i;
			idx[i-1] += idx[i]-1; 
		}
		printf("%d\n",ans);
	}
	return 0;
}