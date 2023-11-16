#include <bits/stdc++.h>
using namespace std;

unordered_map<int,long long> mp1, mp2;
unordered_map<long long,long long> mp3;

int main() {
	int n;
	scanf("%d",&n);
	int x, y;
	for (int i = 0; i < n; ++i) {
		scanf("%d %d",&x,&y);
		++mp1[x];
		++mp2[y];
		++mp3[((long long)x+1e9)*1e9+((long long)y+1e9)];
	}
	long long ans = 0;
	for (auto it : mp1) {
		ans += (it.second)*(it.second-1)/2;
	}
	for (auto it : mp2) {
		ans += (it.second)*(it.second-1)/2;
	}
	for (auto it : mp3) {
		ans -= (it.second)*(it.second-1)/2;
	}
	printf("%lld",ans);
	return 0;
}