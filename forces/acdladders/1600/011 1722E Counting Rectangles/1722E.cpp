#include <bits/stdc++.h>
using namespace std;

long long arr[1001][1001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, q;
		scanf("%d%d",&n,&q);
		for (int i = 1; i <= 1000; ++i) {
			fill(arr[i]+1,arr[i]+1001,0);
		}
		for (int i = 0; i < n; ++i) {
			int h, w;
			scanf("%d%d",&h,&w);
			arr[h][w] += h*w;
		}
		for (int i = 1; i <= 1000; ++i) {
			for (int j = 1; j <= 1000; ++j) {
				arr[i][j] += arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
			}
		}
		for (int qi = 0; qi < q; ++qi) {
			int hs, ws, hb, wb;
			scanf("%d%d%d%d\n",&hs,&ws,&hb,&wb);
			--hb; --wb;
			printf("%lld\n",arr[hb][wb]-arr[hs][wb]-arr[hb][ws]+arr[hs][ws]);
		}
	}
	return 0;
}