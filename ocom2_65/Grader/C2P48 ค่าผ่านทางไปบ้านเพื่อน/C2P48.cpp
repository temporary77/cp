#include <bits/stdc++.h>
using namespace std;

long long arr[1005][1005];

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	long long k, x;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%lld",&k);
			if (i == 0 && j == 0) {
				arr[i][j] = k;
				continue;
			}
			x = INT_MAX;
			if (i > 0)x = min(x,arr[i-1][j]);
			if (j > 0)x = min(x,arr[i][j-1]);
			if (i > 0 && j > 0)x = min(x,arr[i-1][j-1]);
			arr[i][j] = x+k;
		}
	}
	printf("%lld",arr[n-1][m-1]);
	return 0;
}