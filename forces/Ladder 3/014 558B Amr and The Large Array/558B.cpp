#include <bits/stdc++.h>
using namespace std;

int cnt[1000001];
int pos[1000001];

int main() {
	int n;
	scanf("%d",&n);
	int k;
	int max1 = 0;
	int l = -1;
	int r = -1;
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&k);
		if (pos[k] == 0) {
			pos[k] = i;
		}
		++cnt[k];
		if (cnt[k] >= max1) {
			if (cnt[k] > max1) {
				max1 = cnt[k];
				l = pos[k];
				r = i;
			} else {
				if (i-pos[k]+1 < r-l+1) {
					r = i;
					l = pos[k];
				}
			}
		}
	}
	printf("%d %d\n",l,r);
	return 0;
}