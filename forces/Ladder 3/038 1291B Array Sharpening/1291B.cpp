#include <bits/stdc++.h>
using namespace std;

int arr[300001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i]);
		}
		int idx;
		for (idx = 0; idx < n-1; ++idx) {
			if (arr[idx+1] < idx+1)break;
		}
		for (int i = n-1; i >= 0; --i) {
			if (i == idx) {
				printf("Yes\n");
				goto g;
			}
			if (arr[i-1] < n-i)break;
		}
		printf("No\n");
		g:;
	}
	return 0;
}