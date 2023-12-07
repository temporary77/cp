#include <bits/stdc++.h>
using namespace std;

int cnt[26];

int main() {
	cin.tie(NULL);
	int t;
	scanf("%d",&t);
	string str;
	for (int ti = 0; ti < t; ++ti) {
		int n, k;
		scanf("%d%d",&n,&k);
		cin >> str;
		int ans = 0;
		for (int i = 0; i < (k+1)/2; ++i) {
			fill(cnt,cnt+26,0);
			for (int j = 0; j < n; j += k) {
				++cnt[str[j+i]-'a'];
				if (i != k/2)++cnt[str[j+k-1-i]-'a'];
			}
			int max1 = 0;
			for (int i = 0; i < 26; ++i) {
				max1 = max(max1,cnt[i]);
			}
			if (i != k/2)ans += 2*n/k-max1;
			else ans += n/k-max1;
		}
		printf("%d\n",ans);
	}
	return 0;
}