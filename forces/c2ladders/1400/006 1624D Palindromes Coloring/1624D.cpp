#include <bits/stdc++.h>
using namespace std;

bool active[26];

int main() {
	cin.tie(NULL);
	int t;
	scanf("%d",&t);
	string str;
	for (int ti = 0; ti < t; ++ti) {
		int n, k;
		scanf("%d%d",&n,&k);
		cin >> str;
		for (int i = 0; i < 26; ++i)active[i] = false;
		int pairs = 0;
		int lones = 0;
		for (auto it : str) {
			if (active[it-'a']) {
				--lones;
				++pairs;
			} else {
				++lones;
			}
			active[it-'a'] ^= 1;
		}
		// printf("%d %d\n",pairs,lones);
		int ans = 2*(pairs/k);
		lones += 2*(pairs%k);
		if (lones >= k) {
			++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}