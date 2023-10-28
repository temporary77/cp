#include <bits/stdc++.h>
using namespace std;

vector<tuple<int,int,long long>> vctr;
long long dp[200001];

bool comp(tuple<int,int,long long> a, int b) {
	return get<0>(a) < b;
}

int main() {
	int n;
	scanf("%d",&n);
	int a, b;
	long long p;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%lld",&a,&b,&p);
		vctr.push_back({b,a,p});	
	}
	sort(vctr.begin(),vctr.end());
	dp[0] = get<2>(vctr[0]);
	// printf("0 %lld\n",dp[0]);
	for (int i = 1; i < n; ++i) {
		int idx = (--lower_bound(vctr.begin(),vctr.begin()+i,get<1>(vctr[i]),comp))-vctr.begin();
		if (idx == -1) {
			dp[i] = max(dp[i-1],get<2>(vctr[i]));
		} else {
			dp[i] = max(dp[i-1],dp[idx]+get<2>(vctr[i]));
		}
		// printf("%d %lld\n",i,dp[i]);
	}
	printf("%lld",dp[n-1]);
	return 0;
}