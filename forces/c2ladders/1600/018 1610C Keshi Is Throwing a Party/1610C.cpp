#include <bits/stdc++.h>
using namespace std;

int arr[200001];
int brr[200001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d",&arr[i],&brr[i]);
		}
		int l = 1, r = n;
		for (;;) {
			if (l >= r)break;
			int m = (l+r+1)/2;
			int cur = 0;
			for (int i = 0; i < n; ++i) {
				if (brr[i] >= cur && m-1-cur <= arr[i]) {
					++cur;
				}
			}
			if (cur >= m) {
				l = m;
			} else {
				r = m-1;
			}
		}
		printf("%d\n",l);
	}
	return 0;
}