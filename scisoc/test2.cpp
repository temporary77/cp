#include <bits/stdc++.h>
using namespace std;

bool sieve[10000] = {0};

int main() {
	int a, b;
	scanf("%d%d",&a,&b);
	int ans = 0;
	for (int i = 2; i <= b; ++i) {
		if (!sieve[i]) {
			if (i >= a) ++ans;
			for (int j = i*i; j <= b; j += i) {
				sieve[j] = 1;
			}
		}
	}
	printf("%d",ans);
	return 0;
}