#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("test_input3.txt","r",stdin);
	int n, m;
	scanf("%d%d",&n,&m);
	multiset<int> graph[n];
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		graph[--a].insert(--b);
		graph[b].insert(a);
	}
	int k;
	scanf("%d",&k);
	--k;
	int prev = k, start = k, end = k, path = 0;
	bool valid = 1, visited[n] = {0}, so = 0;
	visited[k] = 1;
	for (;;) {
		scanf("%d",&k);
		if (k == -1)break;
		if (valid == 0) {
			scanf("%d",&k);
			if (k == -1)break;
			continue;
		}
		--k;
		if (graph[prev].find(k) != graph[prev].end()) {
			end = k;
			++path;
			if (visited[k] == 1) {
				so = 1;
			}
			visited[k] = 1;
			prev = k;
		} else {
			valid = 0;
		}
	}
	if (so == 0) {
		printf("%d %d %d NO",start+1,end+1,path);
	} else {
		printf("%d %d %d YES",start+1,end+1,path);
	}
	return 0;
}