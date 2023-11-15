#include <bits/stdc++.h>
using namespace std;

queue<pair<int,bool>> graph[32770];

void eulerpath(int node, int b) {
	for (;!graph[node].empty();) {
		int ni;
		bool bi;
		tie(ni,bi) = graph[node].front();
		graph[node].pop();
		eulerpath(ni,bi ? 1 : 0);
	}
	if (b == 1) {
		printf("1");
	} else if (b == 0) {
		printf("0");
	}
	return;
}

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < (1 << n-1); ++i) {
		graph[i].push({(i << 1)&((1 << n-1)-1),0});
		graph[i].push({(i << 1)&((1 << n-1)-1)^1,1});
		// printf("%d->%d\n%d->%d\n",i,(i << 1)&((1 << n-1)-1),i,(i << 1)&((1 << n-1)-1)^1);
	}
	eulerpath(0,-1);
	for (int i = 0; i < n-1; ++i) {
		printf("0");
	}
	return 0;
}