#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		int cur = 1;
		int a = 0, b = 0;
		for (;n > 0;) {
			a += (n%10)*cur;
			n /= 10;
			b += (n%10)*cur;
			n /= 10;
			cur *= 10;
		}
		long long nozeros;
		if (a >= 2 && b >= 2) {
			nozeros = (a-1)*(long long)(b-1);
		} else {
			nozeros = 0;
		}
		long long extra;
		if (a == 0 || b == 0) {
			if (a) {
				extra = a-1;
			} else if (b) {
				extra = b-1;
			}
		} else {
			extra = 2*(a+b-1);
		}
		printf("%lld\n",nozeros+extra);
	}
	return 0;
}