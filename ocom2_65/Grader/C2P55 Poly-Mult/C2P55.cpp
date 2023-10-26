#include <bits/stdc++.h>
using namespace std;

long long *polyadd(long long arr[], long long brr[], long long n, long long rn) {
	long long* prod = new long long[n];
	for (long long i = 0; i < rn; ++i) {
		prod[i] = arr[i]+brr[i];
	}
	if (n > rn)prod[n-1] = brr[n-1];
	return prod;
}

long long *polysubtract(long long arr[], long long brr[], long long n, long long rn) {
	long long* prod = new long long[n];
	for (long long i = 0; i < rn; ++i) {
		prod[i] = arr[i]-brr[i];
	}
	for (long long i = rn; i < n; ++i) {
		prod[i] = arr[i];
	}
	return prod;
}

long long *polymul(long long arr[], long long brr[], long long n) {
	/*cout << "mul" << n << "asd";
	cin >> db;*/
    long long* prod = new long long[2*n-1];
	for (long long i = 0; i < 2*n-1; ++i) {
		prod[i] = 0;
	}
	if (n == 0)return prod;
	if (n == 1) {
		prod[0] = arr[0]*brr[0];
		return prod;
	}
	long long f = n/2;
	long long s = n-f;
	long long a0[f], a1[s], b0[f], b1[s];
	copy(arr,arr+f,a0);
	copy(arr+f,arr+n,a1);
	copy(brr,brr+f,b0);
	copy(brr+f,brr+n,b1);
	long long* ac = polyadd(a0,a1,s,f);
	long long* bc = polyadd(b0,b1,s,f);
	long long* prod1 = polymul(a0,b0,f);
	long long* prod2 = polymul(a1,b1,s);
	long long* prod3 = polymul(ac,bc,s);
	prod3 = polysubtract(prod3,prod1,2*s-1,2*f-1);
	prod3 = polysubtract(prod3,prod2,2*s-1,2*s-1);
	/*cin >> db;
	cout << "d" << 2*n-1 << " " << 2*f-1 << " " << 2*f-2 << " " << prod[0] << " " << prod1[0];
	cin >> db;*/
	for (long long i = 2*f-2; i >= 0; --i) {
		prod[i] += prod1[i];
	}
	long long idx = 2*(n-s);
	for (long long i = 0; i < 2*s-1; ++i) {
		prod[idx+i] += prod2[i];
	}
	for (long long i = 0; i < 2*s-1; ++i) {
		prod[i+f] += prod3[i];
	}
	return prod;
}

int main() {
	long long n;
	scanf("%lld",&n);
	long long arr[n+1], brr[n+1];
	for (long long i = 0; i < n; ++i) {
		scanf("%lld",&arr[i]);
	}
	for (long long i = 0; i < n; ++i) {
		scanf("%lld",&brr[i]);
	}
	long long *prod = polymul(arr,brr,n);
	//prlong longf("---------------------------------");
	for (long long i = 0; i < 2*n-1; ++i) {
		printf("%lld\n",prod[i]);
	}
	return 0;
}