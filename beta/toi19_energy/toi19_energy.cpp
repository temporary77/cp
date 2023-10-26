#include <bits/stdc++.h>
using namespace std;

int arr[301];
int qs[301];
long long dp[301][301][10];
const int mod = 1e9+7;

int qsum(int a, int b) {
	return qs[b]-qs[a-1];
}

int main() {
	int n, k, d;
	scanf("%d%d%d",&n,&k,&d);
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&arr[i]);
		sum += arr[i];
		qs[i] = sum;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			dp[i][j][1] = 1;
		}
	}
	for (int i = 2; i <= k; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int l = j+pow(2,i-1)-1; l <= n; ++l) {
				for (int m = j+1; m <= l; ++m) {
					if (abs(qsum(j,m-1)-qsum(m,l)) <= d) {
						//printf("%d %d %d %d ",i,j,m,l);
						dp[j][l][i] += (dp[j][m-1][i-1]*dp[m][l][i-1])%mod;
						dp[j][l][i] %= mod;
						//printf("%d\n",dp[j][l][i]);
					}
				}
			}
		}
	}
	printf("%lld",dp[1][n][k]%mod);
	return 0;
}