#include <bits/stdc++.h>
using namespace std;

int cnt[2][2][2];

int main() {
	cin.tie(NULL);
	int n;
	scanf("%d",&n);
	string str;
	cin >> str;
	for (int i = 0; i < n; ++i) {
		if (str[i] == 'r') {
			++cnt[0][0][i&1];
			++cnt[1][0][!(i&1)];
		} else if (str[i] == 'b') {
			++cnt[0][1][!(i&1)];
			++cnt[1][1][i&1];
		}
	}
	int ans;
	ans = min(min(cnt[1][0][1],cnt[1][1][1])+abs(cnt[1][0][1]-cnt[1][1][1]),min(cnt[0][0][1],cnt[0][1][1])+abs(cnt[0][0][1]-cnt[0][1][1]));
	printf("%d",ans);
	return 0;
}