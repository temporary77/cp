#include <bits/stdc++.h>
using namespace std;

int cnt[26];

int main() {
	cin.tie(NULL);
	int t;
	scanf("%d",&t);
	string str;
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		cin >> str;
		if (n&1) {
			printf("-1\n");
			continue;
		}
		fill(cnt,cnt+26,0);
		for (auto it : str) {
			++cnt[it-'a'];
		}
		bool check = true;
		for (int i = 0; i < 26; ++i) {
			if (cnt[i] > n/2) {
				printf("-1\n");
				check = false;
				break;
			}
		}
		if (!check)continue;
		fill(cnt,cnt+26,0);
		int max1 = 0;
		int ttl = 0;
		for (int i = 0; i < n/2; ++i) {
			if (str[i] != str[n-1-i])continue;
			max1 = max(max1,++cnt[str[i]-'a']);
			++ttl;
		}
		int leftover = max(ttl%2,2*max1-ttl);
		printf("%d\n",(ttl-leftover)/2+leftover);
	}
	return 0;
}

/*
c c
a a
b a
b b
a a
c c

a a
a a
c c
c c
b b
b a
*/