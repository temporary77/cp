#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	int n;
	scanf("%d",&n);
	string str;
	cin >> str;
	int cur = 0;
	for (int i = 0; i < n-1; ++i) {
		if (i != 0 && str[i] == '0')continue;
		cur += str[i]-'0';
		int cnt = cur;
		for (int j = i+1; j < n; ++j) {
			cnt -= str[j]-'0';
			if (cnt < 0) {
				break;
			} else if (cnt == 0) {
				if (j == n-1) {
					printf("YES");
					return 0;
				} else {
					if(str[j+1]-'0' > 0)cnt = cur;
				}
			}
		}
	}
	printf("NO");
	return 0;
}