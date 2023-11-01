#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
int indegree[100001];
long long ans[100001];
queue<int> que;
const int mod = 1e9+7;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d",&a,&b);
		--a; --b;
		graph[a].push_back(b);
		++indegree[b];
	}
	for (int i = 0; i < n; ++i) {
		if (indegree[i] == 0) {
			que.push(i);
		}
	}
	ans[0] = 1;
	for (;!que.empty();) {
		int x = que.front();
		que.pop();
		for (auto it : graph[x]) {
			ans[it] += ans[x];
			ans[it] %= mod;
			--indegree[it];
			if (indegree[it] == 0) {
				if (it == n-1) {
					printf("%lld",ans[n-1]);
					return 0;
				}
				que.push(it);
			}
		}
	}
	printf("0");
	return 0;
}