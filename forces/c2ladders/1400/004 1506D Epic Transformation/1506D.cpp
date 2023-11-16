#include <bits/stdc++.h>
using namespace std;

vector<int> vctr;
priority_queue<int> pq;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int idx = vctr.size();
		int n;
		scanf("%d",&n);
		int k;
		for (int i = 0; i < n; ++i) {
			scanf("%d",&k);
			vctr.push_back(k);
		}
		sort(vctr.begin()+idx,vctr.end());
		int cur = 1;
		int prev = vctr[idx];
		for (int i = idx+1; i < vctr.size(); ++i) {
			if (vctr[i] == prev) {
				++cur;
			} else {
				pq.push(cur);
				cur = 1;
				prev = vctr[i];
			}
		}
		pq.push(cur);
		int del = 0;
		for (;pq.size() >= 2;) {
			int a, b;
			a = pq.top(); pq.pop();
			b = pq.top(); pq.pop();
			if (--a > 0)pq.push(a);
			if (--b > 0)pq.push(b);
			del += 2;
		}
		printf("%d\n",n-del);
		for (;!pq.empty();)pq.pop();
	}
	return 0;
}