#include <bits/stdc++.h>
using namespace std;

vector<int> graph[200001];
long long hs[200001];
int size1[200001];
long long ans[200001];

int findsize(int node, int pa) {
	int sz = 1;
	for (auto it : graph[node]) {
		if (it == pa)continue;
		sz += findsize(it,node);
	}
	size1[node] = sz;
	return sz;
}

long long precompute(int node, int pa) {
	long long sum = 0;
	for (auto it : graph[node]) {
		if (it == pa)continue;
		sum += precompute(it,node);
	}
	hs[node] = sum;
	return sum+size1[node];
}

void dfs(int node, int pa, long long behind, int szz) {
	ans[node] = hs[node]+behind;
	for (auto it : graph[node]) {
		if (it == pa)continue;
		//printf("%d %d %lld\n",it,node,behind);
		int nsz = szz+(size1[node]-size1[it]);
		dfs(it,node,behind+hs[node]-hs[it]-size1[it]+nsz,nsz);
	}
	return;
}

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	findsize(1,-1);
	precompute(1,-1);
	dfs(1,-1,0,0);
	// for (int i = 1; i <= n; ++i) {
	// 	printf("%lld ",hs[i]);
	// }
	// printf("\n");
	// for (int i = 1; i <= n; ++i) {
	// 	printf("%lld ",size1[i]);
	// }
	// printf("\n");
	for (int i = 1; i <= n; ++i) {
		printf("%lld ",ans[i]);
	}
	return 0;
}