#include <bits/stdc++.h>
using namespace std;

set<int> graph[100005];
bool visited[100005];

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		graph[--a].insert(--b);
		graph[b].insert(a);
	}
	int k;
	scanf("%d",&k);
	queue<int> que;
	que.push(--k);
	visited[k] = 1;
	for (;!que.empty();) {
		printf("%d ",que.front()+1);
		for (auto it : graph[que.front()]) {
			if (visited[it] == 0) {
				que.push(it);
				visited[it] = 1;
			}
		}
		que.pop();
	}
	return 0;
}