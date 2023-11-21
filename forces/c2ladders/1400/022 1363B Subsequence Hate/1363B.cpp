#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	int t;
	scanf("%d",&t);
	string str;
	for (int ti = 0; ti < t; ++ti) {
		cin >> str;
		int n = str.size();
		int ttl[2] = {0,0};
		for (auto it : str)++ttl[it-'0'];
		int cnt[2] = {0,0};
		int ans = INT_MAX;
		for (int i = 0; i < n; ++i) {
			++cnt[str[i]-'0'];
			--ttl[str[i]-'0'];
			ans = min(ans,n-cnt[0]-ttl[1]);
			ans = min(ans,n-cnt[1]-ttl[0]);
		}
		printf("%d\n",ans);
	}
	return 0;
}