#include <bits/stdc++.h>
using namespace std;

int cnt[31];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, m;
		scanf("%d%d",&n,&m);
		fill(cnt,cnt+(n+m)/2,0);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int a;
				scanf("%d",&a);
				cnt[min(i+j,n+m-2-i-j)] += a;
			}
		}
		int ans = 0;
		for (int i = 0; i < (n+m-1)/2; ++i) {
			int all = i < n && i < m ? 2*(i+1) : 2*min(n,m);
			ans += min(cnt[i],all-cnt[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}