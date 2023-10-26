#include <bits/stdc++.h>
using namespace std;

int arr[105][105];

int main() {
	int l, w, n;
	scanf("%d%d%d",&l,&w,&n);
	for (int i = 1; i <= n; ++i) {
		int a, b, c, d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		++arr[a+1][b+1];
		--arr[a+1][d+1];
		--arr[c+1][b+1];
		++arr[c+1][d+1];
		// for (int i = 1; i <= l; ++i) {
		// 	for (int j = 1; j <= w; ++j) {
		// 		printf("%d ",arr[i][j]);
		// 	}
		// 	printf("\n");
		// }
		// printf("\n");
	}
	// for (int i = 1; i <= l; ++i) {
	// 	for (int j = 1; j <= w; ++j) {
	// 		printf("%d ",arr[i][j]);
	// 	}
	// 	printf("\n");
	// }
	for (int t = 0; t < 2; ++t) {
		for (int i = 1; i <= l; ++i) {
			for (int j = 1; j <= w; ++j) {
				arr[i][j] = arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1]+arr[i][j];
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= l-2; ++i) {
		for (int j = 1; j <= w-2; ++j) {
			if (arr[i+2][j+2]-arr[i-1][j+2]-arr[i+2][j-1]+arr[i-1][j-1] == 0) {
				// printf("%d %d\n",i,j);
				++cnt;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}