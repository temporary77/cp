#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> graph[100001];
priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
int cnt[100001];

int main() {
	int n, m, k;
	scanf("%d%d%d",&n,&m,&k);
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d",&a,&b,&c);
		--a; --b;
		graph[a].push_back({b,c});
	}
	pq.push({0,0});
	for (;!pq.empty();) {
		long long d;
		int bi;
		tie(d,bi) = pq.top();
		pq.pop();
		// printf("%lld %d %d\n",d,bi,cnt[bi]);
		if (cnt[bi] >= k)continue;
		++cnt[bi];
		if (bi == n-1) {
			printf("%lld ",d);
			if (cnt[n-1] == k)return 0;
		}
		for (auto it : graph[bi]) {
			pq.push({d+it.second,it.first});
		}
	}
	return 0;
}