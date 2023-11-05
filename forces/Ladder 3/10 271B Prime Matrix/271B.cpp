#include <bits/stdc++.h>
using namespace std;

bool sieve[100005];
int nxt[100005];
int colsum[501];

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	sieve[1] = 1;
	for (int i = 2; i*i <= 100003; ++i) {
		if (!sieve[i]) {
			for (int j = i*i; j <= 100003; j += i) {
				sieve[j] = 1;
			}
		}
	}
	int cur = 0;
	for (int i = 100003; i >= 1; --i) {
		if (!sieve[i]) {
			cur = 0;
		} else {
			++cur;
			nxt[i] = cur; 
		}
	}
	int k;
	int ans = INT_MAX;
	int rowsum;
	for (int i = 0; i < n; ++i) {
		rowsum = 0;
		for (int j = 0; j < m; ++j) {
			scanf("%d",&k);
			rowsum += nxt[k];
			colsum[j] += nxt[k];
			if (i == n-1)ans = min(ans,colsum[j]);
		}
		ans = min(ans,rowsum);
	}
	printf("%d",ans);
	return 0;
}