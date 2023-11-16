#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	for (;b != 0;) {
		a %= b;
		swap(a,b);
	}
	return a;
}

int main() {
	int r, c;
	scanf("%d%d",&r,&c);
	if (r == 1 && c == 1) {
		printf("0\n");
		return 0;
	}
	if (r == 1 || c == 1) {
		for (int i = 2; i <= max(r,c)+1; ++i) {
			printf("%d ",i);
			if (c == 1)printf("\n");
		}
		return 0;
	}
	for (int i = 1; i <= r; ++i) {
		for (int j = r+1; j <= r+c; ++j) {
			printf("%d ",i*j/gcd(i,j));
		}
		printf("\n");
	}
	return 0;
}