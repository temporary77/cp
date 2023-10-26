#include <bits/stdc++.h>
using namespace std;

map<char,long long> mp;

int main() {
	cin.tie(nullptr);
	int n;
	long long c;
	scanf("%d%lld",&n,&c);
	string str;
	cin >> str;
	int a = 0;
	int ans = 0;
	long long cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (str[i] == 'a' || str[i] == 'b')++mp[str[i]];
		if (str[i] == 'b') {
			cnt += mp['a'];
		}
		for (;cnt > c;) {
			if (str[a] == 'a' || str[a] == 'b')--mp[str[a]];
			if (str[a] == 'a') {
				cnt -= mp['b'];
			}
			++a;
		}
		ans = max(ans,i-a+1);
	}
	printf("%d",ans);
	return 0;
}