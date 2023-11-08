#include <bits/stdc++.h>
using namespace std;

int arr[20001];
int ans = INT_MIN;

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
	}
	for (int i = n/3; i >= 1; --i) {
		if (n%i)continue;
		for (int j = 0; j < i; ++j) {
			int cur = 0;
			for (int k = j; k < n; k += i) {
				cur += arr[k];
			}
			ans = max(ans,cur);
		}
	}
	printf("%d",ans);
	return 0;
}