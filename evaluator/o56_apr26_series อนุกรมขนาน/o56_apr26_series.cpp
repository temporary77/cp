#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1001];
int color[1001];
bool tobe[3][1001];
int n, c = 1;

bool check(int node, int c1) {
	for (auto it : graph[node]) {
		if (color[it] == c1) {
			return 0;
		}
	}
	return 1;
}

bool graphcolor(int node) {
	if (node == n) {
		return 1;
	}
	for (int i = 1; i <= c; ++i) {
		if (check(node,i)) {
			color[node] = i;
			if (graphcolor(node+1)) {
				return 1;
			}
			color[node] = 0;
		}
		if (i == 1) {
			c = 2;
		}
		if (i == 2) {
			c = 3;
		}
	}
	return 0;
}
	
int main() {
	int m, p;
	scanf("%d%d%d",&n,&m,&p);
	int a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d",&a,&b);
		--a;
		--b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		//printf("%d %d\n",a,b);
	}
	graphcolor(0);
	printf("%d\n",c);
	for (int i = 0; i < n; ++i) {
		printf("%d\n",color[i]);
	}
	return 0;
}