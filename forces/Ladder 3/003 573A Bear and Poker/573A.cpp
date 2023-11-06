#include <bits/stdc++.h>
using namespace std;

int pow2[31];
int pow3[20];

int main() {
	int n;
	scanf("%d",&n);
	int k;
	scanf("%d",&k);
	for (;!(k&1);) {
		k >>= 1;
	}
	for (;!(k%3);) {
		k /= 3;
	}
	int x;
	for (int i = 1; i < n; ++i) {
		scanf("%d",&x);
		for (;!(x&1);) {
			x >>= 1;
		}
		for (;!(x%3);) {
			x /= 3;
		}
		if (x != k) {
			printf("No");
			return 0;
		}
	}
	printf("Yes");
	return 0;
}