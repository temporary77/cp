#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
int indegree[100001];
queue<int> que;
vector<int> vctr;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d",&a,&b);
		graph[a].push_back(b);
		++indegree[b];
	}
	for (int i = 1; i <= n; ++i) {
		if (indegree[i] == 0) {
			que.push(i);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (que.empty()) {
			printf("IMPOSSIBLE");
			return 0;
		}
		int x = que.front();
		que.pop();
		vctr.push_back(x);
		for (auto it : graph[x]) {
			--indegree[it];
			if (indegree[it] == 0) {
				que.push(it);
			}
		}
	}
	for (auto it : vctr) {
		printf("%d ",it);
	}
	return 0;
}