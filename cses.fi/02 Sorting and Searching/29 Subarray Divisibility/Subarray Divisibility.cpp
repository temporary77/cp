#include <bits/stdc++.h>
using namespace std;

long long arr[200002];
int n;

int main() {
	scanf("%d",&n);
	int k;
	int sum = 0;
	long long cnt = 0;
	++arr[0];
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		sum += k;
		sum %= n;
		if (sum < 0)sum += n;
		++arr[sum];
	}
	for (int i = 0; i < n; ++i) {
		cnt += arr[i]*(arr[i]-1)/2;
	}
	printf("%lld",cnt);
	return 0;
}