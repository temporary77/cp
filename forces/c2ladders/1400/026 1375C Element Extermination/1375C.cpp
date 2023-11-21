#include <bits/stdc++.h>
using namespace std;

int arr[300001];
int pos[300001];
int pos2[300001];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i]);
			pos[arr[i]] = i;
		}
		int l = 0, r = n-1;
		for (int i = 1; i < n; ++i) {
			if (arr[i-1] > arr[i]) {
				break;
			}
			l = i;
		}
		for (int i = n-2; i >= 0; --i) {
			if (arr[i] > arr[i+1]) {
				break;
			}
			r = i;
		}
		bool check = false;
		pos2[n] = 0;
		for (int i = n-1; i >= 1; --i) {
			pos2[i] = max(pos[i+1],pos2[i+1]);
			if (pos[i] <= l && r <= pos2[i]) {
				check = true;
				break;
			}
		}
		if (check) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}