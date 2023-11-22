#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		int max1 = 0;
		long long ttl = 0;
		for (int i = 0; i < n; ++i) {
			int a;
			scanf("%d",&a);
			max1 = max(max1,a);
			ttl += a;
		}
		// long long ans = max1*(long long)(n-1)-ttl;
		// if (ans < 0)ans += ceil((-1*ans)/(double)(n-1))*(n-1);
		long long ans = max(max1,(int)ceil(ttl/(double)(n-1)))*(long long)(n-1)-ttl;
		printf("%lld\n",ans);
	}
	return 0;
}