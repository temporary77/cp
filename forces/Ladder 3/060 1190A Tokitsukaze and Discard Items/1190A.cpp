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
	auto page = vctr.begin();
	int ans = 0;
	for (;;) {
		if (page == vctr.end())break;
		auto it = upper_bound(page,vctr.end(),cur);
		int idx = it-page;
		if (idx == 0) {
			cur += k;
		} else {
			++ans;
			cur += idx;
		}
		page = it;
	}
	printf("%d",ans);
	return 0;
}