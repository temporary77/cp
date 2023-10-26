#include <bits/stdc++.h>
using namespace std;

int arr[100001];
int cnt;
unordered_map<int,int> color;

int main() {
	int n, k;
	scanf("%d%d",&n,&k);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
	}
	int l = 0, r = 0;
	++color[arr[0]];
	long long ans = 1;
	cnt = 1;
	for (;;) {
			++r;
			if (r == n)break;
			if (color[arr[r]] == 0) {
				++cnt;
			}
			++color[arr[r]];
			if (cnt >= k) {
				for (;;) {
					--color[arr[l]];
					if (color[arr[l]] == 0) {
						--cnt;
					}
					++l;
					if (cnt < k) {
						break;
					}
				}
			}
			//printf("%d %d %d %d\n",l,r,r-l+1,cnt);
			ans += r-l+1;
	}
	long long ttl = (long long)n*(n+1)/2;
	printf("%lld",ttl-ans);
	return 0;
}