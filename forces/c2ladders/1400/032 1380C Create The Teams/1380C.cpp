#include <bits/stdc++.h>
using namespace std;

int arr[100001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, x;
		scanf("%d%d",&n,&x);
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i]);
		}
		sort(arr,arr+n);
		int cnt = 0;
		int r = n;
		for (int i = n-1; i >= 0; --i) {
			if (arr[i]*(r-i) >= x) {
				++cnt;
				r = i;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}