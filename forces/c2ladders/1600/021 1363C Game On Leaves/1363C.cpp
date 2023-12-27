#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, x;
		scanf("%d%d",&n,&x);
		int degree = 0;
		for (int i = 0; i < n-1; ++i) {
			int u, v;
			scanf("%d%d",&u,&v);
			if (u == x || v == x)++degree;
		}
		if (degree <= 1) {
			printf("Ayush\n");
			continue;
		} else {
			if (n&1) {
				printf("Ashish\n");
			} else {
				printf("Ayush\n");
			}
		}
	}
	return 0;
}