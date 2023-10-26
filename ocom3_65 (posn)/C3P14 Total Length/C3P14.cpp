#include <bits/stdc++.h>
using namespace std;

#define int long long

int arr[100001];

signed main() {
	int n;
	long long s;
	scanf("%lld%lld",&n,&s);
	long long sum = 0;
	int a = 0;
	long long cnt = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%lld",&arr[i]);
		sum += arr[i];
		if (sum > s) {
			for (;sum > s;) {
				sum -= arr[a];
				++a;
			}
		}
		cnt += (i-a+1)*(i-a+2)/2;
		//printf("%lld %d %d\n",cnt,a,i);
	}
	printf("%lld",cnt);
	return 0;
}