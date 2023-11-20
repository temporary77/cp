#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<int,int>> pq;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		int max1 = 0;
		long long sum = 0;
		for (int i = 1; i <= n; ++i) {
			int a;
			scanf("%d",&a);
			if (a)pq.push({a,i});
			sum += a;
			max1 = max(max1,a);
		}
		int remain = max(sum&1,2*max1-sum);
		printf("%d\n",(sum-remain)/2);
		pair<int,int> p1 ,p2;
		for (;pq.size() > 1;) {
			p1 = pq.top();
			pq.pop();
			p2 = pq.top();
			pq.pop();
			printf("%d %d\n",p1.second,p2.second);
			--p1.first;
			--p2.first;
			if (p1.first) {
				pq.push(p1);
			}
			if (p2.first) {
				pq.push(p2);
			}
		}
		for (;!pq.empty();)pq.pop();
	}
	return 0;
}