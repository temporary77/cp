#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		n -= (n%11)*111;
		if (n >= 0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}