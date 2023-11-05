#include <bits/stdc++.h>
using namespace std;

vector<int> graph[200001];
int disc[200001];
int low[200001];
int scc[200001];
int ans[100001];
stack<int> stck;

int idx = 0;
int timer = 0;

void tarjan(int node) {
	++timer;
	disc[node] = timer;
	low[node] = timer;
	stck.push(node);
	for (auto it : graph[node]) {
		if (disc[it] && !scc[it]) {
			low[node] = min(low[node],disc[it]);
		} else if (!disc[it]) {
			tarjan(it);
			low[node] = min(low[node],low[it]);
		}
	}
	if (low[node] == disc[node]) {
		++idx;
		for (;!stck.empty();) {
			int x = stck.top();
			stck.pop();
			scc[x] = idx;
			// printf("%d %d\n",idx,x);
			if (x == node)break;
		}
	}
	return;
}

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int a, b;
	char ca, cb;
	for (int i = 0; i < n; ++i) {
		scanf(" %c%d %c%d",&ca,&a,&cb,&b);
		if (ca == '-') {
			a += 100000;
		}
		if (cb == '-') {
			b += 100000;
		}
		int ai = (a+100000-1)%200000+1;
		int bi = (b+100000-1)%200000+1;
		graph[ai].push_back(b);
		graph[bi].push_back(a);
	}
	for (int i = 1; i <= m; ++i) {
		if (!disc[i]) {
			tarjan(i);
		}
		if (!disc[i+100000]) {
			tarjan(i+100000);
		}
	}
	// for (int i = 1; i <= m; ++i) {
	// 	if (!disc[i]) {
	// 		tarjan(i);
	// 	}
	// }
	// for (int i = 100001; i <= 100000+m; ++i) {
	// 	if (!disc[i]) {
	// 		tarjan(i);
	// 	}
	// }
	for (int i = 1; i <= m; ++i) {
		if (scc[i] == scc[i+100000]) {
			printf("IMPOSSIBLE");
			return 0;
		} else if (scc[i] > scc[i+100000]) {
			ans[i] = -1;
		} else {
			ans[i] = 1;
		}
	}
	for (int i = 1; i <= m; ++i) {
		if (ans[i] == 1) {
			printf("+ ");
		} else {
			printf("- ");
		}
	}
	return 0;
}