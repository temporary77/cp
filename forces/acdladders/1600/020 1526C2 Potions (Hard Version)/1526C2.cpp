#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	int n;
	scanf("%d",&n);
	long long pos = 0;
	long long neg = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d",&a);
		if (a >= 0) {
			pos += a;
			++cnt;
		} else {
			if (pos+neg+a >= 0) {
				neg += a;
				pq.push(a);
				++cnt;
			} else {
				if (pq.size() && pq.top() < a) {
					neg += a-pq.top();
					pq.pop();
					pq.push(a);
				}
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}