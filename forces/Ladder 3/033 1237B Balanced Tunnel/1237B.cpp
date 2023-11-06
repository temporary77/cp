#include <bits/stdc++.h>
using namespace std;

bool exited[100001];
queue<int> que;

int main() {
	int n;
	scanf("%d",&n);
	int k;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		que.push(k);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		exited[k] = 1;
		if (k != que.front()) {
			++ans;
		} else {
			for (;!que.empty() && exited[que.front()];)que.pop();
		}
	}
	printf("%d",ans);
	return 0;
}