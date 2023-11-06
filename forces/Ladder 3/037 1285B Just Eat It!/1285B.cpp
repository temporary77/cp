#include <bits/stdc++.h>
using namespace std;

int arr[100001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i]);
		}
		long long cur = 0;
		for (int i = 0; i < n-1; ++i) {
			cur += arr[i];
			if (cur <= 0) {
				printf("NO\n");
				goto g;
			}
		}
		cur = 0;
		for (int i = n-1; i > 0; --i) {
			cur += arr[i];
			if (cur <= 0) {
				printf("NO\n");
				goto g;
			}
		}
		printf("YES\n");
		g:;
	}
	return 0;
}