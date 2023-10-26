#include <bits/stdc++.h>
using namespace std;

int arr[101];
bool dp[10001];

int main() {
	int c;
	scanf("%d",&c);
	int n, t;
	for (int a = 0; a < c; ++a) {
		scanf("%d%d",&n,&t);
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i]);
		}
		dp[0] = 1;
		for (int i = 1; i <= t; ++i) {
			dp[i] = 0;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = t; j >= 0; --j) {
				if (j >= arr[i]) {
					if (dp[j-arr[i]] == 1)dp[j] = 1;
				}
			}
		}
		if (dp[t]) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}