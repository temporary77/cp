#include <bits/stdc++.h>
using namespace std;

vector<int> vctr;

int main() {
	int n, s;
	scanf("%d%d",&n,&s);
	int k;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		vctr.push_back(k);
	}
	sort(vctr.begin(),vctr.end());
	long long ans = 0;
	for (int i = n/2; i >= 0; --i) {
		if (vctr[i] > s) {
			ans += vctr[i]-s;
		} else {
			break;
		}
	}
	for (int i = n/2; i < n; ++i) {
		if (vctr[i] < s) {
			ans += s-vctr[i];
		} else {
			break;
		}
	}
	printf("%lld",ans);
	return 0;
}