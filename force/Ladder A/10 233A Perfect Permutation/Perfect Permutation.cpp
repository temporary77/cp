#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	if (n%2 == 1) {
		printf("-1");
	} else {
		for (int i = 1; i <= n; ++i) {
			printf("%d ",i+1-2*((i+1)%2));
		}
	}

	return 0;
}