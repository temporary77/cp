#include <bits/stdc++.h>
using namespace std;

vector<int> vctr[5];

int main() {
	int t;
	scanf("%d",&t);
	string str;
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			cin >> str;
			int cnt[5] = {0,0,0,0,0};
			for (auto it : str) {
				++cnt[it-'a'];
			}
			for (int j = 0; j < 5; ++j) {
				vctr[j].push_back(2*cnt[j]-str.size());
			}
		}
		for (int i = 0; i < 5; ++i) {
			sort(vctr[i].begin(),vctr[i].end(),greater<int>());
		}
		int ans = 0;
		for (int i = 0; i < 5; ++i) {
			int cur = 0;
			int cnt = 0;
			for (auto it : vctr[i]) {
				cur += it;
				// printf("%d ",it);
				if (cur <= 0)break;
				++cnt;
			}
			// printf("%d <<\n",cnt);
			ans = max(ans,cnt);
		}
		printf("%d\n",ans);
		for (int i = 0; i < 5; ++i) {
			vctr[i].clear();
		}
	}
	return 0;
}