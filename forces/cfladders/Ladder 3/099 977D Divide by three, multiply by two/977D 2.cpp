#include <bits/stdc++.h>
using namespace std;

vector<pair<int,long long>> vctr;
long long pow3[40];

int main() {
	int n;
	scanf("%d",&n);
	pow3[0] = 1;
	for (int i = 1; i < 40; ++i) {
		pow3[i] = pow3[i-1]*3;
	}
	for (int i = 0; i < n; ++i) {
		long long k;
		scanf("%lld",&k);
		int l = 0;
		int r = 39;
		for (;;) {
			if (l >= r)break;
			int m = (l+r+1)/2;
			if (k%pow3[m] == 0) {
				l = m;
			} else {
				r = m-1;
			}
		}
		vctr.push_back({-1*l,k});
	}
	sort(vctr.begin(),vctr.end());
	for (auto it : vctr) {
		printf("%lld ",it.second);
	}
	return 0;
}