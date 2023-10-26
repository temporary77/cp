#include <bits/stdc++.h>
using namespace std;

int arr[100005];

int main() {
	int n, s;
	scanf("%d%d",&n,&s);
	int sum = 0, idx = 0, min1 = INT_MAX;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
		sum += arr[i];
		if (sum >= s) {
			for (;sum-arr[idx] >= s;) {
				sum -= arr[idx];
				++idx;
			}
			min1 = min(min1,i-idx+1);
		}
	}
	if (min1 == INT_MAX)min1 = -1;
	printf("%d",min1);
	return 0;
}