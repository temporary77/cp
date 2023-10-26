#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("test_input3.txt","r",stdin);
	//for (int j = 0; j < 5; ++j) {
	int n, m;
	scanf("%d%d",&n,&m);
	map<int,int> graph[n];
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d%d%d",&a,&b,&c);
		graph[--a][--b] = c;
		graph[b][a] = c;
	}
	int k;
	scanf("%d",&k);
	--k;
	int prev = k, path = 0, path2 = 0;
	bool valid = 1, visited[n] = {0};
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
		//printf("prev %d k %d path %d path2 %d\n",prev,k,path,path2);
		if (graph[prev][k] != 0) {
			++path;
			path2 += graph[prev][k];
			if (visited[k] == 1) {
				valid = 0;
			}
			visited[k] = 1;
			prev = k;
		} else {
			valid = 0;
		}
	}
	printf("%d %d",path,path2);
	//}
	return 0;
}