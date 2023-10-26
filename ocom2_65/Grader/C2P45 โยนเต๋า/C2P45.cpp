#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, f, sum;
	scanf("%d%d%d",&n,&f,&sum);
	long long arr[sum+1];
	for (int i = 0; i < sum+1; ++i) {
		arr[i] = 0;
	}
	for (int i = 1; i <= f; ++i) {
		arr[i] = 1;
	}
	for (int i = 1; i < n; ++i) {
		for (int j = f*i+f-1; j >= 1; --j) {
			if (j > sum)continue;
			for (int k = 1; k < f; ++k) {
				if (j-k <= 0)continue;
				arr[j] += arr[j-k];
			}
		}
	}
	printf("%lld",arr[sum-n+1]);
	return 0;
}