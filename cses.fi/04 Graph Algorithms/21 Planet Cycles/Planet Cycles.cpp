#include <bits/stdc++.h>
using namespace std;

int nxt[200001];
int visited[200001];
int ans[200001];

int mode;
int curlength;
vector<int> vctr;

void dfs(int node) {
	visited[node] = 1;
	if (visited[nxt[node]] == 1) {
		vctr.push_back(nxt[node]);
		visited[nxt[node]] = 2;
		++curlength;
		mode = 1;
	} else if (visited[nxt[node]] == 0) {
		dfs(nxt[node]);
	} else if (visited[nxt[node]] == 3) {
		curlength = ans[nxt[node]]+1;
		mode = 2;
	}
	if (mode == 1) {
		if (visited[node] == 2) {
			for (auto it : vctr) {
				ans[it] = curlength;
			}
			++curlength;
			vctr.clear();
			mode = 2;
		} else {
			++curlength;
			vctr.push_back(node);
		}
	} else if (mode == 2) {
		ans[node] = curlength;
		++curlength;
	}
	visited[node] = 3;
	return;
}

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&nxt[i]);
	}
	for (int i = 1; i <= n; ++i) {
		if (visited[i] == 0) {
			mode = 0;
			curlength = 0;
			dfs(i);
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ",ans[i]);
	}
	return 0;
}