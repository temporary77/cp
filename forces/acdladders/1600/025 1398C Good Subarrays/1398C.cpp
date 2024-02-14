#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

map<int,int> mp;

int main() {
	cin.tie(NULL);
	int t;
	scanf("%d",&t);
	string str;
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		cin >> str;
		int cur = 0;
		++mp[1];
		for (int i = 0; i < n; ++i) {
			cur += str[i]-'0';
			++mp[cur-i];
			// printf("%d\n",cur-i);
		}
		long long ans = 0;
		for (auto it : mp) {
			ans += it.s*(long long)(it.s-1)/2;
		}
		printf("%lld\n",ans);
		mp.clear();
	}
	return 0;
}