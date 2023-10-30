#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
int parent[100001];
queue<int> que;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int ans = 0;
	parent[1] = -1;
	bool found = 0;
	que.push(1);
	for (;!que.empty();) {
		int t = que.size();
		++ans;
		for (int i = 0; i < t; ++i) {
			int x = que.front();
			que.pop();
			if (x == n) {
				found = 1;
				goto g;
			}
			for (auto it : graph[x]) {
				if (parent[it] == 0) {
					// printf("%d %d\n",x,it);
					parent[it] = x;
					que.push(it);
				}
			}
		}
	}
	g:;
	if (!found) {
		printf("IMPOSSIBLE");
		return 0;
	}
	printf("%d\n",ans);
	stack<int> stck;
	int x = n;
	for (;x != -1;) {
		stck.push(x);
		x = parent[x];
	}
	for (;!stck.empty();) {
		printf("%d ",stck.top());
		stck.pop();
	}
	return 0;
}