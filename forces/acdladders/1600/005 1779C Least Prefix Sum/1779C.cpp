#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int arr[200001];

priority_queue<int, vector<int>, greater<int>> pq;
priority_queue<int> pq2;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, m;
		scanf("%d%d",&n,&m);
		for (int i = 1; i <= n; ++i) {
			scanf("%d",&arr[i]);
		}
		int ans = 0;
		long long cur = 0;
		for (int i = m+1; i <= n; ++i) {
			cur += arr[i];
			if (arr[i] < 0) {
				pq.push(arr[i]);
				if (cur < 0) {
					cur -= 2*pq.top();
					pq.pop();
					++ans;
				}
			}
		}
		for (;pq.size();)pq.pop();
		cur = 0;
		for (int i = m; i >= 1; --i) {
			cur += arr[i];
			if (arr[i] > 0 && i != 1) {
				pq2.push(arr[i]);
				if (cur > 0) {
					cur -= 2*pq2.top();
					pq2.pop();
					++ans;
				}
			}
		}
		for (;pq2.size();)pq2.pop();
		printf("%d\n",ans);
	}
	return 0;
}