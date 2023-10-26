#include <bits/stdc++.h>
using namespace std;

int arr[1001];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n);
	printf("%d\n%d",arr[0],arr[n-1]);
	return 0;
}