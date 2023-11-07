#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, k;
		scanf("%d%d",&n,&k);
		int x = ceil((-1+sqrt(1+8*(long long)k))/2);
		int a = n-1-x;
		int b = n-(k-((long long)x*(x-1)/2));
		for (int i = 0; i < n; ++i) {
			if (i == a || i == b)printf("b");
			else printf("a");
		}
		printf("\n");
	}
	return 0;
}