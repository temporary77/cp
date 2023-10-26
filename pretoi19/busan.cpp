#include <bits/stdc++.h>
using namespace std;

int arr[2][2005];
int dp1[2005][3001], dp2[2005][3001], dp3[2005][3001], dp4[2005][3001];

int main() {
	int n, m, s;
	scanf("%d%d%d",&n,&m,&s);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&arr[0][i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&arr[1][i]);
	}
	for (int i = 1; i <= n; ++i) {
		if (arr[0][i] < 0 && arr[1][i] < 0) {
			for (int j = 0; j <= m; ++j) {
				dp1[i][j] = dp1[i-1][j];
				dp2[i][j] = dp2[i-1][j];
			}
		} else if (arr[0][i] >= 0 && arr[1][i] >= 0) {
			for (int j = 0; j <= m; ++j) {
				dp1[i][j] = dp1[i-1][j]+arr[1][i];
				dp2[i][j] = dp2[i-1][j]+arr[0][i];
			}
		} else if (arr[0][i] < 0 && arr[1][i] >= 0) {
			for (int j = 0; j <= m; ++j) {
				dp1[i][j] = dp1[i-1][j];
				if (j-arr[0][i] <= m)dp1[i][j] = max(dp1[i][j],dp1[i-1][j-arr[0][i]]+arr[1][i]);
				dp2[i][j] = dp2[i-1][j];
			}
		} else if (arr[0][i] >= 0 && arr[1][i] < 0) {
			for (int j = 0; j <= m; ++j) {
				dp2[i][j] = dp2[i-1][j];
				if (j-arr[1][i] <= m)dp2[i][j] = max(dp2[i][j],dp2[i-1][j-arr[1][i]]+arr[0][i]);
				dp1[i][j] = dp1[i-1][j];
			}
		}
	}
	for (int i = n; i >= 1; --i) {
		if (arr[0][i] < 0 && arr[1][i] < 0) {
			for (int j = 0; j <= m; ++j) {
				dp3[i][j] = dp3[i+1][j];
				dp4[i][j] = dp4[i+1][j];
			}
		} else if (arr[0][i] >= 0 && arr[1][i] >= 0) {
			for (int j = 0; j <= m; ++j) {
				dp3[i][j] = dp3[i+1][j]+arr[1][i];
				dp4[i][j] = dp4[i+1][j]+arr[0][i];
			}
		} else if (arr[0][i] < 0 && arr[1][i] >= 0) {
			for (int j = 0; j <= m; ++j) {
				dp3[i][j] = dp3[i+1][j];
				if (j-arr[0][i] <= m)dp3[i][j] = max(dp3[i][j],dp3[i+1][j-arr[0][i]]+arr[1][i]);
				dp4[i][j] = dp4[i+1][j];
			}
		} else if (arr[0][i] >= 0 && arr[1][i] < 0) {
			for (int j = 0; j <= m; ++j) {
				dp4[i][j] = dp4[i+1][j];
				if (j-arr[1][i] <= m)dp4[i][j] = max(dp4[i][j],dp4[i+1][j-arr[1][i]]+arr[0][i]);
				dp3[i][j] = dp3[i+1][j];
			}
		}
	}
	int ans = 0;
	/*for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			printf("%d ",dp1[i][j]);
		}
		printf("\n");
	}*/
	if (s == 0) {
		int l = 0, r = 0;
		for (int i = 0; i <= m; ++i) {
			l = max(l,dp1[n][i]);
			r = max(r,dp2[n][i]);
		}
		ans = l+r;
	}
	if (s == 1) {
		for (int i = 1; i <= n; ++i) {
			int l = 0, r = 0;
			for (int j = 0; j <= m; ++j) {
				l = max(l,dp1[i][j]+dp4[i+1][m-j]);
				r = max(r,dp2[i][j]+dp3[i+1][m-j]);
			}
			ans = max(ans,l+r);
		}
	}
	printf("%d",ans);
	return 0;
}