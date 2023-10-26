#include <bits/stdc++.h>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;

int main() {
	long long n, m;
	scanf("%lld%lld",&n,&m);
	long long k, sum;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%lld",&k);
			pq.push(k);
		}
		sum = 0;
		for (;pq.size() > 1;) {
			k = pq.top();
			pq.pop();
			k += pq.top();
			pq.pop();
			sum += k;
			pq.push(k);
		}
		pq.pop();
		printf("%lld\n",sum);
	}
	return 0;
}