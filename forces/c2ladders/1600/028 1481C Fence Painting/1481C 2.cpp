#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

queue<int> que[100001];
int arr[100001];
int brr[100001];
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
		fill(brr+1,brr+n+1,0);
		int correct = 0;
		for (int i = 1; i <= n; ++i) {
			int b;
			scanf("%d",&b);
			brr[b] = i;
			if (b != arr[i]) {
				que[b].push(i);
			} else {
				++correct;
			}
		}
		for (int i = 0; i < m; ++i) {
			int c;
			scanf("%d",&c);
			if (que[c].empty()) {
				if (i == m-1 && brr[c]) {
					ans[i] = brr[c];
					for (;useless.size();) {
						ans[useless.front()] = ans[i];
						useless.pop();
					}
				} else {
					useless.push(i);
				}
			} else {
				ans[i] = que[c].front();
				que[c].pop();
				++correct;
				if (i == m-1) {
					for (;useless.size();) {
						ans[useless.front()] = ans[i];
						useless.pop();
					}
				}
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