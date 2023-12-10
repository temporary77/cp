#include <bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int>> pq;

int main() {
	int n;
	scanf("%d",&n);
	long long cur = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d",&a);
		if (a >= 0) {
			++cnt;
			cur += a;
		} else {
			if (cur+a >= 0) {
				pq.push(a);
				cur += a;
				++cnt;
			} else {
				if (pq.empty() || a <= pq.top())continue;
				cur -= pq.top();
				pq.pop();
				cur += a;
				pq.push(a);
			}
		}
	}
	printf("%d",cnt);
	return 0;
}