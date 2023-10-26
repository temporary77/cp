#include <bits/stdc++.h>
using namespace std;

int dp[10][10][2];

// 0  1  2  3  4  5  6  7  8  9
// XX MM BM FM MB BB FB MF BF FF

int arr[3][10] = {{1,1,1,1,2,2,2,3,3,3},{5,4,4,4,5,5,5,6,6,6},{9,7,7,7,8,8,8,9,9,9}};
int scr[3][10] = {{1,1,2,2,2,2,3,2,3,2},{1,2,2,3,2,1,2,3,2,2},{1,2,3,2,3,2,2,2,2,1}};

int main() {
	cin.tie(nullptr);
	int n;
	scanf("%d",&n);
	string str;
	cin >> str;
	if (str[0] == 'M') {
		dp[1][0][0] = 1;		
	} else if (str[0] == 'B') {
		dp[5][0][0] = 1;
	} else if (str[0] == 'F') {
		dp[9][0][0] = 1;
	}
	int d;
	int ans = 1;
	int i = 1;
	for (int l = 1; l < n; ++l) {
		if (str[l] == 'M')d = 0;
		else if (str[l] == 'B')d = 1;
		else if (str[l] == 'F')d = 2;
		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k < 10; ++k) {
				if (dp[j][k][i^1] == 0)continue;
				dp[arr[d][j]][k][i] = max(dp[arr[d][j]][k][i],dp[j][k][i^1]+scr[d][j]);
				dp[j][arr[d][k]][i] = max(dp[j][arr[d][k]][i],dp[j][k][i^1]+scr[d][k]);
				if (l == n-1)ans = max(max(ans,dp[arr[d][j]][k][i]),dp[j][arr[d][k]][i]);
				dp[j][k][i^1] = 0;
			}
		}
		/*for (int j = 0; j < 10; ++j) {
			for (int k = 0; k < 10; ++k) {
				printf("%d ",dp[j][k][i]);
			}
			printf("\n");
		}
		printf("--------------------------------\n");*/
		i ^= 1;
	}
	printf("%d",ans);
	return 0;
}