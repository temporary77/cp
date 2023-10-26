#include <bits/stdc++.h>
using namespace std;

long long arr[10000005];

int main() {
	int n;
	scanf("%d",&n);
	long long k;
	long long max1 = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld",&k);
		arr[i] = max(k,arr[i-1]+k);
		max1 = max(max1,arr[i]);
	}
	printf("%lld",max1);
	return 0;
}