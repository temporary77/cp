#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	int arr[n];
	long long sum = 0;
	int max1 = INT_MIN;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
		max1 = max(max1,arr[i]);
		sum += arr[i];
	}
	if (max1 > sum-max1) {
		printf("%d",max1*2);
	} else {
		printf("%lld",sum);
	}
	return 0;
}