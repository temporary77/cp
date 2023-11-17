#include <bits/stdc++.h>
using namespace std;

int arr[51];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		long long sum[2] = {0,0};
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i]);
			sum[i&1] += arr[i];
		}
		bool d = sum[0] < sum[1];
		for (int i = 0; i < n; ++i) {
			if (i&1 ^ d) {
				printf("1 ");
			} else {
				printf("%d ",arr[i]);
			}
		}
		printf("\n");
	}
	return 0;
}