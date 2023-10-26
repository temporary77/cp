#include <bits/stdc++.h>
using namespace std;

int arr[300001];

int main() {
	long long n, r;
	scanf("%lld%lld",&n,&r);
	int a = 0;
	long long cnt = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
		if (arr[i]-arr[a] > r) {
			for (;arr[i]-arr[a] > r;) {
				++a;
			}
		}
		cnt += i-a+1;
		//printf("%lld\n",cnt);
	}
	printf("%lld",n*(n+1)/2-cnt);
	return 0;
}