#include <bits/stdc++.h>
using namespace std;

unordered_map<int,int> mp;

int main() {
	int n;
	scanf("%d",&n);
	int k;
	int min1 = INT_MAX;
	int max1 = INT_MIN;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		++mp[k];
		min1 = min(min1,k);
		max1 = max(max1,k);
	}
	int d = max1-min1;
	long long ans = 0;
	for (auto it : mp) {
		if (mp.find(it.first+d) == mp.end())continue;
		if (d == 0)ans += (long long)it.second*(it.second-1)/2;
		else ans += (long long)it.second*(mp[it.first+d]);
	}
	printf("%d %lld",d,ans);
	return 0;
}