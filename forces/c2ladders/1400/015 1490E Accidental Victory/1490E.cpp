#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> vctr;
vector<int> vctr2;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= n; ++i) {
			int a;
			scanf("%d",&a);
			vctr.push_back({a,i});
		}
		sort(vctr.begin(),vctr.end());
		long long cur = vctr[0].first;
		vctr2.push_back(vctr[0].second);
		for (int i = 1; i < n; ++i) {
			if (cur < vctr[i].first) {
				vctr2.clear();
			}
			cur += vctr[i].first;
			vctr2.push_back(vctr[i].second);
		}
		sort(vctr2.begin(),vctr2.end());
		printf("%d\n",vctr2.size());
		for (auto it : vctr2) {
			printf("%d ",it);
		}
		printf("\n");
		vctr.clear();
		vctr2.clear();
	}
	return 0;
}