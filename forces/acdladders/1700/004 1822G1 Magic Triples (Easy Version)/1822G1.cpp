#include <bits/stdc++.h>
using namespace std;

const long long MAX_A = 1e6;

int cnt[MAX_A+1];
int visited[MAX_A+1];
set<int> st;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 1; ti <= t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			int a;
			scanf("%d",&a);
			if (visited[a] != ti) {
				visited[a] = ti;
				cnt[a] = 0;
			}
			++cnt[a];
			st.insert(a);
		}
		long long ans = 0;
		for (auto it : st) {
			ans += cnt[it]*(long long)(cnt[it]-1)*(cnt[it]-2);
		}
		for (int i = 2; i*i <= MAX_A; ++i) {
			for (auto it : st) {
				if (it*(long long)i*i > MAX_A) {
					break;
				}
				if (visited[it*i] != ti || visited[it*i*i] != ti) {
					continue;
				}
				ans += cnt[it]*(long long)cnt[it*i]*cnt[it*i*i];
			}
		}
		printf("%lld\n",ans);
		st.clear();
	}
	return 0;
}