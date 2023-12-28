#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

queue<int> que[100001];
int arr[100001];
int done[100001];
int ans[100001];
queue<int> useless;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, m;
		scanf("%d%d",&n,&m);
		for (int i = 1; i <= n; ++i) {
			scanf("%d",&arr[i]);
		}
		int correct = 0;
		fill(done+1,done+n+1,0);
		for (int i = 1; i <= n; ++i) {
			int b;
			scanf("%d",&b);
			if (b != arr[i]) {
				que[b].push(i);
			} else {
				++correct;
				done[b] = i;
			}
		}
		for (int i = 0; i < m; ++i) {
			int c;
			scanf("%d",&c);
			if (que[c].empty()) {
				if (done[c]) {
					ans[i] = done[c];
					for (;useless.size();) {
						ans[useless.front()] = done[c];
						useless.pop();
					}
				} else {
					useless.push(i);
				}
			} else {
				int idx = que[c].front();
				que[c].pop();
				done[c] = idx;
				++correct;
				for (;useless.size();) {
					ans[useless.front()] = idx;
					useless.pop();
				}
				ans[i] = idx;
				// printf("%d painting %d\n",idx,c);
			}
		}
		if (correct == n && useless.empty()) {
			printf("YES\n");
			for (int i = 0; i < m; ++i) {
				printf("%d ",ans[i]);
			}
			printf("\n");
		} else {
			printf("NO\n");
		}
		for (int i = 1; i <= n; ++i) {
			for (;que[i].size();)que[i].pop();
		}
	for (;useless.size();)useless.pop();
	}
	return 0;
}