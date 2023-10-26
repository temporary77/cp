#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	multiset<int> graph[n];
	int arr[n] = {0};
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		graph[--a].insert(--b);
		++arr[b];
	}
	for (int i = 0; i < n; ++i) {\
		printf("%d",i+1);
		for (auto it : graph[i]) {
			printf("->%d",it+1);
		}
		printf("\n");
	}
	for (int i = 0; i < n; ++i) {\
		printf("%d %lu\n",arr[i],graph[i].size());
	}
	return 0;
}