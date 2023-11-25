#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	int q;
	scanf("%d",&q);
	string s, t;
	for (int qi = 0; qi < q; ++qi) {
		cin >> s >> t;
		int idx = t.size()-1;
		for (int i = s.size()-1; i >= 0; --i) {
			if (s[i] == t[idx]) {
				--idx;
				if (idx == -1) {
					printf("YES\n");
					goto g;
				}
			} else {
				--i;
			}
		}
		printf("NO\n");
		g:;
	}
	return 0;
}