#include <bits/stdc++.h>
using namespace std;

long long dp1[1000001];
long long dp2[1000001];
// long long dp3[1000001];
const int mod = 1e9+7;

int main() {
	// dp1[0] = 1;
	// dp2[0] = 1;
	// dp3[0] = 1;
	// // dp1 stores amount of ways to build tiles that end both columns at index i
	// // dp2 stores every possible way to build tiles that may or may not end at index i without holes
	// // dp3 stores amount of ways to build tiles that end both columns at index 0 through i (qs of dp1)
	// for (int i = 1; i <= 1000000; ++i) {
	// 	dp1[i] = dp3[i-1]+dp2[i-1];
	// 	dp1[i] %= mod;
	// 	dp3[i] = dp3[i-1]+dp1[i];
	// 	dp2[i] = dp2[i-1];
	// 	dp2[i] += dp2[i-1]*3+dp3[i-1];
	// 	dp2[i] %= mod;
	// 	// printf("%d %lld %lld %lld\n",i,dp1[i],dp2[i],dp3[i]);
	// }
	dp1[1] = 1;
	dp2[1] = 1;
	// dp1 stores amount of ways to build tiles that end both columns at index i
	// such that last 2 tiles are part of same block
	// dp2 similiar except that last 2 tiles are not part of the same block
	for (int i = 2; i <= 1000000; ++i) {
		dp1[i] = dp1[i-1]*2+dp2[i-1];
		dp2[i] = dp2[i-1]*4+dp1[i-1];
		dp1[i] %= mod;
		dp2[i] %= mod;
	}
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		printf("%lld\n",(dp1[n]+dp2[n])%mod);
	}
}