#include <bits/stdc++.h>
using namespace std;

int arr[100001];
int brr[100001];

int main() {
	int n, k;
	scanf("%d%d",&n,&k);
	long long suma = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
		suma += arr[i];
	}
	long long sumb = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&brr[i]);
		sumb += brr[i];
	}
	int l = 0;
	int r = (sumb+k)/suma;
	for (;;) {
		if (l >= r)break;
		int m = ((long long)l+r+1)/2;
		int curk = k;
		int need;
		bool check = 1;
		for (int i = 0; i < n; ++i) {
			need = arr[i]*m-brr[i];
			if (need > 0) {
				curk -= need;
				if (curk < 0) {
					check = 0;
					break;
				}
			}
		}
		if (check) {
			l = m;
		} else {
			r = m-1;
		}
	}
	printf("%d",l);
	return 0;
}