#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> graph[100001];
bool isstorage[100001];
vector<int> vctr;

int main() {
	int n, m, k;
	scanf("%d%d%d",&n,&m,&k);
	int u, v, l;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d",&u,&v,&l);
		graph[u].push_back({v,l});
		graph[v].push_back({u,l});
	}
	int c;
	for (int i = 0; i < k; ++i) {
		scanf("%d",&c);
		isstorage[c] = 1;
		vctr.push_back(c);
	}
	int ans = INT_MAX;
	for (auto it : vctr) {
		for (auto it2 : graph[it]) {
			if (isstorage[it2.first])continue;
			ans = min(ans,it2.second);
		}
	}
	if (ans == INT_MAX)ans = -1;
	printf("%d",ans);
	return 0;
}