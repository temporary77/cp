#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> vctr;

int main() {
	scanf("%d%d",&n,&x);
	int k;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		vctr.push_back(k);
	}
	int ans = 0;
	for (auto it = vctr.begin(); it != vctr.end(); ++it) {
		int d = --lower_bound(it,vctr.end(),*it+x+1)-it;
		ans = max(ans,d);
	}
	printf("%d",ans);
	return 0;
}