#include <bits/stdc++.h>
using namespace std;

long long qs[1005][1005];

int main() {
	int n;
	scanf("%d",&n);
	int k;
	long long rsum;
	for (int i = 0; i < n; ++i) {
		rsum = 0;
		for (int j = 0; j < n; ++j) {
			scanf("%d",&k);
			rsum += k;
			qs[i][j] = rsum;
			if (i > 0)qs[i][j] += qs[i-1][j];
		}
	}
	int m;
	scanf("%d",&m);
	int ax, ay, bx, by;
	long long ans;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d%d",&ax,&ay,&bx,&by);
		--ax;
		--ay;
		ans = 0;
		ans += qs[bx][by];
		if (ax >= 0)ans -= qs[ax][by];
		if (ay >= 0)ans -= qs[bx][ay];
		if (ax >= 0 && ay >= 0)ans += qs[ax][ay];
		printf("%lld\n",ans);
	}
	return 0;
}