#include <bits/stdc++.h>
using namespace std;

int arr[100001];
int scc[100001];
long long sccans[100001];
vector<int> graph[100001];
int disc[100001];
int low[100001];
long long maxconnected[100001];
stack<int> stck;

int timer = 0;
int idx = 0;
long long ans = 0;

void tarjan(int node) {
	++timer;
	disc[node] = timer;
	low[node] = timer;
	stck.push(node);
	maxconnected[node] = 0;
	for (auto it : graph[node]) {
		if (disc[it] && !scc[it]) {
			low[node] = min(low[node],disc[it]);
		} else if (!disc[it]) {
			tarjan(it);
			low[node] = min(low[node],low[it]);
		}
		if (scc[it]) {
			maxconnected[node] = max(maxconnected[node],sccans[scc[it]]);
		}
	}
	if (low[node] == disc[node]) {
		++idx;
		long long max1 = 0;
		for (;!stck.empty();) {
			int x = stck.top();
			stck.pop();
			scc[x] = idx;
			max1 = max(max1,maxconnected[x]);
			sccans[idx] += arr[x];
			if (x == node) {
				sccans[idx] += max1;
				// // printf("%d %d\n",idx,sccans[idx]);
				ans = max(ans,sccans[idx]);
				break;
			}
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
		graph[a].push_back(b);
	}
	for (int i = 1; i <= n; ++i) {
		if (!disc[i]) {
			tarjan(i);
		}
	}
	printf("%lld",ans);
	return 0;
}