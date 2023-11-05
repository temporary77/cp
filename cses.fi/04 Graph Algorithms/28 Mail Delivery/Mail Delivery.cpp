#include <bits/stdc++.h>
using namespace std;

queue<pair<int,int>> graph[100001];
bool active[200001];
stack<int> stck;
bool parity[100001];
int crossed = 0;

void eulerpath(int node) {
	for (;!graph[node].empty();) {
		int ei, bi;
		tie(ei,bi) = graph[node].front();
		graph[node].pop();
		if (!active[ei])continue;
		active[ei] = 0;
		++crossed;
		eulerpath(bi);
	}
	stck.push(node);
}

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int a, b;
	int cnt = 0;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d",&a,&b);
		graph[a].push({i,b});
		graph[b].push({i,a});
		active[i] = 1;
		parity[a] ^= 1;
		if (parity[a]) {
			++cnt;
		} else {
			--cnt;
		}
		parity[b] ^= 1;
		if (parity[b]) {
			++cnt;
		} else {
			--cnt;
		}
	}
	// printf("%d\n",cnt);
	if (cnt > 0) {
		printf("IMPOSSIBLE");
		return 0;
	}
	eulerpath(1);
	if (crossed < m) {
		printf("IMPOSSIBLE");
		return 0;
	}
	for (;!stck.empty();) {
		printf("%d ",stck.top());
		stck.pop();
	}
	return 0;
}