#include <bits/stdc++.h>
using namespace std;

int qs[100001];

int main() {
	int n, h1, h2;
	scanf("%d",&n);
	scanf("%d",&h1);
	for (int i = 1; i < n; ++i) {
		scanf("%d",&h2);
		if (h1 < h2) {
			++qs[h1+1];
			--qs[h2];
		} else {
			++qs[h2+1];
			--qs[h1];
		}
		h1 = h2;
	}
	for (int i = 1; i <= 100001; ++i) {
		qs[i] += qs[i-1];
	}
	/*for (int i = 0; i <= 100001; ++i) {
		printf("%d ",qs[i]);
	}
	printf("\n");*/
	for (int i = 2; i <= 100001; ++i) {
		qs[i] += qs[i-2];
	}
	/*for (int i = 0; i <= 100001; ++i) {
		printf("%d ",qs[i]);
	}
	printf("\n");*/
	int q;
	scanf("%d",&q);
	int a, b;
	for (int i = 0; i < q; ++i) {
		scanf("%d%d",&a,&b);
		printf("%d %d\n",qs[b-(b%2)]-qs[(a-1)-((a-1)%2)],qs[b-((b+1)%2)]-qs[max(0,(a-1)-(a%2)) ]);
	}
	return 0;
}