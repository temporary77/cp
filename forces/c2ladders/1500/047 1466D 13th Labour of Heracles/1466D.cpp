#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

pair<int,int> nodes[100001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		long long cur = 0;
		fill(nodes+1,nodes+n+1,(pair<int,int>){0,0});
		for (int i = 1; i <= n; ++i) {
			scanf("%d",&nodes[i].f);
			cur += nodes[i].f;
		}
		for (int i = 0; i < n-1; ++i) {
			int u, v;
			scanf("%d%d",&u,&v);
			++nodes[u].s;
			++nodes[v].s;
		}
		sort(nodes+1,nodes+n+1,greater<pair<int,int>>());
		printf("%lld ",cur);
		for (int i = 1; i <= n; ++i) {
			for (;nodes[i].s > 1;) {
				cur += nodes[i].f;
				printf("%lld ",cur);
				--nodes[i].s;
			}
		}
		printf("\n");
	}
	return 0;
}