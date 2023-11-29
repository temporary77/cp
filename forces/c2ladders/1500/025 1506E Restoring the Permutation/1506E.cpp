#include <bits/stdc++.h>
using namespace std;

int arr[200001];
bool taken[200001];
int warp[200001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i]);
		}
		fill(taken+1,taken+n+1,false);
		int idx = 1;
		for (int i = 0; i < n; ++i) {
			if (i == 0 || arr[i] != arr[i-1]) {
				printf("%d ",arr[i]);
				taken[arr[i]] = true;
			} else {
				for (;taken[idx];)++idx;
				printf("%d ",idx);
				taken[idx] = true;
			}
		}
		printf("\n");
		fill(taken+1,taken+n+1,false);
		fill(warp+1,warp+n+1,-1);
		for (int i = 0; i < n; ++i) {
			if (warp[arr[i]] == -1)warp[arr[i]] = arr[i];
			printf("%d ",warp[arr[i]]);
			taken[warp[arr[i]]] = true;
			--warp[arr[i]];
			for (;taken[warp[arr[i]]];) {
				if (warp[warp[arr[i]]] != -1) {
					warp[arr[i]] = warp[warp[arr[i]]];
				} else {
					--warp[arr[i]];
				}
			}
		}
		printf("\n");
	}
	return 0;
}