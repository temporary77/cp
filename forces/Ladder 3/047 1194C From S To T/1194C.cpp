#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	int q;
	scanf("%d",&q);
	for (int qi = 0; qi < q; ++qi) {
		string s, t, p;
		cin >> s >> t >> p;
		int idx = 0;
		bool check = 0;
		int cnt[26] = {0};
		int cur = 0;
		for (auto it : t) {
			if (it == s[idx]) {
				++idx;
				if (idx == s.size()) {
					check = 1;
				}
			} else {
				++cnt[it-'a'];
				++cur;
			}
		}
		if (!check) {
			printf("NO\n");
			continue;
		}
		for (auto it : p) {
			if (cnt[it-'a'] > 0) {
				--cnt[it-'a'];
				--cur;
			}
		}
		if (cur > 0) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
	return 0;
}