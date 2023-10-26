#include <bits/stdc++.h>
using namespace std;

int arr[31][31];
int min1[31];
int max1[31];
int diff[31];

int main() {
	int n, b;
	scanf("%d%d",&n,&b);
	int ans = INT_MIN;
	for (int i = 0; i < n; ++i) {
		min1[i] = INT_MAX;
		max1[i] = INT_MIN;
		for (int j = 0; j < n; ++j) {
			scanf("%d",&arr[i][j]);
			min1[i] = min(min1[i],arr[i][j]);
			max1[i] = max(max1[i],arr[i][j]);
		}
		ans = max(ans,max1[i]-min1[i]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (j == i)continue;
			ans = max(ans,max1[i]-min1[j]+2*b);
		}
	}
	printf("%d",ans);
}