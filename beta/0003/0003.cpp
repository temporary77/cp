#include <bits/stdc++.h>
using namespace std;

int arr[101][101], brr[101][101];

int main() {
	int m, n;
	scanf("%d%d",&m,&n);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d",&arr[i][j]);
		}
	}
	int k;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d",&k);
			printf("%d ",arr[i][j]+k);
		}
		printf("\n");
	}
	return 0;
}