#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];

int main() {
	int n, k;
	scanf("%d%d",&n,&k);
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < k; ++j) {
			scanf("%d",&arr[i][j]);
		}
	}
	printf("0\n%d\n",arr[0][1]);
	for (int i = 2; i < k; ++i) {
		int a[2] = {arr[0][i],n-arr[0][i]};
		int b[2] = {arr[0][1]+arr[1][i],(arr[0][1]-arr[1][i]+n)%n};
		for (auto it : a) {
			for (auto it2 : b) {
				//printf("%d %d\n",it,it2);
				if (it == it2) {
					printf("%d\n",it);
					goto g;
				}
			}
		}
		g:;
	}
	return 0;
}