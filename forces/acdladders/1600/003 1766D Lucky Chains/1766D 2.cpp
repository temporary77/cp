#include <bits/stdc++.h>
using namespace std;

const int MAXA = 1e7;
int sieve[MAXA+1];

int main() {
	sieve[1] = 1;
	for (long long i = 2; i <= MAXA; ++i) {
		if (!sieve[i]) {
			sieve[i] = i;
			for (long long j = i*i; j <= MAXA; j += i) {
				sieve[j] = i;
			}
		}
	}
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		if (a > b)swap(a,b);
		int diff = b-a;
		if (diff == 1) {
			printf("-1\n");
			continue;
		}
		int steps = INT_MAX;
		for (;diff > 1;) {
			steps = min(steps,sieve[diff]-((a-1)%sieve[diff]+1));
			// printf("%d %d\n",it,it-((a-1)%it+1));
			diff /= sieve[diff];
		}
		printf("%d\n",steps);
	}
	return 0;
}