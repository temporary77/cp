#include <bits/stdc++.h>
using namespace std;

int arr[71];
unordered_map<double,int> mp;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i]);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = i+1; j < n; ++j) {
				double d = (arr[j]-arr[i])/(double)(j-i);
				double idx = arr[i]-(d*i);
				d = floor(d*1e6)/1e6;
				idx = floor(idx*1e6)/1e6;
				// printf("%lf <\n",abs(idx-0));
				// negative zero
				if (abs(d-0) <= 1e-6) {
					// printf("%lf <\n",idx);
					d = 0;
				}
				if (abs(idx-0) <= 1e-6) {
					// printf("%lf <\n",idx);
					idx = 0;
				}
				// printf("%d %d %d %d %lf %lf\n",i,j,arr[i],arr[j],d,idx);
				double key = d*1e12+idx;
				if (abs(key-0) <= 1e-6) {
					// printf("%lf <\n",idx);
					key = 0;
				}
				++mp[key];
				// if (mp[{d,idx}] >= 6)printf("[%d] %d %d %lf %lf\n",mp[{d,idx}],i,j,(double)d,(double)idx);
			}
		}
		double max1 = 0;
		for (auto it : mp) {
			max1 = max(max1,(double)it.second);
		}
		// printf(">%d<\n",max1);
		max1 = (1+sqrt(8*max1+1))/2;
		if (max1-floor(max1) > 0)printf(">>>%lf<<<\n",max1);
		printf("%d\n",n-(int)max1);
		mp.clear();
	}
	return 0;
}