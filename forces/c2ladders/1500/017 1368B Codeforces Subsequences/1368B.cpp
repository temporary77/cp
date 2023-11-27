#include <bits/stdc++.h>
using namespace std;

string str = "codeforces";
int ans[10];

int main() {
	long long k;
	scanf("%lld",&k);
	long long cnt = 1;
	int cur = 2;
	for (;;) {
		for (int i = 0; i < 10; ++i) {
			if (cnt >= k)goto g;
			// printf("%lld %d\n",cnt,cur);
			cnt *= cur;
			cnt /= cur-1;
			++ans[i];
		}
		++cur;
	}
	g:;
	for (int i = 0; i < 10; ++i) {
		for (int j = -1; j < ans[i]; ++j) {
			printf("%c",str[i]);
		}
	}
	return 0;
}