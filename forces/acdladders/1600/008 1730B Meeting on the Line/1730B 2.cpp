#include <bits/stdc++.h>
using namespace std;

int arr[200001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		int min1 = INT_MAX;
		int max1 = INT_MIN;
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i]);
		}
		for (int i = 0; i < n; ++i) {
			int t;
			scanf("%d",&t);
			min1 = min(min1,arr[i]-t);
			max1 = max(max1,arr[i]+t);
		}
		printf("%.20g\n",(max1+min1)/(double)2);
	}
	return 0;
}