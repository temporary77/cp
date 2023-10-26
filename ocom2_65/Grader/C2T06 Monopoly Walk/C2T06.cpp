#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int arr[1000005];

int main() {
	int n, k;
	scanf("%d%d",&n,&k);
	arr[0] = 1;
	long long sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum += arr[i-1]%mod;
		if (i-k-1 >= 0)sum -= arr[i-k-1]%mod;
		arr[i] = sum%mod;
	}
	if (arr[n] < 0)arr[n] += mod;
	printf("%d",arr[n]);
	return 0;
}