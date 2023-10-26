#include <bits/stdc++.h>
using namespace std;

int arr[200001];

int main() {
	int n;
	scanf("%d",&n);
	int max1 = INT_MIN;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
		max1 = max(max1,arr[i]);
	}
	int gcd = 0;
	for (int i = 0; i < n; ++i) {
		arr[i] = max1-arr[i];
		if (arr[i] == 0)continue;
		gcd = __gcd(gcd,arr[i]);
	}
	long long cnt = 0;
	for (int i = 0; i < n; ++i) {
		cnt += arr[i]/gcd;
	}
	printf("%I64d %d",cnt,gcd);
}