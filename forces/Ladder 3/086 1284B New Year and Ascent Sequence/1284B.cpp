#include <bits/stdc++.h>
using namespace std;

vector<int> vctr1;
vector<int> vctr2;

int main() {
	int n;
	scanf("%d",&n);
	int l;
	int k;
	int prev;
	bool check;
	long long cnt = 0;
	int frst;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&l);
		prev = INT_MAX;
		check = 0;
		frst = -1;
		for (int j = 0; j < l; ++j) {
			scanf("%d",&k);
			if (frst == -1)frst = k;
			if (prev < k) {
				check = 1;
			}
			prev = k;
		}
		if (check) {
			++cnt;
			continue;
		}
		vctr1.push_back(k);
		vctr2.push_back(frst);
	}
	sort(vctr1.begin(),vctr1.end());
	sort(vctr2.begin(),vctr2.end());
	int idx = 0;
	// ans = 2*cnt*(n-cnt)+cnt*cnt;
	long long ans = cnt*(2*n-cnt);
	for (auto it : vctr1) {
		for (;;) {
			if (idx == vctr2.size() || vctr2[idx] > it)break;
			++idx;
		}
		ans += vctr2.size()-idx;
	}
	printf("%lld",ans);
	return 0;
}