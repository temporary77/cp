#include <bits/stdc++.h>
using namespace std;

int cnt[26];
int ttl = 0;

int main() {
	cin.tie(NULL);
	string str;
	cin >> str;
	if (str.size() < 26) {
		printf("-1");
		return 0;
	}
	for (int i = 0; i < 25; ++i) {
		if (str[i] == '?') {
			++ttl;
		} else {
			if (cnt[str[i]-'A'] == 0) {
				++ttl;
			}
			++cnt[str[i]-'A'];
		}
	}
	bool check = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (!check) {
			if (i+25 < str.size()) {
				if (str[i+25] == '?') {
					++ttl;
				} else {
					if (cnt[str[i+25]-'A'] == 0) {
						++ttl;
					}
					++cnt[str[i+25]-'A'];
				}
			} else {
				printf("-1");
				return 0;
			}
			if (ttl == 26) {
				check = 1;
				int idx = 0;
				for (int j = i; j < 26+i; ++j) {
					if (str[j] == '?') {
						for (;;) {
							if (cnt[idx] == 0) {
								str[j] = 'A'+idx;
								++idx;
								break;
							}
							++idx;
						}
					}
				}
			}
		}
		if (str[i] == '?') {
			str[i] = 'A';
			--ttl;
		} else {
			if (cnt[str[i]-'A'] == 1) {
				--ttl;
			}
			--cnt[str[i]-'A'];
		}
	}
	cout << str;
	return 0;
}