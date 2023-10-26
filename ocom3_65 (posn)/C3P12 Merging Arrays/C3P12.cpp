#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int k;
	for (int i = 0; i < n+m; ++i) {
		scanf("%d",&k);
		pq.push(k);
	}
	for (;!pq.empty();) {
		printf("%d ",pq.top());
		pq.pop();
	}
	return 0;
}