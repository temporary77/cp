#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, x;
		scanf("%d%d",&n,&x);
		int max1 = 0;
		int k;
		bool check = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d",&k);
			max1 = max(max1,k);
			if (k == x)check = 1;
		}
		if (check)printf("1\n");
		else if (max1 > x)printf("2\n");
		else printf("%d\n",(x+max1-1)/max1);
	}
	return 0;
}