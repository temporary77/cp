#include <bits/stdc++.h>
using namespace std;

bool sieve[10001];
vector<int> graph[10001];
int visited[10001];
queue<int> que;

int main() {
	for (int i = 2; i <= 9999; ++i) {
		if (sieve[i])continue;
		for (int j = i*i; j <= 9999; j += i) {
			sieve[j] = 1;
		}
	}
	for (int i = 1000; i <= 9999; ++i) {
		if (sieve[i])continue;
		for (int j = 1; j <= 1000; j *= 10) {
			int d = i;
			d -= ((d/j)%10)*j;
			for (int k = 0; k <= 9; ++k, d += j) {
				if (sieve[d] || d == i || d < 1000 || d > 9999)continue;
				graph[i].push_back(d);
				//printf("%d %d\n",i,d);
			}	
		}
	}
	int n;
	scanf("%d",&n);
	int a, b;
	for (int ti = 1; ti <= n; ++ti) {
		scanf("%d%d",&a,&b);
		que.push(a);
		visited[a] = ti;
		int d = 0;
		int ans = -1;
		for (;!que.empty();) {
			int t = que.size();
			for (int i = 0; i < t; ++i) {
				int bi = que.front();
				if (bi == b) {
					for (;!que.empty();)que.pop();
					ans = d;
					break;
				}
				for (auto it : graph[bi]) {
					if (visited[it] == ti)continue;
					que.push(it);
					visited[it] = ti;
				}
				que.pop();
			}
			++d;
		}
		if (ans != -1) {
			printf("%d\n",ans);
		} else {
			printf("Impossible\n");
		}
	}
	return 0;
}