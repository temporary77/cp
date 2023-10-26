#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int qs[1001];
int brr[1001];
int crr[1001];
int fac[1001];
const int mod = 9901;

int modinvers(int x) {
	if (x == 0)return 1;
	int y = 9899;
	x %= mod;
	int res = 1;
	for (;y > 0;) {
		if (y%2 == 1) {
			res = (res*x)%mod;
			res %= mod;
		}
		y /= 2;
		x = (x*x)%mod;
		x %= mod;
	}
	return res;
}

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&arr[i]);
		sum += arr[i];
		qs[i] = sum;
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d",&brr[i]);
	}
	fac[0] = 1;
	for (int i = 1; i <= qs[n]; ++i) {
		fac[i] = (fac[i-1]*i)%mod;
		fac[i] %= mod;
		//printf("%d %d\n",i,fac[i]);
	}
	brr[0] = 1;
	crr[0] = 1;
	brr[m+1] = qs[n];
	crr[m+1] = n;
	for (int i = 1; i <= m; ++i) {
		crr[i] = lower_bound(qs,qs+n,brr[i])-qs;
	}
	int ans = 1;
	for (int i = 0; i <= m; ++i) {
		int x = brr[i+1]-brr[i];
		int y = crr[i+1]-crr[i];
		//printf("%d %d %d %d %d %d\n",x,y,fac[x],modinvers(x-y),modinvers(y),(modinvers(x-y)*fac[x])%mod);
		ans *= fac[x];
		ans %= mod;
		ans *= modinvers(fac[x-y]);
		ans %= mod;
		ans *= modinvers(fac[y]);
		ans %= mod;
		//printf("%d\n",ans);
	}
	printf("%d",ans);
	return 0;
}