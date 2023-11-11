#include <bits/stdc++.h>
using namespace std;

long long rcnt[501];
long long ccnt[501];

int main() {
	int n;
	scanf("%d",&n);
	if (n == 1) {
		printf("1");
		return 0;
	}
	int k;
	int r, c;
	long long d1 = 0, d2 = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d",&k);
			if (!k) {
				r = i;
				c = j;
			}
			rcnt[i] += k;
			ccnt[j] += k;
			if (i == j)d1 += k;
			if (i == n-j-1)d2 += k;
		}
	}
	long long ansi = rcnt[(r+1)%n]-rcnt[r];
	rcnt[r] += ansi;
	ccnt[c] += ansi;
	if (r == c)d1 += ansi;
	if (r == n-c-1)d2 += ansi;
	for (int i = 1; i < n; ++i) {
		if (rcnt[i] != rcnt[0]) {
			printf("-1");
			return 0;
		}
		if (ccnt[i] != ccnt[0]) {
			printf("-1");
			return 0;
		}
	}
	if (d1 != rcnt[0] || d2 != rcnt[0] || rcnt[0] != ccnt[0]) {
		printf("-1");
		return 0;
	}
	printf("%lld",ansi);
	return 0;
}