#include <bits/stdc++.h>
using namespace std;

vector<long long> vctr;

int main() {
	long long n, m, k;
	scanf("%lld%lld%lld",&n,&m,&k);
	long long p;
	for (int i = 0; i < m; ++i) {
		scanf("%lld",&p);
		vctr.push_back(p);
	}
	long long cur = k;
	auto it = vctr.begin();
	int ans = 0;
	for (;;) {
		if (it == vctr.end())break;
		auto it2 = upper_bound(it,vctr.end(),cur);
		if (it == it2) {
			cur += ceil((*it2-cur)/(double)k)*k;
		} else {
			++ans;
			cur += it2-it;
			it = it2;
		}
	}
	printf("%d",ans);
	return 0;
}