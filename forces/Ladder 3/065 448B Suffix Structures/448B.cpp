#include <bits/stdc++.h>
using namespace std;

int cnt[26];

int main() {
	cin.tie(NULL);
	string s, t;
	cin >> s >> t;
	int idx = 0;
	for (auto it : s) {
		if (it == t[idx]) {
			++idx;
		}
		++cnt[it-'a'];
	}
	if (idx == t.size()) {
		printf("automaton");
		return 0;
	}
	for (auto it : t) {
		if (!cnt[it-'a']) {
			printf("need tree");
			return 0;
		}
		--cnt[it-'a'];
	}
	if (s.size() == t.size()) {
		printf("array");
	} else {
		printf("both");
	}
	return 0;
}