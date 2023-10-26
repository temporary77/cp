#include <bits/stdc++.h>
using namespace std;

#define int long long

int dp[1001][513];
vector<int> graph[513];

/*

X 0
0 X
0 X
X 0
X 0
0 X
X 0

*/

signed main() {
	int n, m;
	scanf("%lld%lld",&n,&m);
	int capn = pow(2,n)-1;
	for (int i = 0; i <= capn; ++i) {
		for (int j = 0; j <= capn; ++j) {
			int a = i;
			int b = j;
			bool state = 0;
			bool check = 1;
			for (int k = 0; k < n; ++k, a /= 2, b /= 2) {
				if (state) {
					if (a%2 == 1 || b%2 == 1) {
						check = 0;
						break;
					} else {
						state = 0;
					}
					continue;
				}
				if (a%2 == 1) {
					if (b%2 != 0) {
						check = 0;
						break;
					}
				} else if (a%2 == 0) {
					if (b%2 == 0) {
						state = 1;
					}
				}
			}
			if (check && !state) {
				graph[i].push_back(j);
			}
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j <= capn; ++j) {
			if (dp[i][j] == 0)continue;
			for (auto it : graph[j]) {
				dp[i+1][it] += dp[i][j];
			}
		}
		//printf("%lld\n",dp[i+1][0]);
	}
	printf("%lld",dp[m][0]);
	return 0;
}