#include <bits/stdc++.h>
using namespace std;
 
int arr[1000001];
 
int main() {
	int q;
	scanf("%d",&q);
	for (int qi = 0; qi < q; ++qi) {
		int n, k;
		scanf("%d%d",&n,&k);
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i]);
		}
		int cnt[1000001] = {0};
		long long ans = 0;
		int l = 0;
		int r = 0;
		int cur = 0;
		bool cooler = 0;
		for (;;) {
			for (;;) {
				if (cur >= k) {
					ans += n-r+1;
					break;
				}
				if (r >= n) {
					cooler = 1;
					break;
				}
				if (cnt[arr[r]] == 0) {
					++cur;
				}
				++cnt[arr[r]];
				++r;
			}
			if (cooler)break;
			--cnt[arr[l]];
			if (cnt[arr[l]] == 0) {
				--cur;
			}
			++l;
		}
		printf("%lld\n",ans);
	}
	return 0;
}