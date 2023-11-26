#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	int t;
	scanf("%d",&t);
	string str;
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		cin >> str;
		for (int i = 0; i < n; ++i) {
			if (str[i]-'0' == 0) {
				if (i <= n-n/2-1) {
					// printf("%d %d %d %d\n",i+1,i+n/2+1,i+2,i+n/2+1);
					printf("%d %d %d %d\n",i+1,n,i+2,n);
				} else {
					// printf("%d %d %d %d\n",i-n/2+1,i+1,i-n/2+1,i);
					printf("%d %d %d %d\n",1,i+1,1,i);
				}
				goto g;
			}
		}
		printf("%d %d %d %d\n",1,n-1,2,n);
		g:;
	}
	return 0;
}