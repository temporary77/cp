#include <bits/stdc++.h>
using namespace std;

bool prime[15000005];
int qs[15000005];

int main() {
	int n;
	scanf("%d",&n);
	prime[0] = 1;
	prime[1] = 1;
	for (int i = 2; i*i <= 15000005; ++i) {
		if (!prime[i]) {
			for (int j = i*i; j <= 15000005; j += i) {
				prime[j] = 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 2; i <= 15000005; ++i) {
		if (!prime[i])++cnt;
		qs[i] = cnt;
	}
	int a, b;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d",&a,&b);
		if (a > b) {
			printf("0\n");
			continue;
		}
		if (b < 2)b = 1;
		if (a < 0)a = 1;
		printf("%d\n",qs[b]-qs[a-1]);
	}
	return 0;
}