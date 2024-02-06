#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int qrr[100001];
int cnt[100001];
pair<int,int> rnges[100001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, m;
		scanf("%d%d",&n,&m);
		for (int i = 0; i < m; ++i) {
			scanf("%d%d",&rnges[i].f,&rnges[i].s);
		}
		int q;
		scanf("%d",&q);
		for (int i = 0; i < q; ++i) {
			scanf("%d",&qrr[i]);
		}
		int l = 0, r = q;
		for (;;) {
			if (l >= r)break;
			int mid = (l+r)/2;
			// printf("%d %d %d\n",l,r,mid);
			fill(cnt+1,cnt+n+1,0);
			for (int i = 0; i <= mid; ++i) {
				++cnt[qrr[i]];
			}
			for (int i = 1; i <= n; ++i) {
				cnt[i] += cnt[i-1];
				// printf("%d ",cnt[i]);
			}
			// printf("\n");
			bool check = false;
			for (int i = 0; i < m; ++i) {
				int x = cnt[rnges[i].s]-cnt[rnges[i].f-1];
				if (x > (rnges[i].s-rnges[i].f+1)/2) {
					check = true;
					break;
				}
			}
			if (check) {
				r = mid;
			} else {
				l = mid+1;
			}
		}
		if (l == q)l = -2;
		printf("%d\n",l+1);
	}
	return 0;
}