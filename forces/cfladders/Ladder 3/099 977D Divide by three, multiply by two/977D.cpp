#include <bits/stdc++.h>
using namespace std;

long long arr[101];
vector<int> graph[101];
bool visited[101];
stack<int> stck;

void toposort(int node) {
	visited[node] = true;
	for (auto it : graph[node]) {
		if (visited[it])continue;
		toposort(it);
	}
	stck.push(node);
	return;
}

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld",&arr[i]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j)continue;
			if (arr[i]*2 == arr[j] || arr[j]*3 == arr[i]) {
				graph[i].push_back(j);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			toposort(i);
		}
	}
	for (;!stck.empty();) {
		printf("%lld ",arr[stck.top()]);
		stck.pop();
	}
	return 0;
}