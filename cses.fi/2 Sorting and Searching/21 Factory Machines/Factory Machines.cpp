#include <bits/stdc++.h>
using namespace std;

int n, t;
int arr[200002];

int main() {
	scanf("%d%d",&n,&t);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
	}
	long long l = 0;
	long long r = 1e18;
	long long m;
	long long d;
	for (;;) {
		if (l >= r)break;
		m = (l+r)/2;
		//printf("%lld\n",m);
		d = 0;
		for (int i = 0; i < n; ++i) {
			d += min(m/arr[i],(long long)1e9);
			//printf(">%lld\n",d);
		}
		//printf("->%lld\n",d);
		if (d >= t) {
			r = m;
		} else {
			l = m+1;
		}
	}
	printf("%lld",l);
	return 0;
}