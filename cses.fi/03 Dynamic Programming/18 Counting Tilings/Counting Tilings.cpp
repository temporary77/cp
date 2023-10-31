#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int dp[1001][1025];
bool check[1025][1025];

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	if ((n*m)%2) {
		printf("0");
		return 0;
	}
	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < (1 << n); ++j) {
			int flats = (~i)&(~j);
			int cur = -1;
			check[i][j] = 1;
			for (int k = 0; k < n; ++k) {
				if (flats&(1 << k)) {
					if (cur == -1) {
						cur = k;
					}
				} else {
					if (cur != -1) {
						if ((k-cur)&1) {
							check[i][j] = 0;
						}
						cur = -1;
					}
				}
			}
			if (cur != -1) {
				if ((n-cur)&1) {
					check[i][j] = 0;
				}
			}
		}
	}
	dp[0][0] = 1;
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < (1 << n); ++j) {
			int allvalid = ((1 << n)-1)^j;
			for (int k = allvalid; k > 0; k = (k-1)&allvalid) {
				if (check[k][j]) {
					dp[i][j] += dp[i-1][k];
					dp[i][j] %= mod;
				}
			}
			if (check[0][j]) {
				dp[i][j] += dp[i-1][0];
				dp[i][j] %= mod;
			}
		}
	}
	printf("%d",dp[m][0]);
	return 0;
}