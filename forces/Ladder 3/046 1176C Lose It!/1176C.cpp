#include <bits/stdc++.h>
using namespace std;

int cnt[6];
unordered_map<int,int> mp;

int main() {
	int n;
	scanf("%d",&n);
	int k;
	mp[4] = 0;
	mp[8] = 1;
	mp[15] = 2;
	mp[16] = 3;
	mp[23] = 4;
	mp[42] = 5;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		k = mp[k];
		if (k == 0)++cnt[0];
		else {
			if (cnt[k-1] > 0) {
				--cnt[k-1];
				++cnt[k];
			}
		}
	}
	printf("%d",n-6*cnt[5]);
	return 0;
}