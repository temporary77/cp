#include <bits/stdc++.h>
using namespace std;

long long arr[101][101];

int main() {
	for (int a = 0; a < 100; ++a) {
	int n, m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i <= n; ++i) {
		arr[i][0] = 1;
	}
	arr[1][1] = 1;
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			arr[i][j] = arr[i-1][j] + arr[i-2][j-1];
		}
	}
	/*for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}*/
	printf("%lld",arr[n][m]);
}
	return 0;
}

//(n,m) = (n-1,m) + (n-2,m-1);