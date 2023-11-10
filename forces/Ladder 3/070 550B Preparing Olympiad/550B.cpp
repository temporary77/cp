#include <bits/stdc++.h>
using namespace std;

vector<int> vctr;

int main() {
	int n, l, r, x;
	scanf("%d%d%d%d",&n,&l,&r,&x);
	int k;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		vctr.push_back(k);
	}
	sort(vctr.begin(),vctr.end());
	int ans = 0;
	for (int i = 1; i <= vctr.size()-1; ++i) {
		for (int j = 0; j < vctr.size()-i; ++j) {
			if (vctr[j+i]-vctr[j] < x)continue;
			for (int a = 0; a < 1 << j+i; a += 1 << j+1) {
				int cur = vctr[j]+vctr[j+i];
				for (int b = j+1; b <= j+i-1; ++b) {
					if (a&(1 << b)) {
						cur += vctr[b];
					}
				}
				if (l <= cur && cur <= r)++ans;
			}
		}
	}
	printf("%d",ans);
	return 0;
}