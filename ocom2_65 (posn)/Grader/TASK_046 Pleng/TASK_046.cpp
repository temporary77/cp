#include <bits/stdc++.h>
using namespace std;

int x[100005], y[100005];

int main() {
	int n;
	scanf("%d",&n);
	int k;
	long long sumx = 0, sumy = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		x[i] = k;
		sumx += k;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		y[i] = k;
		sumy += k;
	}
	long long qsx[n];
	long long qsy[n];
	for (int i = 0; i < n; ++i) {
		sumx -= x[i];
		sumy -= y[i];	
		qsx[i] = sumx;
		qsy[i] = sumy;
	}
	long long cnt = 0;
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += (long long)x[i]%2560*y[i]%2560*(n-1)%2560;
		sum -= (long long)x[i]%2560*(qsy[i])%2560;
		sum -= (long long)y[i]%2560*(qsx[i])%2560;
		cnt += i;
	}
	sum %= 2560;
	if (sum < 0)sum += 2560;
	printf("%lld\n%lld",cnt%2560,sum);
	return 0;
}