#include <bits/stdc++.h>
using namespace std;

int arr[301][301];
int nghbrs[301];

int main() {
	int n, t;
	scanf("%d%d",&n,&t);
	for (int i = 0; i < n; ++i) {
		int min1 = INT_MAX;
		for (int j = 0; j < n; ++j) {
			scanf("%d",&arr[i][j]);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			bool check = 1;
			for (int k = 0; k < n; ++k) {
				if (k == i || k == j)continue;
				if (arr[i][j] == arr[i][k]+arr[k][j]) {
					check = 0;
					//printf("consider %d %d %d\n",i+1,k+1,j+1);
				}
			}
			if (check) {
				++nghbrs[i];
				++nghbrs[j];
			}
		}
	}
	/*for (int i = 0; i < n; ++i) {
		printf("%d ",nghbrs[i]);
	}
	printf("\n");*/
	for (int i = 0; i < n; ++i) {
		if (nghbrs[i] > 2) {
			printf("%d\n",i+1);
			if (t == 2) {
				printf("%d\n",nghbrs[i]);
			}
		}
	}
	return 0;
}