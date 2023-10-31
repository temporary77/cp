#include <bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int>> edges;
long long voiddist[2501];
int parent[2501];
bool check[2501];
stack<int> stck;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d",&a,&b,&c);
		edges.push_back({a,b,c});
	}
	int x = -1;
	for (int i = 0; i < n; ++i) {
		for (auto it : edges) {
			tie(a,b,c) = it;
			if (voiddist[b] > voiddist[a]+c) {
				voiddist[b] = voiddist[a]+c;
				parent[b] = a;
				if (i == n-1) {
					x = b;
					break;
				}
			}
		}
	}
	if (x == -1) {
		printf("NO");
		return 0;
	}
	printf("YES\n");
	// for (int i = 0; i < n-1; ++i)x = parent[x];
	// int knot = x;
	// stck.push(knot);
	// x = parent[x];
	// for (;;) {
	// 	stck.push(x);
	// 	if (x == knot)break;
	// 	x = parent[x];
	// }
	// for (;!stck.empty();) {
	// 	printf("%d ",stck.top());
	// 	stck.pop();
	// }
	// return 0;
	for (;;) {
		stck.push(x);
		if (check[x]) {
			printf("%d ",stck.top());
			stck.pop();
			for (;;) {
				printf("%d ",stck.top());
				if (stck.top() == x) {
					return 0;
				}
				stck.pop();
			}
		}
		check[x] = 1;
		x = parent[x];
	}
	return 0;
}