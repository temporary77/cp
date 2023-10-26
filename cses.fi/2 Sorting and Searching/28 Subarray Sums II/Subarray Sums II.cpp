#include <bits/stdc++.h>
using namespace std;

unordered_map<long long,int> mp;
int n;
long long x;

int main() {
	scanf("%d%lld",&n,&x);
	int l = 0;
	long long sum = 0;
	long long cnt = 0;
	int k;
	++mp[0];
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		sum += k;
		if (mp.find(sum-x) != mp.end())cnt += mp[sum-x];
		//printf("%d %d\n",sum-x,mp[sum-x]);
		++mp[sum];
	}
	printf("%lld",cnt);
	return 0;
}