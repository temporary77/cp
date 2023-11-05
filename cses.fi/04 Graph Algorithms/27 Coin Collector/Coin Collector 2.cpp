#include <bits/stdc++.h>
using namespace std;

int arr[100001];
vector<int> graph1[100001];
vector<int> graph2[100001];
vector<int> graph3[100001];
bool visited[100001];
bool visited3[100001];
int scc[100001];
long long scck[100001];
long long sccans[100001];
stack<int> stck;

void dfs(int node) {
	visited[node] = 1;
	for (auto it : graph1[node]) {
		if (!visited[it]) {
			dfs(it);
		}
	}
	stck.push(node);
	return;
}

int idx = 0;

void kosaraju(int node) {
	scc[node] = idx;
	scck[idx] += arr[node];
	for (auto it : graph2[node]) {
		if (!scc[it]) {
			kosaraju(it);
		} else if (scc[it] != idx) {
			graph3[scc[it]].push_back(idx);
			// printf("%d->%d\n",scc[it],idx);
		}
	}
	return;
}

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&arr[i]);
	}
	int a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d",&a,&b);
		graph1[a].push_back(b);
		graph2[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	for (;!stck.empty();) {
		int x = stck.top();
		stck.pop();
		if (!scc[x]) {
			++idx;
			kosaraju(x);
			// printf("%d = %d\n",idx,scck[idx]);
		}
	}
	// for (int i = 1; i <= n; ++i) {
	// 	printf("%d ",scc[i]);
	// }
	// printf("\n");
	long long ans = 0;
	for (int i = idx; i > 0; --i) {
		sccans[i] = 0;
		for (auto it : graph3[i]) {
			// if (sccans[it] == 0)printf("ABORT\n");
			sccans[i] = max(sccans[i],sccans[it]);
		}
		sccans[i] += scck[i];
		ans = max(ans,sccans[i]);
	}
	printf("%lld",ans);
	return 0;
}