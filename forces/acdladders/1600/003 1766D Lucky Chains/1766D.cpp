#include <bits/stdc++.h>
using namespace std;

const int SQRTMAXA = sqrt(1e7);
bool sieve[SQRTMAXA+1];
vector<int> primes;

int main() {
	sieve[1] = true;
	for (long long i = 2; i <= SQRTMAXA; ++i) {
		if (!sieve[i]) {
			primes.push_back(i);
			for (long long j = i*i; j <= SQRTMAXA; j += i) {
				sieve[j] = true;
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
		for (auto it : primes) {
			if (!(diff%it)) {
				steps = min(steps,it-((a-1)%it+1));
				// printf("%d %d\n",it,it-((a-1)%it+1));
				for (;!(diff%it);) {
					diff /= it;
				}
			}
			if (diff == 1)break;
		}
		if (diff > 1) {
			steps = min(steps,diff-((a-1)%diff+1));
		}
		printf("%d\n",steps);
	}
	return 0;
}