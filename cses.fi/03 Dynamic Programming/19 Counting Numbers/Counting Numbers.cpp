#include <bits/stdc++.h>
using namespace std;

long long arr[20], brr[20];
long long pow1[20];

int main() {
	long long a, b;
	scanf("%lld%lld",&a,&b);
	--a;
	long long ansa = 1, ansb = 1;
	long long cpow = 1;
	for (int i = 0; i <= 18; ++i) {
		pow1[i] = cpow;
		cpow *= 9;
	}
	if (a >= 10) {
		int al = floor(log10(a));
		for (int i = 1; i <= al; ++i) {
			ansa += pow1[i];
		}
		for (int i = 0; i <= al; ++i) {
			arr[i] = a%10;
			a /= 10;
		}
		ansa += (arr[al]-1)*pow1[al];
		// printf("%lld\n",ansa);
		for (int i = al-1; i >= 0; --i) {
			// printf(">> %d %d\n",arr[i+1],arr[i]);
			if (arr[i+1] >= arr[i]) {
				ansa += (arr[i])*pow1[i];
			} else {
				ansa += (arr[i]-1)*pow1[i];
			}
			if (arr[i+1] == arr[i])break;
			if (i == 0) {
				if (arr[0] != arr[1])++ansa;
			}
		}
	} else {
		ansa = a+1;
	}
	if (b >= 10) {
		int bl = floor(log10(b));
		// printf("%d %d\n",al,bl);
		for (int i = 1; i <= bl; ++i) {
			// printf("%lld\n",pow1[i]);
			ansb += pow1[i];
		}
		for (int i = 0; i <= bl; ++i) {
			brr[i] = b%10;
			b /= 10;
		}
		ansb += (brr[bl]-1)*pow1[bl];
		// printf("%lld\n",ansb);
		for (int i = bl-1; i >= 0; --i) {
			if (brr[i+1] >= brr[i]) {
				ansb += (brr[i])*pow1[i];
			} else {
				ansb += (brr[i]-1)*pow1[i];
			}
			if (brr[i+1] == brr[i])break;
			if (i == 0) {
				if (brr[0] != brr[1])++ansb;
			}
		}
	} else {
		ansb = b+1;
	}
	// printf("%lld %lld %lld\n",ansb,ansa,ansb-ansa);
	printf("%lld",ansb-ansa);
	return 0;
}