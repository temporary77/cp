#include <bits/stdc++.h>
using namespace std;

long long arr[100001], brr[100001];

int main() {
	int n;
	long long s;
	scanf("%d%lld",&n,&s);
	for (int i = 0; i < n; ++i) {
		scanf("%lld",&arr[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%lld",&brr[i]);
	}
	int a = 0;
	long long w = 0, p = 0;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		w += arr[i];
		p += brr[i];
		if (w > s) {
			for (;w > s;) {
				w -= arr[a];
				p -= brr[a];
				++a;
			}
		}
		ans = max(ans,p);
	}
	printf("%lld",ans);
	return 0;
}