#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	int arr[n+1];
	int k;
	arr[0] = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&k);
		if (i == 1) {
			arr[1] = k;
			continue;
		}
		arr[i] = max(k+arr[i-2],arr[i-1]);
	}
	printf("%d",arr[n]);
	return 0;
}