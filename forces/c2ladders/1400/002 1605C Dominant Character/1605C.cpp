#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		string str;
		cin >> str;
		int ans = INT_MAX;
		for (int i = 0; i < n; ++i) {
			if (str[i] == 'a') {
				if (i+1 < n && str[i+1] == 'a') {
					ans = min(ans,2);
				}
				if (i+2 < n && str[i+2] == 'a') {
					ans = min(ans,3);
				}
				if (i+3 < n && str[i+3] == 'a') {
					if (str[i+1] == 'b' ^ str[i+2] == 'b') {
						ans = min(ans,4);
					} else {
						if (i+6 < n && str[i+6] == 'a') {
							if (str[i+4] == str[i+5] && str[i+4] != 'a' && str[i+4] != str[i+1]) {
								ans = min(ans,7);
							}
						}
					}
				}
			}
		}
		if (ans == INT_MAX)printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}