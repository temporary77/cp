#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

pair<int,int> arr[500001];
bool couldbeat[500001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		long long m;
		scanf("%d%lld",&n,&m);
		fill(couldbeat,couldbeat+n,false);
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i].f);
			arr[i].s = i;
		}
		sort(arr,arr+n);
		long long cur = 0;
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			cur += arr[i].f;
			if (cur > m) {
				cur -= arr[i].f;
				if (i > 0) {
					cur -= arr[i-1].f;
					for (int j = i; cur+arr[j].f <= m && j < n; ++j) {
						couldbeat[arr[j].s] = true;
					}
				}
				break;
			}
			couldbeat[arr[i].s] = true;
			++cnt;
		}
		int k;
		if (cnt == n) {
			k = 1;
		} else {
			k = n-cnt;
			if (!couldbeat[cnt]) {
				++k;
			}
		}
		printf("%d\n",k);
	}
	return 0;
}