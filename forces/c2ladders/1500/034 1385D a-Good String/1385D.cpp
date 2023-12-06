#include <bits/stdc++.h>
using namespace std;

int arr[200002];

int main() {
	cin.tie(NULL);
	int t;
	scanf("%d",&t);
	string str;
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		char cmax = 'a'+log2(n);
		cin >> str;
		fill(arr,arr+n,0);
		for (int i = 0; i < n; ++i) {
			if (str[i] > cmax)continue;
			else if (str[i] == cmax) {
				++arr[i];
				--arr[i+1];
				continue;
			}
			int l = 0;
			int r = n;
			for (char c = str[i]; c > 'a'; --c) {
				if (i < (l+r)/2) {
					r = (l+r)/2;
				} else {
					l = (l+r)/2;
				}
			}
			// printf("%c %d %d\n",str[i],l,r);
			if (i < (l+r)/2) {
				++arr[(l+r)/2];
				--arr[r];
			} else {
				++arr[l];
				--arr[(l+r)/2];
			}
		}
		int max1 = arr[0];
		// printf("%d ",max1);
		for (int i = 1; i < n; ++i) {
			arr[i] += arr[i-1];
			// printf("%d ",arr[i]);
			max1 = max(max1,arr[i]);
		}
		// printf("\n");
		printf("%d\n",n-max1);
	}
	return 0;
}