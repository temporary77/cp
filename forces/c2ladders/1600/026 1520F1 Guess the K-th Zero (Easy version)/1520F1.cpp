#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, t;
	scanf("%d%d",&n,&t);
	for (int ti = 0; ti < t; ++ti) {
		int k;
		scanf("%d",&k);
		int l = 1, r = n;
		for (;;) {
			if (l >= r)break;
			// printf("%d %d\n",l,r);
			int m = (l+r)/2;
			printf("? %d %d\n",1,m);
			fflush(stdout);
			int res;
			scanf("%d",&res);
			// printf("%d???\n",res);
			if (m-res < k) {
				l = m+1;
			} else if (m-res >= k) {
				r = m;
			} else {
				r = m-1;
			}
		}
		printf("! %d\n",l);
		fflush(stdout);
	}
	return 0;
}

// 1 0 1 1 0 1