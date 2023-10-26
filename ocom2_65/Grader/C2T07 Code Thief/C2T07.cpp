#include <bits/stdc++.h>
using namespace std;

int dp[402][400][401];
int arr[402][400];

int main() {
	//freopen("test_input.txt","r",stdin);
	int n, m, k;
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d",&arr[i][j]);
		}
	}
	for (int j = 0; j < m; ++j) {
		for (int kk = 0; kk <= k; ++kk) {
			dp[0][j][kk] = -1e7;
			dp[n+1][j][kk] = -1e7;
		}
	}
	for (int i = 1; i <= n; ++i) {
		dp[i][0][k] = arr[i][0];
		//printf("%d 0 %d - %d %d %d\n",i,k-1,arr[i][0],arr[i-1][0],arr[i+1][0]);
		dp[i][0][k-1] = arr[i][0]+max(arr[i-1][0],arr[i+1][0]);
		for (int j = k-2; j >= 0; --j) {
			dp[i][0][j] = -1e7;
		}
	}
	/*for (int kk = 0; kk <= k; ++kk) {
		for (int i = 0; i <= n+1; ++i) {
			for (int j = 0; j < m; ++j) {
				printf("%d ",dp[i][j][kk]);
			}
			printf("\n");
		}
		printf("----\n");
	}*/
	for (int j = 1; j < m; ++j) {
		for (int i = 1; i <= n; ++i) {
			for (int l = k; l >= 0; --l) {
				dp[i][j][l] = max(max(dp[i][j-1][l],dp[i-1][j-1][l]),dp[i+1][j-1][l]);
				if(l != k)dp[i][j][l] = max(max(dp[i][j][l],dp[i-1][j-1][l+1]+arr[i-1][j]),dp[i+1][j-1][l+1]+arr[i+1][j]);
				dp[i][j][l] += arr[i][j];
				//if (i == 1 && j == 1 && l == 2)printf("->_>_>_> %d %d %d %d %d %d %d %d %d\n",dp[i][j-1][l],dp[i-1][j-1][l],dp[i+1][j-1][l],arr[i][j],dp[i-1][j-1][l+1],arr[i-1][j],dp[i+1][j-1][l+1],arr[i+1][j],dp[i][j][l]);
			}
		}
		/*for (int kk = 0; kk <= k; ++kk) {
			for (int i = 1; i <= n; ++i) {
				for (int j = 0; j < m; ++j) {
					printf("%d ",dp[i][j][kk]);
				}
				printf("\n");
			}
			printf("%d %d----\n",j,kk);		
		}
		printf("----------------------------------------------- %d\n",j);*/
	}
	int max1 = INT_MIN;
	for (int i = 1; i <= n; ++i) {
		for (int j = k; j >= 0; --j) {
			max1 = max(max1,dp[i][m-1][j]);
		}
	}
	printf("%d",max1);
	return 0;
}

// (n,m,k) = max[ (n-1,m-1,k+1)+skipped tile   (n-1,m+1,k+1)+skipped tile     (n-1,m,k)     (n-1,m-1,k)     (n-1,m+1,k) ]