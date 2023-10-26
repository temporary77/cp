#include <bits/stdc++.h>
using namespace std;

multiset<int> graph[20];
bool visited[20];
int y;

bool recursion(int x) {
	if (visited[x] == 1) {
		return false;
	}
	if (x == y) {
		return true;
	}
	bool passer = 0;
	visited[x] = 1;
	for (auto it : graph[x]) {
		if (recursion(it))passer = 1;
	}
	return passer;
}

int main() {
	//freopen("test_input3.txt","r",stdin);
	int n, m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		graph[--a].insert(--b);
	}
	for (int i = 0; i < n; ++i) {
		//if (graph[i].empty())continue;
		printf("%d",i+1);
		for (auto it : graph[i]) {
			printf("->%d",it+1);
		}
		printf("\n");
	}
	int x;
	scanf("%d%d",&x,&y);
	--y;
	if (recursion(x)) {
		printf("Yes");
	} else {
		printf("No");
	}
	return 0;
}