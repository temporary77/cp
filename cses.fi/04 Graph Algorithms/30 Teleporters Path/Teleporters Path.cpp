#include <bits/stdc++.h>
using namespace std;

queue<int> graph[100001];
int indegree[100001];
int outdegree[100001];
stack<int> stck;
int crossed = 0;

void eulercircuit(int node) {
	for (;!graph[node].empty();) {
		int b = graph[node].front();
		graph[node].pop();
		++crossed;
		eulercircuit(b);
	}
	stck.push(node);
	return;
}

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d",&a,&b);
		graph[a].push(b);
		++indegree[b];
		++outdegree[a];
	}
	if (outdegree[1]-indegree[1] != 1 || indegree[n]-outdegree[n] != 1) {
		printf("IMPOSSIBLE");
		return 0;
	}
	for (int i = 2; i <= n-1; ++i) {
		if (indegree[i] != outdegree[i]) {
			printf("IMPOSSIBLE");
			return 0;
		}
	}
	eulercircuit(1);
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