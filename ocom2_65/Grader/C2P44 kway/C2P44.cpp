#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	int arr[n+1];
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 2;
	for (int i = 4; i <= n; ++i) {
		arr[i] = arr[i-4]+arr[i-3]+arr[i-1];
	}
	printf("%d",arr[n]);
	return 0;
}