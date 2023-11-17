#include <bits/stdc++.h>
using namespace std;

int degree[400001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int a, b, k;
		scanf("%d%d%d",&a,&b,&k);
		fill(degree,degree+a+b,0);
		for (int i = 0; i < k; ++i) {
			int ai;
			scanf("%d",&ai);
			++degree[--ai];
		}
		for (int i = 0; i < k; ++i) {
			int bi;
			scanf("%d",&bi);
			++degree[--bi+a];
		}
		//ttl-d[a]-d[b]+1;
		long long ans = (long long)k*(k-1)/2;
		for (int i = 0; i < a+b; ++i) {
			ans -= (long long)degree[i]*(degree[i]-1)/2;
		}
		// long long ans = (long long)k*(k+1);
		// for (int i = 0; i < a+b; ++i) {
		// 	ans -= (long long)degree[i]*(degree[i]);
		// }
		printf("%lld\n",ans>>1);
	}
	return 0;
}