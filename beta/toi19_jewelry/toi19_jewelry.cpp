#include <bits/stdc++.h>
using namespace std;

int pos[1000001];

int main() {
	cin.tie(NULL);
	int n;
	string str;
	scanf("%d",&n);
	cin >> str;
	long long cnt = 0;
	long long ans = 0;
	int cur = 0;
	for (int i = 1; i <= n; ++i) {
		if (str[i-1] == 'F') {
			for (int j = 1; j <= cur; ++j) {
				pos[j] = i-j;
			}
			cur = 0;
			ans += cnt;
		} else {
			++cur;
			cnt += i-pos[cur];
			ans += cnt;
		}
		//printf("%d %d\n",ans,cnt);
	}
	printf("%lld",ans);
	return 0;
}