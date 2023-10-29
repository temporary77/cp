#include <bits/stdc++.h>
using namespace std;

long long dp[20][10][2][2];
string str;

long long dfs(int n, int x, int l, int c) {
	if (n == 0)return 1;
	if (x != -1 && dp[n][x][l][c] != -1) {
		return dp[n][x][l][c];
	}
	int limit;
	if (!c) {
		limit = 9;
	} else {
		limit = str[str.size()-n]-'0';
	}
	long long res = 0;
	for (int i = 0; i <= limit; ++i) {
		if (x == i && !l)continue;
		res += dfs(n-1,i,l && i == 0,i == limit && c);
	}
	dp[n][x][l][c] = res;
	return res;
}

int main() {
	long long a, b;
	scanf("%lld%lld",&a,&b);
	--a;
	long long ansa;
	if (a < 0) {
		ansa = 0;
	} else {
		str = to_string(a);
		memset(dp,-1,sizeof(dp));
		ansa = dfs(str.size(),-1,1,1);
	}
	long long ansb;
	str = to_string(b);
	memset(dp,-1,sizeof(dp));
	ansb = dfs(str.size(),-1,1,1);
	// printf("%lld %lld %lld",ansa,ansb,ansb-ansa);
	printf("%lld",ansb-ansa);
	return 0;
}