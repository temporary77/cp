#include <bits/stdc++.h>
using namespace std;

stack<int> stck;
queue<int> que;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		que.push(0);
		int cur = 1;
		for (;;) {
			que.push(cur);
			if (cur >= n/cur)break;
			stck.push(n/cur);
			int l = cur+1;
			int r = n;
			int det = n/cur;
			for (;;) {
				if (l >= r)break;
				int m = (l+r)/2;
				if (n/m < n/cur) {
					r = m;
				} else {
					l = m+1;
				}
			}
			cur = l;
			if (cur > n/cur)break;
		}
		printf("%d\n",que.size()+stck.size());
		for (;!que.empty();) {
			printf("%d ",que.front());
			que.pop();
		}
		for (;!stck.empty();) {
			printf("%d ",stck.top());
			stck.pop();
		}
		printf("\n");
	}
	return 0;
}