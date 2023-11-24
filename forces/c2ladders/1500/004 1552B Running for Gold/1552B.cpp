#include <bits/stdc++.h>
using namespace std;

int arr[50001][5];

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < 5; ++j) {
				scanf("%d",&arr[i][j]);
			}
		}
		int ans = 1;
		for (int i = 2; i <= n; ++i) {
			int lead = 0;
			for (int j = 0; j < 5; ++j) {
				lead += arr[ans][j] < arr[i][j] ? 1 : 0;
			}
			if (lead < 3) {
				ans = i;
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (i == ans)continue;
			int lead = 0;
			for (int j = 0; j < 5; ++j) {
				lead += arr[ans][j] < arr[i][j] ? 1 : 0;
			}
			if (lead < 3) {
				ans = -1;
				break;
			}
		}
		printf("%d\n",ans);
	}	
	return 0;
}