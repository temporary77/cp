#include <bits/stdc++.h>
using namespace std;

int arr[101];

int main() {
	int n;
	scanf("%d",&n);
	int k;
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&k);
		arr[k] = i;
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ",arr[i]);
	}
	return 0;
}