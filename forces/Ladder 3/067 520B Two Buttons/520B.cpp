#include <bits/stdc++.h>
using namespace std;

queue<int> que;
bool visited[20001];

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	que.push(n);
	visited[n] = 1;
	int ans = 0;
	for (;!que.empty();) {
		int t = que.size();
		for (int i = 0; i < t; ++i) {
			int x = que.front();
			que.pop();
			if (x == m) {
				printf("%d",ans);
				return 0;
			}
			if (x < m && !visited[2*x]) {
				que.push(2*x);
				visited[2*x] = 1;
			}
			if (x > 1 && !visited[x-1]) {
				que.push(x-1);
				visited[x-1] = 1;
			}
		}
		++ans;
	}
	return 0;
}