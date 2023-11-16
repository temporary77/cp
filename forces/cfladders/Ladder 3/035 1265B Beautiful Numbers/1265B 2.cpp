#include <bits/stdc++.h>
using namespace std;

int idx[200001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		int k;
		for (int i = 0; i < n; ++i) {
			scanf("%d",&k);
			idx[k] = i;
		}
		int min1 = n;
		int max1 = -1;
		for (int i = 1; i <= n; ++i) {
			min1 = min(min1,idx[i]);
			max1 = max(max1,idx[i]);
			if (max1-min1+1 == i) {
				printf("1");
			} else {
				printf("0");
			}
		}
		printf("\n");
	}
	return 0;
}