#include <bits/stdc++.h>
using namespace std;

int arr[100001];
int brr[1001];

int main() {
	int n, s;
	scanf("%d%d",&n,&s);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&arr[i]);
	}
	int ans = INT_MAX;
	brr[0] = -1;
	for (int r = 1; r <= n; ++r) {
		for (int j = s; j >= arr[r]; --j) {
			if(brr[j-arr[r]] == -1)brr[j] = r;
			else brr[j] = max(brr[j],brr[j-arr[r]]);
		}
		/*for (int i = 0; i <= s; ++i) {
			printf("%d ",brr[i]);
		}
		printf("\n");*/
		if(brr[s] != 0)ans = min(ans,r-brr[s]+1);
	}
	/*for (int i = 0; i <= s; ++i) {
		printf("%d ",brr[i]);
	}*/
	if (ans == INT_MAX) {
		printf("-1");
		return 0;
	}
	printf("%d",ans);
	return 0;
}