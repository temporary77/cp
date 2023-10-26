#include <bits/stdc++.h>
using namespace std;

#define int long long

long long arr[100001];
multiset<long long> deq;

signed main() {
	int n;
	long long k;
	scanf("%lld%lld",&n,&k);
	for (int i = 0; i < n; ++i) {
		scanf("%lld",&arr[i]);
	}
	int a = 0, b = 0;
	long long cnt = 0;
	deq.insert(arr[a]);
	/*for (auto it : deq) {
		printf("%d ",it);
	}
	printf("\n");*/
	for (;a < n && b < n;) {
		if (deq.empty() || *deq.rbegin()-*deq.begin() <= k) {
			cnt += b-a+1;
			++b;
			if (b == n)break;
			deq.insert(arr[b]);
		} else {
			deq.erase(arr[a]);
			++a;
		}
		/*for (auto it : deq) {
			printf("%d ",it);
		}
		printf("<< %lld\n",cnt);*/
	}
	printf("%lld",cnt);
	return 0;
}