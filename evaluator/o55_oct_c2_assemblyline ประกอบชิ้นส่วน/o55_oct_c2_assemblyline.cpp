#include <bits/stdc++.h>
using namespace std;

char arr[26];
int table[26][26];
int res[26][26];
int dp[201][201][26];

int main() {
	cin.tie(NULL);
	for (;;) {
		int k1;
		scanf("%d",&k1);
		if (k1 == 0)return 0;
		char c;
		unordered_map<char,int> mp;
		for (int i = 0; i < k1; ++i) {
			scanf(" %c",&c);
			arr[i] = c;
			mp[c] = i;
		}
		int t;
		for (int i = 0; i < k1; ++i) {
			for (int j = 0; j < k1; ++j) {
				scanf(" %d%*c%c",&t,&c);
				table[i][j] = t;
				res[i][j] = mp[c];
			}
		}
		int n;
		scanf("%d",&n);
		string str;
		for (int t = 0; t < n; ++t) {
			cin >> str;
			int min1 = INT_MAX;
			int ansc = 100;
			for (int i = 0; i < str.size(); ++i) {
				for (int j = i; j < str.size(); ++j) {
					for (int c1 = 0; c1 < k1; ++c1) {
						dp[i][j][c1] = INT_MAX;
					} 
				}
			}
			for (int i = 0; i < str.size(); ++i) {
				dp[i][i][mp[str[i]]] = 0;
			}
			for (int i = 1; i < str.size(); ++i) {
				for (int j = 0; j < str.size()-i; ++j) {
					for (int k = j; k < j+i; ++k) {
						for (int c1 = 0; c1 < k1; ++c1) {
							for (int c2 = 0; c2 < k1; ++c2) {
								if (dp[j][k][c1] == INT_MAX || dp[k+1][j+i][c2] == INT_MAX)continue;
								int newc = res[c1][c2];
								//printf("[%d,%d]+[%d,%d] %d %d %d %d %d\n",j,k,k+1,j+i,c1,c2,newc,dp[j][j+i][newc],dp[j][k][c1]+dp[k+1][j+i][c2]+table[c1][c2]);
								if (dp[j][j+i][newc] >= dp[j][k][c1]+dp[k+1][j+i][c2]+table[c1][c2]) {
									dp[j][j+i][newc] = dp[j][k][c1]+dp[k+1][j+i][c2]+table[c1][c2];
								}	
							}
						} 
					}
				}
			}
			for (int newc = 0; newc < k1; ++newc) {
				if (dp[0][str.size()-1][newc] <= min1) {
					min1 = dp[0][str.size()-1][newc];
					//printf("%d\n",ansc);
				}
			}
			for (int newc = 0; newc < k1; ++newc) {
				if (dp[0][str.size()-1][newc] == min1) {
					ansc = min(ansc,newc);
				}
			}
			printf("%d-%c\n",min1,arr[ansc]);
		}
		printf("\n");
	}
	return 0;
}