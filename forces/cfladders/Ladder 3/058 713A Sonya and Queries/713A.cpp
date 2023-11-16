#include <bits/stdc++.h>
using namespace std;

int arr[262150];

int main() {
	int t;
	scanf("%d",&t);
	for (int i = 0; i < t; ++i) {
		char c;
		long long x;
		scanf(" %c%lld",&c,&x);
		int res = 0;
		for (int j = 0; j < 18; ++j) {
			if (x&1) {
				res ^= (1 << j);
			}
			x /= 10;
			if (x <= 0)break;
		}
		if (c == '+') {
			++arr[res];
		} else if (c == '-') {
			--arr[res];
		} else if (c == '?') {
			printf("%d\n",arr[res]);
		}
	}
	return 0;
}