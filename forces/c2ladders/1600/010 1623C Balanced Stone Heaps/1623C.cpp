#include <bits/stdc++.h>
using namespace std;

int arr[200001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		long long sum = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i]);
			sum += arr[i];
		}
		int l = 0, r = sum/n;
		for (;;) {
			if (l >= r)break;
			int m = (l+r+1)/2;
			bool check = true;
			int quota[3] = {0,0,0};
			for (int i = n-1; i >= 2; --i) {
				quota[2] = quota[1];
				quota[1] = quota[0];
				quota[0] = 0;
				if (arr[i]+quota[2] < m) {
					check = false;
					break;
				}
				int give = min(arr[i],arr[i]+quota[2]-m)/3;
				quota[0] += 2*give;
				quota[1] += give;
				// printf("%d %d %d %d\n",m,quota[0],quota[1],quota[2]);
			}
			if (arr[0]+quota[0] < m || arr[1]+quota[1] < m)check = false;
			if (check) {
				l = m;
			} else {
				r = m-1;
			}
		}
		printf("%d\n",l);
	}
	return 0;
}