#include <bits/stdc++.h>
using namespace std;

int arr[100001], brr[100001];
int qs1[100001], qs2[100001];
int a, b, k;

bool comp(int x, int y) {
	//printf("COMPARE %d %d\nACTUALLY %d %d\n",x,y,a*x+b,y);
	return x < y*a+b;
}

int main() {
	int n, m, q;
	scanf("%d%d%d",&n,&m,&q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&arr[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&qs1[i]);
		qs1[i] += qs1[i-1];
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d",&brr[i]);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d",&qs2[i]);
		qs2[i] += qs2[i-1];
	}
	for (int i = 0; i < q; ++i) {
		scanf("%d%d%d",&a,&b,&k);
		int l = min(arr[1],brr[1]*a+b), r = max(arr[n],brr[m]*a+b);
		int mid;
		for (;;) {
			mid = floor((double)(l+r)/2);
			if (l >= r) {
				break;
			}
			int idx1 = (upper_bound(arr+1,arr+n+1,mid)-1)-arr;
			int idx2 = (upper_bound(brr+1,brr+m+1,mid,comp)-1)-brr;
			//printf("%d %d %d\n",l,r,mid);
			//printf("%d %d %d %d\n",idx1,arr[idx1],idx2,brr[idx2]*a+b);
			if (qs1[idx1]+qs2[idx2] >= k) {
				r = mid;
			} else if (qs1[idx1]+qs2[idx2] < k) {
				l = mid+1;
			}
		}
		printf("%d\n",mid);
	}
	return 0;
}