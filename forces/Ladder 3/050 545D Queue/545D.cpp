#include <bits/stdc++.h>
using namespace std;

vector<long long> vctr;

int main() {
	int n;
	scanf("%d",&n);
	long long k;
	long long cur = 0;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%lld",&k);
		vctr.push_back(k);
	}
	sort(vctr.begin(),vctr.end());
	for (auto it : vctr) {
		if (cur <= it) {
			++ans;
			cur += it;
		}
	}
	printf("%d",ans);
	return 0;
}