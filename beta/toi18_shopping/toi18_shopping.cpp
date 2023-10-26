#include <bits/stdc++.h>
using namespace std;

int qs1[500001], qs2[500001];

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int k;
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&k);
		if (k < 0) {
			qs1[i] = qs1[i-1]+k;
			qs2[i] = qs2[i-1];
		} else {
			qs1[i] = qs1[i-1];
			qs2[i] = qs2[i-1]+k;			
		}
	}
	/*for (int i = 1; i <= n; ++i) {
		printf("%d ",qs1[i]);
	}
	printf("\n");
	for (int i = 1; i <= n; ++i) {
		printf("%d ",qs2[i]);
	}
	printf("\n");*/
	int x;
	long long h;
	for (int i = 0; i < m; ++i) {
		scanf("%d%lld",&x,&h);
		++x;
		int l = x, r = n;
		for (;;) {
			if (l >= r)break;
			int mid = (l+r)/2;
			if (qs1[mid]-qs1[x-1]+h <= 0) {
				r = mid;
			} else {
				l = mid+1;
			}
		}
		//printf("%d < \n",l);
		printf("%d\n",qs2[l]-qs2[x-1]);
	}
	return 0;
}