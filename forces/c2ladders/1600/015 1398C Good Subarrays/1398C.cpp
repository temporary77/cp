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
	for (int ti = 1; ti <= t; ++ti) {
		int n;
		scanf("%d",&n);
		cin >> str;
		++mp[100000];
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			sum += str[i-1]-'0';
			int idx = 100000+sum-i;
			++mp[idx];
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