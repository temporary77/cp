#include <bits/stdc++.h>
using namespace std;

int disjoint[101];
int ans;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	ans = 0;
	int k, x, a;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		if (k == 0) {
			++ans;
			continue;
		}
		scanf("%d",&x);
		if (!disjoint[x]) {
			disjoint[x] = x;
			++cnt;
		}
		if (k == 1)continue;
		int px = x;
		for (;px != disjoint[px];) {
			px = disjoint[px];
		}
		for (int j = 1; j < k; ++j) {
			scanf("%d",&a);
			int pa = a;
			if (!disjoint[a]) {
				disjoint[a] = a;
				++cnt;
			}
			for (;pa != disjoint[pa];) {
				pa = disjoint[pa];
			}
			if (pa != px) {
				disjoint[pa] = px;
				disjoint[a] = px;
				--cnt;
			}
		}
	}
	ans += max(cnt-1,0);
	printf("%d",ans);
	return 0;
}