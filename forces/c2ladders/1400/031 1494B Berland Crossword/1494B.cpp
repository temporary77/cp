#include <bits/stdc++.h>
using namespace std;

int side[4];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 0; i < 4; ++i)scanf("%d",&side[i]);
		for (int i = 0; i < 16; ++i) {
			int cnt[4] = {0,0,0,0};
			for (int j = 0; j < 4; ++j) {
				if (i&(1 << j)) {
					++cnt[j];
					++cnt[(j+1)%4];
				}
			}
			for (int j = 0; j < 4; ++j) {
				// printf("%d %d\n",side[j],cnt[j]);
				if (side[j]-cnt[j] < 0 || side[j]-cnt[j] > n-2)goto h;
			}
			printf("YES\n");
			goto g;
			h:;
		}
		printf("NO\n");
		g:;
	}
	return 0;
}