#include <bits/stdc++.h>
using namespace std;

queue<int> que;
int arr[20];
pair<int,int> dp[1050000];

int main() {
	int n, x;
	scanf("%d%d",&n,&x);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
	}
	dp[0] = {0,x};
	for (int i = 1; i < (1 << n); ++i) {
		dp[i] = {INT_MAX,-1};
		int last = -1;
		for (int j = 0; j < n; ++j) {
			if (i&(1 << j)) {
				last = j;
				pair<int,int> pr = dp[i^(1 << j)];
				if (x-pr.second < arr[j]) {
					++pr.first;
					pr.second = arr[j];
				} else {
					pr.second += arr[j];
				}
				dp[i] = min(dp[i],pr);
			}
		}
	}
	printf("%d",dp[(1 << n)-1]);
	return 0;
}