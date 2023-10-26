#include <bits/stdc++.h>
using namespace std;

priority_queue<int> pq;

int main() {
	int n;
	scanf("%d",&n);
	int k;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		pq.push(k);
	}
	int t = 0;
	int sum = 0;
	for (;!pq.empty();) {
		if (t < 2)sum += pq.top();
		else t = -1;
		++t;
		pq.pop();
	}
	printf("%d",sum);
	return 0;
}