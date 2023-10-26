#include <bits/stdc++.h>
using namespace std;

int arr[100];

int main() {
	int m, n;
	scanf("%d%d",&m,&n);
	int l = 0, r = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
		l = max(l,arr[i]);
		r += arr[i];
	}
	for (;;) {
		if (l >= r)break;
		int mid = (l+r)/2;
		//printf("%d\n",mid);
		int cnt = 0, cur = 1;
		for (int i = 0; i < n; ++i) {
			if (cur > m) {
				l = mid+1;
				break;
			} else {
				cnt += arr[i];
				if (cnt > mid) {
					++cur;
					cnt = arr[i];
				}
				if (i == n-1) {
					if (cur > m) {
						l = mid+1;
					} else {
						r = mid;
					}
					break;
				}
			}
		}
	}
	printf("%d",l);
	return 0;
}

/*
2
4
7
3
5

10
7
8
9

1
1
1
1
*/