#include <bits/stdc++.h>
using namespace std;

vector<int> graph[200001];
vector<pair<int,int>> queries[200001];
int ans[200001];
int bs[200001];

void dfs(int node, int cur) {
	bs[cur] = node;
	for (auto it : queries[node]) {
		if (cur-it.first >= 0) {
			ans[it.second] = bs[cur-it.first];
		} else {
			ans[it.second] = -1;
		}
	}
	for (auto it : graph[node]) {
		dfs(it,cur+1);
	}
	return;
}

int main() {
	int n, q;
	scanf("%d%d",&n,&q);
	for (int i = 2; i <= n; ++i) {
		int a;
		scanf("%d",&a);
		graph[a].push_back(i);
	}
	for (int i = 0; i < q; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		queries[a].push_back({b,i});
	}
	dfs(1,0);
	for (int i = 0; i < q; ++i) {
		printf("%d\n",ans[i]);
	}
	return 0;
}