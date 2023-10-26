#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	long long sum = 0;
	int max1 = INT_MIN;
	int k;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		sum += k;
		max1 = max(max1,k);
	}
	if (max1*2 > sum)printf("%d",max1*2);
	else printf("%lld",sum);
	return 0;
}