#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	int t;
	scanf("%d",&t);
	string str;
	for (int ti = 0; ti < t; ++ti) {
		cin >> str;
		long long ans = 0;
		int lst[2] = {-1,-1};
		for (int i = 0; i < str.size(); ++i) {
			if (str[i] == '?') {
				ans += max(i-lst[0],i-lst[1]);
				// printf("%d <\n",max(i-lst[0],i-lst[1]));
			} else {
				int p = ((i&1)^(str[i]-'0'));
				ans += i-lst[p^1];
				// printf("%d <\n",i-lst[p^1]);
				lst[p] = i;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}