#include <bits/stdc++.h>
using namespace std;

int arr[3001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		long long ttl = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i]);
			ttl += arr[i];
		}
		long long cur = 0;
		for (int i = 0; i < n; ++i) {
			cur += arr[i];
			if (ttl%cur)continue;
			long long curi = 0;
			for (int j = i+1; j < n; ++j) {
				curi += arr[j];
				if (curi > cur) {
					goto g;
				} else if (curi == cur) {
					curi = 0;
				}
			}
			if (curi != 0)goto g;
			printf("%d\n",n-(ttl/cur));
			break;
			g:;
		}
	}
	return 0;
}