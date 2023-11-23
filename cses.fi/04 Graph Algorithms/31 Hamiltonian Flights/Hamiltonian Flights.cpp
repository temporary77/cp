#include <bits/stdc++.h>
using namespace std;
 
vector<int> graph[21];
int ans[21][1050000];
const int mod = 1e9+7;
int n, m;
 
int main() {
	scanf("%d%d",&n,&m);
	int a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d",&a,&b);
		--a;
		--b;
		graph[a].push_back(b);
	}
	ans[0][1] = 1;
	for (int i = 1; i < (1 << n); ++i) {
		if (!(i&1))continue;
		if (i&(1 << n-1) && i != (1 << n)-1)continue;
		for (int j = 0; j < n; ++j) {
			if (!(i&(1 << j)))continue;
			for (auto it : graph[j]) {
				if (!(i&(1 << it))) {
					ans[it][i^(1 << it)] += ans[j][i];
					ans[it][i^(1 << it)] %= mod;
				}
			}
		}
	}
	printf("%d",ans[n-1][(1 << n)-1]);
	return 0;
}
