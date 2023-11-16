#include <bits/stdc++.h>
using namespace std;

long long qs[200001];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld",&qs[i]);
		qs[i] += qs[i-1];
	}
	printf("%d",lower_bound(qs+1,qs+n+1,(qs[n]+1)/2)-qs);
	return 0;
}