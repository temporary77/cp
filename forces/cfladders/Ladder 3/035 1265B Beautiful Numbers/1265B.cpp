#include <bits/stdc++.h>
using namespace std;

int idx[200002];
int arr[200002];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d",&arr[i]);
			idx[arr[i]] = i;
		}
		arr[0] = n+1;
		arr[n+1] = n+1;
		int cnt = 0;
		bool a, b;
		for (int i = 1; i <= n; ++i) {
			a = arr[idx[i]-1] < i;
			b = i > arr[idx[i]+1];
			if (a && b) {
				--cnt;
			} else if (!(a || b)) {
				++cnt;
			}
			if (cnt == 1) {
				printf("1");
			} else {
				printf("0");
			}
		}
		printf("\n");
	}
	return 0;
}