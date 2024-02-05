#include <bits/stdc++.h>
using namespace std;

int arr[100001];
long long qs[100001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		long long k;
		scanf("%d%lld",&n,&k);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld",&arr[i]);
			qs[i] = qs[i-1]+arr[i];
		}
		long long ans = qs[n]-k*n;
		for (int i = 1; i <= n; ++i) {
			long long cur = qs[i-1]-k*(i-1);
			int det = 2;
			for (int j = i; j <= n; ++j) {
				cur += arr[j]/det;
				det *= 2;
				if (det > 1e9)break;
			}
			// printf(">> %lld\n",cur);
			ans = max(ans,cur);
		}
		printf("%lld\n",ans);
	}
	return 0;
}