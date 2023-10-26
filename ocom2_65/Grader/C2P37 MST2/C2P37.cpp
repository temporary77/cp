#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("test_input.txt","r",stdin);
	int n, m;
	scanf("%d%d",&n,&m);
	priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		scanf("%d%d%d",&a,&b,&w);
		pq.push({w,--a,--b});
	}
	int arr[n];
	for (int i = 0; i < n; ++i) {
		arr[i] = i;
	}
	long long ans = 0;
	for (int i = 1; i < n;) {
		int w = get<0>(pq.top()), a = get<1>(pq.top()), b = get<2>(pq.top());
		int pa = a, pb = b;
		for (;arr[pa] != pa;) {
			pa = arr[pa];
		}
		for (;arr[pb] != pb;) {
			pb = arr[pb];
		}
		if (pa == pb) {
			pq.pop();
			continue;
		}
		arr[pb] = pa;
		arr[b] = pa;
		ans += w;
		pq.pop();
		++i;
	}
	printf("%lld",ans);
	return 0;
}