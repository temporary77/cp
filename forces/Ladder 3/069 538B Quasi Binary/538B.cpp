#include <bits/stdc++.h>
using namespace std;

int cnt[7];

int main() {
	int n;
	scanf("%d",&n);
	int k = 0;
	for (int i = 0; i < 7; ++i) {
		if (n == 0)break;
		cnt[i] = n%10;
		k = max(k,cnt[i]);
		n /= 10;
	}
	printf("%d\n",k);
	for (int i = 1; i <= k; ++i) {
		int x = 0;
		int d = 1;
		for (int j = 0; j < 7; ++j) {
			if (cnt[j] >= i)x += d;
			d *= 10;
		}
		printf("%d ",x);
	}
	return 0;
}