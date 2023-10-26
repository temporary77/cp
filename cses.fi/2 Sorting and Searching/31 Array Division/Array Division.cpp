#include <bits/stdc++.h>
using namespace std;

long long arr[200002];
int n, k;

int main() {
	scanf("%d%d",&n,&k);
	long long l = LLONG_MIN;
	for (int i = 0; i < n; ++i) {
		scanf("%lld",&arr[i]);
		l = max(l,arr[i]);
	}
	long long r = l*n;
	//int i = 0;
	for (;l < r;) {
		//++i;
		//printf("%d %d %d\n",l,r,(l+r)/2);
		//if (i == 10)break;
		long long m = (l+r)/2;
		int cur = 0;
		long long cnt = 0;
		for (int i = 0; i < n; ++i) {
			cnt += arr[i];
			//printf("%d %d\n",i,cnt);
			if (cnt > m) {
				++cur;
				//printf("rA\n");
				cnt = arr[i];
			}
		}
		//printf("%d\n",cur);
		if (cnt <= m)++cur;
		//printf("%d\n",cur);
		if (cur > k) {
			l = m+1;
		} else {
			r = m;
		}
	}
	printf("%lld",l);
	return 0;
}