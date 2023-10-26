#include <bits/stdc++.h>
using namespace std;

int arr[200001];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%*d%d",&arr[i]);
	}
	int max1 = INT_MIN;
	int cnt = 0;
	for (int i = n-1; i >= 0; --i) {
		if (arr[i] < max1) {
			++cnt;
		}
		max1 = max(max1,arr[i]);
	}
	printf("%d",cnt);

	return 0;
}