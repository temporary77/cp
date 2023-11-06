#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	scanf("%d%d",&n,&k);
	for (int i = 0; i < k; ++i) {
		scanf("%*d%*d");
	}
	for (int i = 0; i < n; ++i) {
		if (i&1) {
			printf("0");
		} else {
			printf("1");
		}
	}

	return 0;
}