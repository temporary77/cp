#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
int idx = 0;
long long fac[500001];
const int mod = 1e9+7;

int recursion(int root, int cur) {
	//prlong longf("%lld %lld\n",root,cur);
	long long cnt = 1;
	int cnnct = 0;
	for (;;) {
		++idx;
		//prlong longf("%lld %lld\n",root,arr[idx]);
		if (root == arr[idx]) {
			break;
		} 
		++cnnct;
		//prlong longf("sending %lld %lld\n",cur,arr[idx]);
		cnt *= (recursion(cur,arr[idx]));
		cnt %= mod;
	}
	return (cnt*fac[cnnct])%mod;
}

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < 2*n-1; ++i) {
		scanf("%d",&arr[i]);
	}
	fac[0] = 1;
	for (long long i = 1; i <= n; ++i) {
		fac[i] = (fac[i-1]*i)%mod;
		fac[i] %= mod;
		//printf("%lld %lld\n",i,fac[i]);
	}
	printf("%d",recursion(0,arr[idx]));
	return 0;
}