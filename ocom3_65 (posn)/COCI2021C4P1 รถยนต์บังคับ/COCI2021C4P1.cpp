#include <bits/stdc++.h>
using namespace std;

vector<long long> vctr;

int main() {
	int n;
	scanf("%d",&n);
	long long k;
	for (int i = 0; i < n; ++i) {
		scanf("%lld",&k);
		vctr.push_back(k);
	}
	sort(vctr.begin(),vctr.end());
	long long sum = vctr[0]*(n-1);
	for (int i = 1; i < n; ++i) {
		sum += vctr[i];
	}
	printf("%lld",sum);
	return 0;
}