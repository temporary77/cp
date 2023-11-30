#include <bits/stdc++.h>
using namespace std;

int arr[20];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		long long n;
		int s;
		scanf("%lld%d",&n,&s);
		int r;
		long long ni = n;
		int ttl = 0;
		for (int i = 0; i < 20; ++i) {
			arr[i] = ni%10;
			ni /= 10;
			ttl += arr[i];
			if (ni == 0) {
				r = i;
				arr[i+1] = 0;
				break;
			}
		}
		int idx = 0;
		for (;ttl > s;) {
			ttl += 10-arr[idx];
			arr[idx] = 10;
			for (;arr[idx] == 10;) {
				ttl -= 10;
				arr[idx] = 0;
				++idx;
				++ttl;
				++arr[idx];
			}
		}
		long long trgt = 0;
		for (int i = max(r,idx); i >= 0; --i) {
			trgt *= 10;
			trgt += arr[i];
		}
		printf("%lld\n",trgt-n);
	}
	return 0;
}