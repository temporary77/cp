#include <bits/stdc++.h>
using namespace std;

// map<int,int> mp;
int cnt[8001];
int qs[8001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d",&qs[i]);
			++cnt[qs[i]];
			qs[i] += qs[i-1];
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i+2; j <= n; ++j) {
				if (qs[j]-qs[i] <= n && cnt[qs[j]-qs[i]] != 0) {
					ans += cnt[qs[j]-qs[i]];
					cnt[qs[j]-qs[i]] = 0;
				}
			}
		}
		printf("%d\n",ans);
		fill(cnt+1,cnt+n+1,0);
	}
	return 0;
}