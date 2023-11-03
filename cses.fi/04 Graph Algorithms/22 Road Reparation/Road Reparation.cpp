#include <bits/stdc++.h>
using namespace std;

int disjoint[100001];
int height[100001];
priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d",&a,&b,&c);
		--a; --b;
		pq.push({c,a,b});
	}
	for (int i = 0; i < n; ++i) {
		disjoint[i] = i;
	}
	int cnt = 0;
	long long ans = 0;
	for (;!pq.empty();) {
		tie(c,a,b) = pq.top();
		pq.pop();
		int pa, pb;
		pa = a;
		pb = b;
		for (;pa != disjoint[pa];) {
			pa = disjoint[pa];
		}
		for (;pb != disjoint[pb];) {
			pb = disjoint[pb];
		}
		if (pa == pb)continue;
		if (height[pa] >= height[pb]) {
			disjoint[pb] = pa;
			disjoint[b] = pa;
			if (height[pa] == height[pb]) {
				++height[pa];
			}
		} else {
			disjoint[pa] = pb;
			disjoint[a] = pb;
		}
		ans += c;
		++cnt;
		if (cnt == n-1) {
			printf("%lld",ans);
			return 0;
		}
	}
	printf("IMPOSSIBLE");
	return 0;
}