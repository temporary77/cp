#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, h, w;
	scanf("%d%d%d",&n,&h,&w);
	long long arri[n], arrj[n];
	for (int i = 0; i < n; ++i) {
		scanf("%lld",&arri[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%lld",&arrj[i]);
	}
	long long maxi = 0, maxj = 0;
	for (int i = 0; i < h; ++i) {
		maxi += arri[i];
	}
	for (int i = 0; i < w; ++i) {
		maxj += arrj[i];
	}
	long long sumi = maxi;
	long long sumj = maxj;
	for (int i = h; i < n; ++i) {
		sumi -= arri[i-h];
		sumi += arri[i];
		//printf("maxi %lld sumi %lld\n",maxi,sumi);
		maxi = max(maxi,sumi);
	}
	for (int i = w; i < n; ++i) {
		sumj -= arrj[i-w];
		sumj += arrj[i];
		maxj = max(maxj,sumj);
	}
	//printf("%lld %lld\n",maxi,maxj);
	printf("%lld",w*maxi+h*maxj);
	return 0;
}