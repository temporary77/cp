#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

bool sieve[1000001];
int arr[200001];
vector<pair<bool,int>> vctr;

int main() {
	sieve[1] = true;
	for (int i = 2; i <= sqrt(1e6); ++i) {
		if (!sieve[i]) {
			for (int j = i*i; j <= 1e6; j += i) {
				sieve[j] = true;
			}
		}
	}
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, e;
		scanf("%d%d",&n,&e);
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i]);
		}
		long long ans = 0;
		for (int i = 0; i < e; ++i) {
			vctr.push_back({0,i-e});
			for (int j = i; j < n; j += e) {
				if (arr[j] != 1) {
					vctr.push_back({!sieve[arr[j]],j});
				}
				if (j+e >= n)vctr.push_back({0,j+e});
			}
			for (int i = 1; i < vctr.size()-1; ++i) {
				// printf("%d <<<\n",vctr[i].f);
				if (vctr[i].f) {
					// printf("%d %d %d\n",vctr[i-1].s,vctr[i].s,vctr[i+1].s);
					ans += (long long)(vctr[i].s-vctr[i-1].s)/e*(vctr[i+1].s-vctr[i].s)/e-1;
				}
			}
			// printf("%lld <\n",ans);
			vctr.clear();
		}
		printf("%lld\n",ans);
	}
	return 0;
}