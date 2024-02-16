#include <bits/stdc++.h>
using namespace std;

int cnt[300001];
int visited[300001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 1; ti <= t; ++ti) {
		int n;
		scanf("%d",&n);
		int cur = 0;
		long long odds = 0;
		cnt[0] = 1;
		visited[0] = ti;
		for (int i = 0; i < n; ++i) {
			int a;
			scanf("%d",&a);
			cur ^= a;
			for (int j = 0; j*j <= 3e5; ++j) {
				if ((cur^(j*j)) <= 3e5) {
					if (visited[cur^(j*j)] != ti) {
						visited[cur^(j*j)] = ti;
						cnt[cur^(j*j)] = 0;
					}
					odds += cnt[cur^(j*j)];
				}
			}
			if (visited[cur] != ti) {
				visited[cur] = ti;
				cnt[cur] = 0;
			}
			++cnt[cur];
		}
		printf("%lld\n",(n*(long long)(n+1)/2)-odds);
	}
	return 0;
}