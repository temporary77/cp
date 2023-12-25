#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

vector<pair<long long,long long>> vctr;

int main() {
	int n;
	scanf("%d",&n);
	long long ttl = 0;
	for (int i = 0; i < n; ++i) {
		long long a, b;
		scanf("%lld%lld",&a,&b);
		ttl += a;
		vctr.push_back({b,a});
	}
	sort(vctr.begin(),vctr.end());
	int l = 0;
	int r = n-1;
	long long bought = 0;
	long long twos = 0;
	for (;bought < ttl;) {
		if (bought >= vctr[l].f) {
			bought += vctr[l].s;
			++l;
		} else {
			long long buy = vctr[l].f-bought;
			if (buy >= vctr[r].s) {
				bought += vctr[r].s;
				twos += vctr[r].s;
				--r;
			} else {
				bought += buy;
				twos += buy;
				vctr[r].s -= buy;
			}
		}
	}
	printf("%lld\n",ttl+twos);
	return 0;
}