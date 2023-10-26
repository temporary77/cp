#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	scanf("%d",&n);
	priority_queue<int,vector<int>,greater<int>> pq;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		pq.push(k);
	}
	long long sum = 0;
	k = 0;
	for (int i = 0; i < n-1; ++i) {
		k = pq.top();
		pq.pop();
		k += pq.top();
		pq.pop();
		//printf("%d\n",k);
		sum += k;
		pq.push(k);
		k = 0;
	}
	printf("%lld",sum);
	return 0;
}