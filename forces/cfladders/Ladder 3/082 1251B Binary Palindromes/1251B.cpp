#include <bits/stdc++.h>
using namespace std;

int cnt[2];

int main() {
	cin.tie(NULL);
	int q;
	scanf("%d",&q);
	for (int qi = 0; qi < q; ++qi) {
		int n;
		scanf("%d",&n);
		priority_queue<int, vector<int>, greater<int>> pq;
		string str;
		cnt[0] = 0;
		cnt[1] = 0;
		for (int i = 0; i < n; ++i) {
			cin >> str;
			pq.push(str.size()/2);
			for (auto it : str) {
				++cnt[it-'0'];
			}
		}
		int ttl = (cnt[0]/2)+(cnt[1]/2);
		int cur = 0;
		int ans = 0;
		for (;!pq.empty();) {
			int x = pq.top();
			pq.pop();
			if (cur+x > ttl)break;
			++ans;
			cur += x;
		}
		printf("%d\n",ans);
	}
	return 0;
}