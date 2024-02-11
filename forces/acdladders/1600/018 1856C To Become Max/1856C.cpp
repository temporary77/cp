#include <bits/stdc++.h>
using namespace std;

int arr[1001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, k;
		scanf("%d%d",&n,&k);
		int max1 = INT_MIN;
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i]);
			max1 = max(max1,arr[i]);
		}
		int l = max1, r = max1+n;
		for (;;) {
			if (l >= r) {
				break;
			}
			int m = (l+r+1)/2;
			bool check = false;
			for (int i = 0; i < n; ++i) {
				int ki = k;
				for (int j = 0; i+j < n; ++j) {
					if (arr[i+j]+j >= m) {
						check = true;
						break;
					}
					ki -= (m-j)-arr[i+j];
					if (ki < 0) {
						break;
					}
				}
				if (check)break;
			}
			if (check) {
				l = m;
			} else {
				r = m-1;
			}
		}
		printf("%d\n",l);
	}
	return 0;
}