#include <bits/stdc++.h>
using namespace std;

vector<int> vctr;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		long long k;
		scanf("%d%lld",&n,&k);
		int min1 = INT_MAX;
		long long sum = 0;
		for (int i = 0; i < n; ++i) {
			int a;
			scanf("%d",&a);
			min1 = min(min1,a);
			vctr.push_back(a);
			sum += a;
		}
		sort(vctr.begin(),vctr.end(),greater<int>());
		if (sum <= k) {
			printf("0\n");
			vctr.clear();
			continue;
		}
		long long ans = sum-k;
		long long need = sum-k;
		long long cur = 0;
		for (int i = 0; i < n-1; ++i) {
			cur += vctr[i];
			long long cover = cur-min1*(long long)(i+1);
			long long depth = ceil((need-cover <= 0 ? 0 : need-cover)/(double)(i+2));
			ans = min(ans,depth+i+1);
		}
		printf("%lld\n",ans);
		vctr.clear();
	}
	return 0;
}