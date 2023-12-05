#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, k;
		scanf("%d%d",&n,&k);
		int lowest = k-(n-k);
		for (int i = 1; i < lowest; ++i) {
			printf("%d ",i);
		}
		for (int i = k; i >= lowest; --i) {
			printf("%d ",i);
		}
		printf("\n");
	}
	return 0;
}