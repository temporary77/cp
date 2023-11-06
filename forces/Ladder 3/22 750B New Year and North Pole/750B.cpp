#include <bits/stdc++.h>
using namespace std;


int main() {
	cin.tie(NULL);
	int n;
	scanf("%d",&n);
	string str;
	int k;
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		cin >> str;
		if (str == "North") {
			cur += k;
		} else if (str == "South") {
			cur -= k;
		} else if (str == "East" || str == "West") {
			if (cur == 0 || cur == -20000) {
				printf("NO");
				return 0;
			}
		}
		if (cur > 0 || cur < -20000) {
			printf("NO");
			return 0;
		}
	}
	if (cur == 0)printf("YES");
	else printf("NO");
	return 0;
}